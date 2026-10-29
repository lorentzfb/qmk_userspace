#!/bin/bash
# https://keymap-drawer.streamlit.app

[[ -n "$1" ]] && KEYMAP_DEV_OUT="$(realpath -m "$1")"

# Run from the script's directory so relative config paths resolve
cd "$(dirname "$(realpath "$0")")"

DIST="dist"
CONFIG_PARSE="config_parse.yaml"
CONFIG_KM="config_km.yaml"
CONFIG_DRAW="config_draw.yaml"
CONFIG_OUT="${DIST}/config.yaml"
KEYMAP_JSON="${DIST}/keymap.json"
KEYMAP_SVG="${DIST}/keymap.svg"
KEYMAP_SVG_UNSTYLED="${DIST}/keymap_unstyled.svg"
LATEST="latest"
LATEST_SVG="${LATEST}/crkbd_rev1_lorentzfb.svg"
LATEST_SVG_UNSTYLED="${LATEST}/crkbd_rev1_lorentzfb_unstyled.svg"
LATEST_JSON="${LATEST}/crkbd_rev1_lorentzfb.json"

# Exit on any error
set -e

# Delete old build
[[ -d "$DIST" ]] && rm -rf "${DIST}"/* || mkdir -p "$DIST"

# Parse keymap.c to keymap.json
qmk c2json --no-cpp -o "${KEYMAP_JSON}"

# Parse keymap.json to keymap.yaml
keymap --config "${CONFIG_PARSE}" parse --qmk-keymap-json "${KEYMAP_JSON}" --output "${CONFIG_OUT}"

# Apply keymap overrides
deno run --allow-read --allow-write keymap_overrides.ts "${CONFIG_KM}" "${CONFIG_OUT}"

# Append draw_config and combos to yaml config
cat "${CONFIG_DRAW}" >> "${CONFIG_OUT}"

# Create keymap SVG
keymap draw --output "${KEYMAP_SVG}" "${CONFIG_OUT}"

# Create keymap SVG with no styles
CONFIG=$(cat "${CONFIG_OUT}")
CONFIG+=$'
  svg_style: |
    /* I will handle it... */
'
echo "${CONFIG}" | keymap draw -o "${KEYMAP_SVG_UNSTYLED}" -

# Copy SVGs and keymap JSON to latest dir
mkdir -p "${LATEST}"
cp "${KEYMAP_SVG}" "${LATEST_SVG}"
cp "${KEYMAP_SVG_UNSTYLED}" "${LATEST_SVG_UNSTYLED}"
cp "${KEYMAP_JSON}" "${LATEST_JSON}"
echo "Wrote keymaps to ${LATEST}"

# Copy dev SVG to dev app dir
[[ -n "$KEYMAP_DEV_OUT" ]] || exit 0
cp "${KEYMAP_SVG_UNSTYLED}" "${KEYMAP_DEV_OUT}"
echo "Wrote dev keymap to ${KEYMAP_DEV_OUT}"
