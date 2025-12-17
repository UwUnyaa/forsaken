# Forsaken

This repo holds the community port of Forsaken!

Check out the [Wiki](https://github.com/ForsakenX/forsaken/wiki) for more information.

## Building on Arch Linux (docker)

Use an Arch container to keep dependencies isolated. With these changes, a clean build should work when the SDL/Lua 5.1/OpenAL/ENet toolchain is available. Follow the `forsaken-libs` README recommendation to build dependencies locally and point pkg-config at them:

```bash
docker run --rm -v "$(pwd)":/work -w /work archlinux:latest bash -lc "./build-arch.sh"
```

The Makefile now auto-detects the `libenet` vs `enet` pkg-config name (Arch uses `enet`). Override `LUA` if your system exposes a different pkg-config name. See the Wiki for additional troubleshooting tips.

When working with arch, following dependencies are required to get this project up and running:

- `base-devel`
- `git`
- `lua51`
- `lua51-socket`
- `pkgconf`
- `cmake`
- `mesa`
- `glu`

To run this project after building, set up the `LD_LIBRARY_PATH` like in the following example:

```bash
LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$(pwd)/libs/lib" ./projectx
```

## Renderer selection

The Makefile exposes multiple render backends through the `GL` parameter. Besides the numeric targets (`GL=1`, `GL=2`, `GL=3`), you can now select the symbolic `GLES3` renderer. At the moment `GL=GLES3` builds the same code as the GL3 backend but establishes a dedicated compilation path so it can evolve separately. Because it is a GL3-class renderer it still requires SDL2:

```bash
make SDL=2 GL=GLES3
```
