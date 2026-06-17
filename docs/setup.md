# Tøn Language: Building Tøn from Source

This guide explains the proccess of building Tøn from source.

---

## Table of Contents
- [Requirements](#requirements)
- [Running Installation Scripts](#running-instalation-scripts)
- [Building From Source](#building-from-source)
  - [1. Generating Grammar-Based Files](#1-generating-grammar-based-files)
  - [2. Compiling The Code](#2-compiling-the-code)
  - [3. Running Test Script](#3-running-test-script)
  - [4. Setting Up the SoundFont Library](#4-setting-up-the-soundfont-library)
  - [5. Happy Tøning!](#5-notes-happy-tøning-notes)

---

## Requirements
- **C++ 17**: A compiler that supports C++ 17
- **CMake**: Version 3.14 or higher
- **ANtlr4 tool**: Version 4.13.2
- **Java**: JRE 11 or higher (required to run the ANTLR4 `.jar` generator tool).



---

## Running Instalation Scripts

For the fastest and seamless setup, we provide an automated instalation scripts for both Linux and Windows environments. Use it for both first time setup and updating Tøn to newer version.

*The script automates the build and setup steps detailed further in this file.*

### Linux :penguin:
To run the script, simply open your terminal in the project root directory and execute the following command:

```bash
bash install-linux.sh
```

### Windows :poop:
To run the script, simply open your terminal in the project root directory and execute the following command:

```bat
.\install-windows.bat
```

Important: Please restart your terminal/IDE after the script finishes to apply the new system PATH variable!

---

## Building From Source
*The guide below follows every step you need to take to set up the Tøn envirnment on your own.*

---

### 1. Generating Grammar-Based Files.

Tøn uses ANTLR4 to parse its syntax. The first step is to generate the C++ lexer and parser files from the grammar .g4 file. You can do this with the following command

```bash
antlr4 -Dlanguage=Cpp -visitor -listener -o antlr4_generated Ton.g4
```

---

### 2. Compiling The Code
Once the parser files are generated, use CMake to configure the project and compile the source code into an executable.

#####  Windows :poop:
```bash
cmake -G "MinGW Makefiles" -B build
cmake --build build
# ^ Use -j [num of cores] for faster building
```


#####  Linux :penguin:
```bash
cmake -B build
cmake --build build
# ^ Use -j [num of cores] for faster building
```

<br>

*If the compilation is successful, you will find the executable file (e.g., `ton_app`) inside your `build` directory.*

---

### 3. Running Test Script

With the interpreter successfully built, you should be able to run simple Tøn script. Instrument features are not available since we did not setup `.sf2` file yet.

Create a simple test file named `hello_ton.ton`:

```text
$ hello_music.ton
!shout "It's Tønesame!"
```

Run the script by passing the file to your newly compiled interpreter, assuming you are in the project root directory:
```bash
./build/ton_app path/to/hello_music.ton

```

If everything is set up correctly, your terminal will print given `STRING` on standard output.

> **Note:** Since `ton_app` is a regular executable it is highly recommended to move it into $PATH or create a symlink to the original file in order to be able to run Tøn scripts from any file location.

---

### 4. Setting Up the SoundFont Library
To harness the full power of Tøn, you must attach `FluidR3_GM.sf2` file to the language, which allows you to create `SOUND`s based on real instruments samples (visit [Audio Docs](./audio.md) for syntax details). 
First, you need to download the file from official GitHub repository. The file is distributed under [**MIT** License](https://github.com/pianobooster/fluid-soundfont/blob/main/COPYING).
Now, from **project root** directory run following commands:

#####  Linux :penguin:
```bash
mkdir -p data
cd data
DOWNLOAD_URL="https://github.com/pianobooster/fluid-soundfont/releases/download/v3.1/FluidR3_GM.sf2"
wget --show-progress -O "FluidR3_GM.sf2" "$DOWNLOAD_URL"
```

#####  Windows :poop:
```bat
mkdir data
cd data
curl -L -# -o "FluidR3_GM.sf2" "https://github.com/pianobooster/fluid-soundfont/releases/download/v3.1/FluidR3_GM.sf2"
```
<br>

Now, you will find `FluidR3_GM.sf2` file located in `/path/to/project/root/data` directory. It will work out of the box when running Tøn scripts directly from project root directory. However,to simplify the workflow and enable global access, it is highly recommended to move `.sf2` file into `$HOME/.ton` directory (`C:\Users\YourUsername\.ton` on Windows :poop:). Because this is the interpreter's primary search path, Tøn will be able to locate the SoundFont regardless of which directory you run your scripts from.

---

## 5. :notes: Happy Tøning! :notes: 