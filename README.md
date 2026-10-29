# QMK Userspace - lorentzfb

## Setup

https://docs.qmk.fm/newbs_getting_started

https://docs.qmk.fm/newbs_external_userspace

```sh
cd $HOME
git clone https://github.com/{myusername}/qmk_userspace.git
```

```sh
qmk config user.overlay_dir="$(realpath qmk_userspace)"
```

### Setting default keyboard and keymap

```sh
qmk config user.keyboard=crkbd/rev1
```

```sh
qmk config user.keymap=lorentzfb
```

## Compile

Build the Corne (crkbd rev1 with a Sea-Picro, so the output is a `.uf2`):

```sh
qmk compile -kb crkbd/rev1 -km lorentzfb
```

If the default keyboard and keymap are set (see above), `qmk compile` is enough.
To build every target listed in `qmk.json`:

```sh
qmk userspace-compile
```

The firmware ends up as `crkbd_rev1_lorentzfb.uf2` in the root of this repo.

### Editor support (clangd)

Without a compilation database, clangd can't find the QMK headers and reports errors like `'quantum.h' file not found` or `Expected "FILENAME" or <FILENAME>` (from `#include QMK_KEYBOARD_H`). Add `--compiledb` to generate one:

```sh
qmk compile -kb crkbd/rev1 -km lorentzfb --compiledb
```

This builds the firmware and writes `compile_commands.json` to the root of this repo (it's gitignored). Restart the language server afterwards.

There's no need to use `--compiledb` on every build: it forces a full rebuild, and the database only records include paths, defines and compiler flags, so editing keymaps or code doesn't make it stale. Re-run it when you:

- enable or disable a feature in `rules.mk` (e.g. `COMBO_ENABLE`)
- add a new `.c` file or keymap
- switch keyboards (the database only covers the last keyboard it was generated for)
- update `qmk_firmware`

If clangd starts reporting missing headers or undeclared identifiers again, the database is probably stale.

## Flash

Flash each half separately:

1. Plug in one half over USB.
2. Double-tap the reset button. The controller mounts as a USB drive named `RPI-RP2`.
3. Copy `crkbd_rev1_lorentzfb.uf2` to the drive. The half reboots once the copy finishes.
4. Repeat for the other half.

Alternatively, run `qmk flash -kb crkbd/rev1 -km lorentzfb` and put the half into bootloader mode when prompted.
