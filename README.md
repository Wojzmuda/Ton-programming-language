# Tøn-programming-language :musical_note:
Description, will be written in the future
##  Requirements :spiral_notepad:
To build and run this project, you will need:
* **C++ Compiler**: A compiler that supports C++17 (e.g., GCC/MinGW, Clang, or MSVC).
* **CMake**: Version 3.14 or higher.
* **Antlr4 tool**: Version 4.13.2 - If you make any changes to the `Ton.g4` file
* *(Optional)* **Java (JRE)**: Only required if you plan to modify the `.g4` grammar file and regenerate the parser using the ANTLR4 tool.

##  Setup and Build :building_construction:

###  Windows :poop:
```
cmake -G "MinGW Makefiles" -B build
cmake --build build
# ^ Use -j [num of cores] for faster building
```


###  Linux :penguin:
```
cmake -B build
cmake --build build
# ^ Use -j [num of cores] for faster building
```

##  Generating the parser and lexer with antlr4 :deer:
```

antlr4 -Dlanguage=Cpp -visitor -listener -o antlr4_generated Ton.g4

```

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
