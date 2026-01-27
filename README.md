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
