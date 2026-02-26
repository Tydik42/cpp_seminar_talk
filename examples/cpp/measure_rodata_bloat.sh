#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
SRC="${ROOT_DIR}/examples/cpp/src/rodata_bloat_demo.cpp"
BUILD_DIR="${ROOT_DIR}/examples/cpp/build"
MACRO_BIN="${BUILD_DIR}/rodata_macro"
SOURCE_LOC_BIN="${BUILD_DIR}/rodata_source_location"

mkdir -p "${BUILD_DIR}"

echo "[rodata] build macro-heavy variant"
g++ -std=c++20 -O2 "${SRC}" -o "${MACRO_BIN}"

echo "[rodata] build source_location variant"
g++ -std=c++20 -O2 -DUSE_SOURCE_LOCATION "${SRC}" -o "${SOURCE_LOC_BIN}"

echo
echo "[rodata] section sizes (.rodata):"
size -A "${MACRO_BIN}" "${SOURCE_LOC_BIN}" | sed -n '1,120p'

echo
echo "[rodata] hint: compare .rodata rows above."
