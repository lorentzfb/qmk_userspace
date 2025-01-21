#!/bin/bash

# https://keymap-drawer.streamlit.app

DIST_APP_SVG="/Users/lorentz/projects/personal/kbd/src/lib/assets/crkbd_rev1_lorentzfb_app.svg"

DIST="dist"
CONFIG_PARSE="config_parse.yaml"
CONFIG_KM="config_km.yaml"
CONFIG_DRAW="config_draw.yaml"
CONFIG_OUT="${DIST}/config.yaml"
KEYMAP_JSON="${DIST}/keymap.json"
KEYMAP_SVG="${DIST}/keymap.svg"

# Delete old build
[[ -d "$DIST" ]] && rm -rf "${DIST}"/* || mkdir -p "$DIST"

# Parse keymap.c to keymap.json
qmk c2json --no-cpp -o "${KEYMAP_JSON}"

# Parse keymap.json to keymap.yaml
keymap -c "${CONFIG_PARSE}" parse -q "${KEYMAP_JSON}" -o "${CONFIG_OUT}"

# Apply keymap overrides
deno run --allow-read --allow-write keymap_overrides.ts "${CONFIG_KM}" "${CONFIG_OUT}"

# Append draw_config and combos to yaml config
cat "${CONFIG_DRAW}" >> "${CONFIG_OUT}"

# Create keymap SVG
keymap draw -o "${KEYMAP_SVG}" "${CONFIG_OUT}"

# Copy SVG to app dir
cp "${KEYMAP_SVG}" "${DIST_APP_SVG}"
