#!/usr/bin/env bash
set -euo pipefail

# Usage: run inside Arch container from repo root, e.g.:
# docker run --rm -v "$(pwd)":/work -w /work archlinux:latest bash -lc "./build-arch.sh"

ROOT="$(pwd)"

pacman -Syu --noconfirm base-devel git lua51 lua51-socket pkgconf cmake mesa glu

if [[ ! -d "${ROOT}/libs" ]]; then
  git clone https://github.com/ForsakenX/forsaken-libs.git "${ROOT}/libs"
fi

cd "${ROOT}/libs/src"
# First pass fetch/unpack sources; ignore failure so patches can apply.
./build.sh || true

# Patch OpenAL for newer CMake.
sed -i 's/cmake_minimum_required(VERSION 2\.8/cmake_minimum_required(VERSION 3.5/' openal-soft-1.14/CMakeLists.txt
sed -i 's@cmake -DEXAMPLES=OFF -DCMAKE_INSTALL_PREFIX= ../@cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DEXAMPLES=OFF -DCMAKE_INSTALL_PREFIX= ../@' build.sh
(
  cd openal-soft-1.14
  mkdir -p build
  cd build
  cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DEXAMPLES=OFF -DCMAKE_INSTALL_PREFIX= ../ || true
)

# Rebuild dependencies.
./build.sh

cd "${ROOT}"
export PKG_CONFIG_PATH="${ROOT}/libs/lib/pkgconfig:${PKG_CONFIG_PATH:-}"
make LUA=lua5.1
