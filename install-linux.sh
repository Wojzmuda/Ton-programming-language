#!/bin/bash

# stops the script after any error - sure ??
set -e

# --- variables ---
DATA_DIR="data"
SF2_FILENAME="FluidR3_GM.sf2"
DOWNLOAD_URL="https://github.com/pianobooster/fluid-soundfont/releases/download/v3.1/FluidR3_GM.sf2"
USER_TON_DIR="$HOME/.ton"
BIN_DIR="$HOME/.local/bin"

echo ">>> [Tøn Setup] Sarting the instalation..."
echo "======================================================"

# 1. Safeguard - are you in project root ?
if [ ! -f "Ton.g4" ]; then
    echo ">>> [ERROR] Script must be run from Root Project directory!"
    exit 1
fi

echo ">>> [1/6] SoundFont library setup"
mkdir -p "$DATA_DIR"

if [ -f "$DATA_DIR/$SF2_FILENAME" ]; then
    echo ">>> [INFO] File $SF2_FILENAME already exists. Skipping download."
else
    echo ">>> [INFO] Downloading the SoundFont library (~142 MB)..."
    wget -q --show-progress -O "$DATA_DIR/$SF2_FILENAME" "$DOWNLOAD_URL"
fi

echo ">>> [2/6] Installing SoundFont library globally in $USER_TON_DIR."
mkdir -p "$USER_TON_DIR"
cp "$DATA_DIR/$SF2_FILENAME" "$USER_TON_DIR/$SF2_FILENAME"

echo ">>> [3/6] Generating Parser and Lexer."
antlr4 -Dlanguage=Cpp -visitor -listener -o antlr4_generated Ton.g4

echo ">>> [4/6] Configuring CMake environment."
cmake -B build

echo ">>> [5/6] Building Tøn..."
cmake --build build -j $(nproc)

echo ">>> [6/6] Adding the interpreter to the system PATH"
mkdir -p "$BIN_DIR"
if [ "./build/ton_app" -ef "$BIN_DIR/ton" ]; then
    echo ">>> [INFO] Executable is already linked at the target destination. Skipping copy."
else
    rm -f "$BIN_DIR/ton"

    cp ./build/ton_app "$BIN_DIR/ton"
fi

echo "======================================================"
echo ">>> [SUCCESS] Tøn language has been successfully compiled and installed on the system."
echo ">>>"
echo ">>> From now on, you can use \"ton\" command from anywhere in your system."
echo ">>> Just like that: ton example.ton"
echo ">>> Happy Tøning!"
echo "======================================================"
