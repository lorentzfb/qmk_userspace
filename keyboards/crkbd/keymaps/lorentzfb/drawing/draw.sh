#!/bin/bash

# https://keymap-drawer.streamlit.app

DIST_APP_SVG="/Users/lorentz/projects/personal/kbd/src/lib/assets/crkbd_rev1_lorentzfb_app.svg"

DIST="dist"
# keymap draw -o $OUT config.yaml
#
LAYER_NAMES='Default Norwegian Number Symbol Navigation Function Media Adjust'
CONFIG_DRAW="config_draw.yaml"
CONFIG_PARSE="config_parse.yaml"
CONFIG_OUT="${DIST}/config.yaml"
KEYMAP_JSON="${DIST}/keymap.json"
KEYMAP_SVG="${DIST}/keymap.svg"

# Delete old build
[[ -d "$DIST" ]] && rm -rf "${DIST}"/* || mkdir -p "$DIST"

# Parse keymap.c to keymap.json
qmk c2json --no-cpp -o "${KEYMAP_JSON}"

# Parse keymap.json to keymap.yaml
keymap -c "${CONFIG_PARSE}" parse -q "${KEYMAP_JSON}" -o "${CONFIG_OUT}" --layer-names $LAYER_NAMES

# Replace layout name
sed -i '' 's/layout_name: LAYOUT_wrapper/layout_name: LAYOUT_split_3x6_3/' "${CONFIG_OUT}"

# Append draw_config and combos to yaml config
cat "${CONFIG_DRAW}" >> "${CONFIG_OUT}"

# Apply ovverides to config

# Create keymap SVG
keymap draw -o "${KEYMAP_SVG}" "${CONFIG_OUT}"

# Copy SVG to app dir
cp "${KEYMAP_SVG}" "${DIST_APP_SVG}"
