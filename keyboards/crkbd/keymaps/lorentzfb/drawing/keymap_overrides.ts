import { z } from "https://deno.land/x/zod@v3.24.1/mod.ts";
import * as yaml from "npm:js-yaml";

const keyOverrideSchema = z.object({
    key: z.number(),
    type: z.enum(["held", "trans", "dead"]).optional(),
    t: z.string().optional(),
    h: z.string().optional(),
    s: z.string().optional(),
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
    z.object({
        t: z.string().optional(),
        h: z.string().optional(),
        s: z.string().optional(),
        type: z.string().optional(),
    }),
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

// Check args

const args = Deno.args;

if (args.length != 2) {
    console.error("Please provide the required arguments.");
    Deno.exit(1);
}

// Yaml paths

const overridesYaml = args[0];
const configYaml = args[1];

// Read and parse the config_km.yaml

let ov: Overrides;

try {
    const fileContent = await Deno.readTextFile(overridesYaml);
    const parsedYaml = yaml.load(fileContent);
    ov = overridesSchema.parse(parsedYaml);
} catch (e) {
    console.error(e);
    console.error(`Error: failed to parse ${overridesYaml}`);
    Deno.exit(1);
}

// Read and parse the config.yaml

let config: Config;

try {
    const fileContent = await Deno.readTextFile(configYaml);
    const parsedYaml = yaml.load(fileContent);
    // console.log(parsedYaml);
    config = configSchema.parse(parsedYaml);
} catch (e) {
    console.error(e);
    console.error(`Error: failed to parse ${configYaml}`);
    Deno.exit(1);
}

// Update 'layout' if any ovverides has been set
if (ov.layout) {
    config.layout = {
        ...config.layout,
        ...(ov.layout.qmk_keyboard && { qmk_keyboard: ov.layout.qmk_keyboard }),
        ...(ov.layout.layout_name && { layout_name: ov.layout.layout_name }),
    };
}

// Get layer names from ovverrides
const layerNames = Object.keys(ov.layers);

if (layerNames.length != Object.keys(config.layers).length) {
    console.error(
        `Error: number of layers in ${configYaml} and ${overridesYaml} is not equal`,
    );
    Deno.exit(1);
}

// Update layer names in config
Object.entries(config.layers).forEach((k, i) => {
    k[0] = layerNames[i];
});

// Apply key ovverides in each layer
const layerKeys = Object.values(ov.layers);

const transformedLayers = Object.entries(config.layers).reduce<
    typeof config.layers
>(
    (acc, [_key, value], i) => {
        layerKeys[i].forEach((k) => {
            const a = { ...k };
            Reflect.deleteProperty(a, "key");
            value[k.key] = a;
        });

        acc[layerNames[i]] = value;
        return acc;
    },
    {},
);

config.layers = transformedLayers;

// Write the transformed config.yaml

const convertedConfig = yaml.dump(config);

try {
    await Deno.writeTextFile(configYaml, convertedConfig);
} catch (e) {
    console.error(e);
    console.error(`Error: failed to parse ${configYaml}`);
    Deno.exit(1);
}
