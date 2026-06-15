This file is going to cover:
1. Building and running Ton
1. Using Ton with `.sf2` SoundFont library
1. potentially - an integrated script 

# Tøn Language: Building Tøn from Source

This guide explains the proccess of building Tøn from source.

---

## 1. Requirements
- **C++ 17**: A compiler that supports C++ 17
- **CMake**: Version 3.14 or higher
- **ANtlr4 tool**: Version 4.13.2
- **Java**: is it??



---

## TLDR - Running Instalation Scripts

Script for linux and windows are currently being developed

---

## 2. Building From Source



### Generating Grammar-Based Files.

Tøn uses ANTLR4 to parse its syntax. The first step is to generate the C++ lexer and parser files from the grammar .g4 file. You can do this with the following command

```
antlr4 -Dlanguage=Cpp -visitor -listener -o antlr4_generated Ton.g4
```

<br>

### Compiling The Code
Once the parser files are generated, use CMake to configure the project and compile the source code into an executable.

#####  Windows :poop:
```
cmake -G "MinGW Makefiles" -B build
cmake --build build
# ^ Use -j [num of cores] for faster building
```


#####  Linux :penguin:
```
cmake -B build
cmake --build build
# ^ Use -j [num of cores] for faster building
# ^ [num of cores] = -1 takes all there is
```

<br>

*If the compilation is successful, you will find the executable file (e.g., `ton_app`) inside your `build` directory.*

---

## 3. Running Test Script

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

## 4. Setting Up the SoundFont Library
To harness the full power of Tøn, you must attach `FluidR3_GM.sf2` file to the language. By default the file is located in `/path/to/project/root/data` directory and will work out of the box when running Tøn scripts directly from project root directory. However,to simplify the workflow and enable global access, it is highly recommended to move `.sf2` file into `$HOME/.ton` directory (`C:\Users\YourUsername\.ton` on Windows :poop:). Because this is the interpreter's primary search path, Tøn will be able to locate the SoundFont regardless of which directory you run your scripts from.

## 5. :notes: Happy Tøning! :notes: 