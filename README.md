# Forsaken

This repo holds the community port of Forsaken!

Check out the [Wiki](https://github.com/ForsakenX/forsaken/wiki) for more information.

## Building on Arch Linux (docker)

Use an Arch container to keep dependencies isolated. With these changes, a clean build should work when the SDL/Lua 5.1/OpenAL/ENet toolchain is available. Follow the `forsaken-libs` README recommendation to build dependencies locally and point pkg-config at them:

```bash
docker run --rm -v "$(pwd)":/work -w /work archlinux:latest bash -lc "\
  pacman -Syu --noconfirm base-devel git lua51 lua51-socket pkgconf cmake && \
  git clone https://github.com/ForsakenX/forsaken-libs.git libs && \
  cd libs/src && ./build.sh && cd /work && \
  export PKG_CONFIG_PATH=/work/libs/lib/pkgconfig:\$PKG_CONFIG_PATH && \
  make LUA=lua5.1"
```

The Makefile now auto-detects the `libenet` vs `enet` pkg-config name (Arch uses `enet`). Override `LUA` if your system exposes a different pkg-config name. See the Wiki for additional troubleshooting tips.
