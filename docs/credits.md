# Tøn Language: Credits & Acknowledgments

This document lists the third-party libraries, tools, and open-source projects that make the **Tøn Programming Language** possible. We are deeply grateful to the developers and contributors of these amazing projects.

---

## 1. Core Parsing & Language Engine
Tools and libraries used for lexical analysis, parsing, and building the Abstract Syntax Tree (AST).

* **[ANTLR v4](https://www.antlr.org/)** 
    * **Authors:** Terence Parr and Sam Harwell
    * **Description:** ANother Tool for Language Recognition is used to generate the Lexer and Parser for Tøn grammar ([Ton.g4](../Ton.g4)).
    * **License:** BSD 3-Clause License (see full text below)
    * **Usage:** Core syntax parsing and visitor/listener generation.


## 2. Audio Processing & Export
Libraries utilized by the Tøn Audio Engine for handling SoundFonts and rendering audio files.

* **[AudioFile](https://github.com/adamstark/AudioFile)**
  * **Author:** Adam Stark
  * **Description:** A simple C++ library for reading and writing audio files. 
  * **License:** MIT License
  * **Usage:** Used to export the generated `TIMELINE` to physical `.wav` files on the disk.

* **[TinySoundFont](https://github.com/schellingb/TinySoundFont)**
  * **Author:** Bernhard Schelling 
  * **Description:** SoundFont2 synthesizer library in a single C/C++ file 
  * **License:** MIT License
  * **Usage:** Serves as the core instrument synthesizer. It parses `.sf2` SoundFont files and provides support for instruments loaded via the `USE` keyword.

## 4. Build System & Standard Library

* **[CMake](https://cmake.org/)**
    * **Description:** An open-source, cross-platform build system designed to build, test, and package software.

* **C++ Standard Library (C++17)**
    * **Description:** The language is entirely written in C++ and strongly relies on modern C++ features.

---
*If you notice a missing attribution, please open an issue or submit a pull request!*


---

## Appendix: Full License Texts

### ANTLR 4 License
```text
[The BSD License]
Copyright (c) 2012 Terence Parr and Sam Harwell
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, 
    this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, 
    this list of conditions and the following disclaimer in the documentation 
    and/or other materials provided with the distribution.
    Neither the name of the author nor the names of its contributors may be used
    to endorse or promote products derived from this software without 
    specific prior written permission. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```