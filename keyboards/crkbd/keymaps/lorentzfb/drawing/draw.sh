#!/bin/bash
# https://keymap-drawer.streamlit.app

[[ -n "$1" ]] && KEYMAP_DEV_OUT="$1"

DIST="dist"
CONFIG_PARSE="config_parse.yaml"
CONFIG_KM="config_km.yaml"
CONFIG_DRAW="config_draw.yaml"
CONFIG_OUT="${DIST}/config.yaml"
KEYMAP_JSON="${DIST}/keymap.json"
KEYMAP_SVG="${DIST}/keymap.svg"
KEYMAP_SVG_UNSTYLED="${DIST}/keymap_unstyled.svg"

# Exit on any error
set -e

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

# Create keymap SVG with no styles
CONFIG=$(cat "${CONFIG_OUT}")
CONFIG+=$'
  svg_style: |
    /* I will handle it... */
'
echo "${CONFIG}" | keymap draw -o "${KEYMAP_SVG_UNSTYLED}" -

# Copy dev SVG to dev app dir
[[ -n "$KEYMAP_DEV_OUT" ]] || exit 0
cp "${KEYMAP_SVG_UNSTYLED}" "${KEYMAP_DEV_OUT}"
echo "Wrote dev keymap to ${KEYMAP_DEV_OUT}"
