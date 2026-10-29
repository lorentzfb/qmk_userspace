# Keymap drawing

`draw.sh` generates SVG images of the Corne keymap into `dist/`:

- `dist/keymap.svg` – styled keymap
- `dist/keymap_unstyled.svg` – same keymap without the built-in styles

## Dependencies

`draw.sh` relies on [keymap-drawer](https://github.com/caksoylar/keymap-drawer),
a Python tool that provides the `keymap` command used to parse the QMK keymap
(`keymap parse`) and render the SVGs (`keymap draw`).

keymap-drawer is installed on the system with [pipx](https://pipx.pypa.io),
and pipx itself is installed with [mise](https://mise.jdx.dev):

```sh
mise use -g pipx
pipx install keymap-drawer
```

The script also uses:

- `qmk` – `qmk c2json` converts `keymap.c` to JSON
- `deno` – runs `keymap_overrides.ts` to apply the overrides in `config_km.yaml`

## Usage

Run from this directory:

```sh
./draw.sh [dev-output-path]
```

If `dev-output-path` is given, the unstyled SVG is also copied there.
