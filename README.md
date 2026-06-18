# Tøn-programming-language :musical_note:
**Tøn** is a custom, strongly-typed programming language and built-in Digital Audio Workstation (DAW) engine written in modern C++. Designed for programmatic music generation, it allows developers to script, mix, and manipulate audio events natively. 

By blending standard programming paradigms (loops, functions, strict scoping) with domain-specific musical types (`NOTE`, `SOUND`, `TIMELINE`), Tøn empowers you to generate complex audio tracks from code and export them directly to `.wav` files. Under the hood, it features an ANTLR4-based multi-pass compiler, static type checking, and an intelligent, user-friendly diagnostic system.

---

## Documentation Structure :page_with_curl: 

* **[Setup & Build Guide](docs/setup.md)** – Requirements, installation scripts, and SoundFont configuration.
* **[Core Syntax](docs/syntax.md)** – Variables, data types, type casting, loops, and memory scoping.
* **[Audio Engine](docs/audio.md)** – Generating `SOUND`s, building a `TIMELINE`, audio operators (`+`, `&`), and `.wav` export.
* **[Diagnostics](docs/diagnostics.md)** – Smart typo suggestions, memory safety checks, and the `!debug;` tool.
* **[Technical Report](docs/raport.md)** – Deep dive into the C++ backend, ANTLR4 compiler pipeline, and DSP implementation.
* **[Credits & Acknowledgments](docs/credits.md)** – Third-party libraries, open-source tools, and licenses used in the project.

---

##  Setup and Build :building_construction:
This repository comes with 2 configuration scripts for both **Windows** and **Linux** machines. If you wish to dive deeper into the configuration, please visit [setup.md](./docs/setup.md) file.

#### Quick guide on running the configuration scripts:
To run the script, simply open your terminal in the project root directory and execute the following command:
#### Windows :poop:
```
.\install-windows.bat
```

####  Linux :penguin:
```
bash install-linux.sh
```

---

##  Project structure :evergreen_tree:

```
Ton-programming-language/
├── antlr4_generated/
│   ├── TonBaseVisitor.cpp
│   ├── TonBaseVisitor.h
│   ├── TonLexer.cpp
│   ├── TonParser.cpp
│   └── ...         
├── docs
│   ├── audio.md
│   ├── brainstorm.md
│   ├── credits.md
│   ├── diagnostics.md
│   ├── doc.md.old
│   ├── raport.md
│   ├── setup.md
│   └── syntax.md
├── examples/
│   └── .gitkeep
├── runtime/
├── include
│   ├── core
│   │   ├── MusicBase.h
│   │   ├── Scope.h
│   │   ├── Timeline.h
│   │   └── tsf.h
│   ├── diagnostics
│   │   └── Diagnostics.h
│   ├── interpreter
│   │   └── TonInterpreter.h
│   ├── listener
│   │   ├── TonDeclarationListener.h
│   │   └── TonSyntaxErrorListener.h
│   ├── repl
│   │   └── TonRepl.h
│   └── typechecker
│       └── TonTypeChecker.h
├── src
│   ├── interpreter
│   │   └── TonInterpreter.cpp
│   ├── listener
│   │   ├── TonDeclarationListener.cpp
│   │   └── TonSyntaxErrorListener.cpp
│   ├── main.cpp
│   ├── repl
│   │   └── TonRepl.cpp
│   └── typechecker
│       └── TonTypeChecker.cpp
├── CMakeLists.txt
├── install-linux.sh
├── install-windows.bat
├── LICENSE
├── README.md
└── Ton.g4
```
