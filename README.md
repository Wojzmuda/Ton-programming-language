# Tøn-programming-language :musical_note:
Description, will be written in the future

---

## Documentation Structure :page_with_curl: 
*To be written when all documentation is merged and finished*

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

*To be updated when all is merged*
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
