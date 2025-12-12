# Forsaken

This repo holds the community port of Forsaken!

Check out the [Wiki](https://github.com/ForsakenX/forsaken/wiki) for more information.

## Building on Arch Linux (docker)

Use an Arch container to keep dependencies isolated. With these changes, a clean build should work when the SDL/Lua 5.1/OpenAL/ENet toolchain is available. Follow the `forsaken-libs` README recommendation to build dependencies locally and point pkg-config at them:

```bash
docker run --rm -v "$(pwd)":/work -w /work archlinux:latest bash -lc "./build-arch.sh"
```

The Makefile now auto-detects the `libenet` vs `enet` pkg-config name (Arch uses `enet`). Override `LUA` if your system exposes a different pkg-config name. See the Wiki for additional troubleshooting tips.
