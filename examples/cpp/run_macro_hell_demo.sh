#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
SRC="${ROOT_DIR}/examples/cpp/src/macro_hell_demo.cpp"
OUT="${ROOT_DIR}/examples/cpp/build/macro_hell_demo.o"

mkdir -p "$(dirname "${OUT}")"

echo "[macro-hell] compiling ${SRC}"
if g++ -std=c++20 -c "${SRC}" -o "${OUT}" >"${OUT}.log" 2>&1; then
    echo "[macro-hell] unexpected: compilation succeeded"
    exit 1
fi

echo "[macro-hell] expected failure; excerpt:"
sed -n '1,160p' "${OUT}.log"
