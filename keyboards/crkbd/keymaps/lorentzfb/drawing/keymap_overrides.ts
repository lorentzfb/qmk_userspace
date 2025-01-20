import { z } from "https://deno.land/x/zod@v3.24.1/mod.ts";
import { parse, stringify } from "jsr:@std/yaml";

const keyOverrideSchema = z.object({
    key: z.number(),
    type: z.enum(["held"]),
});

type KeyOverride = z.infer<typeof keyOverrideSchema>;

const ovSchema = z.object({});

type OverridesYaml = {
    layout: {
        layout_name: string;
    };
    layers: {
        [key: string]: KeyOverride;
    };
};

const args = Deno.args;

if (args.length != 2) {
    console.error("Please provide the required arguments.");
    Deno.exit(1);
}
const overridesYaml = args[0];
const configYaml = args[1];

let ov: OverridesYaml;

try {
    const fileContent = await Deno.readTextFile(overridesYaml);
    ov = parse(fileContent);
} catch (e) {
    console.error(e);
    Deno.exit(1);
}

console.log(JSON.stringify(ov));

// try {
//     // Read the JSON file
//     const fileContent = await Deno.readTextFile(keymapPath);
//     const data = JSON.parse(fileContent);

//     // Access and modify the desired element
//     data.layers[1][4] = "NEW_VALUE"; // Change string number 5 (index 4) in array 2 (index 1)

//     // Save the updated JSON back to the file
//     const updatedContent = JSON.stringify(data, null, 4);
//     await Deno.writeTextFile(keymapPath, updatedContent);

//     console.log("String updated successfully!");
// } catch (error) {
//     console.error("Error:", error.message);
// }
