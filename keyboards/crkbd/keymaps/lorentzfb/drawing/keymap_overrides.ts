import { ZodSchema } from "https://deno.land/x/zod@v3.24.1/mod.ts";
import { z } from "https://deno.land/x/zod@v3.24.1/mod.ts";
import * as yaml from "npm:js-yaml";

const keySchema = z.object({
    type: z.string().optional(),
    t: z.string().optional(),
    h: z.string().optional(),
    s: z.string().optional(),
});

type KeyOptions = z.infer<typeof keySchema>;

const keyOverrideSchema = z.object({
    key: z.number(),
    options: keySchema,
});

type KeyOverride = z.infer<typeof keyOverrideSchema>;

const overridesSchema = z.object({
    layout: z.object({
        qmk_keyboard: z.string().optional(),
        layout_name: z.string().optional(),
    }).optional(),
    layers: z.record(z.array(keyOverrideSchema)),
});

type Overrides = z.infer<typeof overridesSchema>;

const configLayerKeySchema = z.union([
    z.string(),
    keySchema,
]);

type ConfigLayerKey = z.infer<typeof configLayerKeySchema>;

const configSchema = z.object({
    layout: z.object({
        layout_name: z.string(),
        qmk_keyboard: z.string(),
    }),
    layers: z.record(z.array(configLayerKeySchema)),
});

type Config = z.infer<typeof configSchema>;

async function loadYaml<T>(schema: ZodSchema<T>, filePath: string): Promise<T> {
    let result: T;
    try {
        const fileContent = await Deno.readTextFile(filePath);
        const parsedYaml = yaml.load(fileContent);
        result = schema.parse(parsedYaml);
    } catch (e) {
        console.error(e);
        console.error(`\nError: failed to load ${filePath}`);
        Deno.exit(1);
    }
    return result;
}

// Check args

const args = Deno.args;

if (args.length != 2) {
    console.error("Please provide the required arguments.");
    Deno.exit(1);
}

// Yaml paths

const overridesPath = args[0];
const configPath = args[1];

// Read and parse the config_km.yaml
const ovr: Overrides = await loadYaml(overridesSchema, overridesPath);

// Read and parse the config.yaml
const config: Config = await loadYaml(configSchema, configPath);

// Update 'layout' if any ovverides has been set
if (ovr.layout) {
    config.layout = {
        ...config.layout,
        ...(ovr.layout.qmk_keyboard &&
            { qmk_keyboard: ovr.layout.qmk_keyboard }),
        ...(ovr.layout.layout_name && { layout_name: ovr.layout.layout_name }),
    };
}

// Get layer names from overrides
const layerNames = Object.keys(ovr.layers);

if (layerNames.length != Object.keys(config.layers).length) {
    console.error(
        `Error: number of layers in ${configPath} and ${overridesPath} is not equal`,
    );
    Deno.exit(1);
}

// Update layer names in config
Object.entries(config.layers).forEach((k, i) => {
    k[0] = layerNames[i];
});

// Apply key ovverides in each layer
const layerKeys = Object.values(ovr.layers);

config.layers = Object.entries(config.layers).reduce<
    typeof config.layers
>(
    (acc, [_key, layer], i) => {
        layerKeys[i].forEach((ov) => {
            let modifiedKey: KeyOptions = {};
            const current = layer[ov.key];

            if (typeof current === "string") {
                modifiedKey.t = current;
            } else if (typeof current === "object") {
                modifiedKey = { ...current };
            }

            layer[ov.key] = { ...modifiedKey, ...ov.options };
        });

        acc[layerNames[i]] = layer;
        return acc;
    },
    {},
);

// Write the transformed config.yaml
const convertedConfig = yaml.dump(config);

try {
    await Deno.writeTextFile(configPath, convertedConfig);
} catch (e) {
    console.error(e);
    console.error(`\nError: failed to write ${configPath}`);
    Deno.exit(1);
}
