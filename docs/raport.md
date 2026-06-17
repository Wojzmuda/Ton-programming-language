# Technical report

## Table of Contents

- [1. Summary](#1-summary)
- [2. Key Grammar Rules](#2-key-grammar-rules)
- [3. System Overview](#3-system-overview)
- [4. Implementation Details](#4-implementation-details)

## 1. Summary

Ton is a complete custom programming language interpreter written in modern C++ (C++17+), leveraging ANTLR4 for parsing. The implementation features a robust, multi-pass architecture that strictly separates syntax analysis, static type checking, variable hoisting (via the Listener pattern), and runtime execution (via the Visitor pattern). With specialized modules for mathematics and music generation, Ton offers users a flexible environment with highly descriptive, user-friendly error handling.

### Key Components

- ANTLR4 grammar for language parsing
- Visitor pattern for AST interpretation
- Dedicated Typechecker module for static analysis
- Domain-specific types for audio manipulation (`SOUND`, `NOTE`, `TRACK`, `TIMELINE`)
- Built-in audio rendering engine (Sine waves, mixing, normalization)
- Type-safe variable scoping and block management
- Advanced, user-friendly syntax error translation
- Strong C++ runtime memory safety with `std::any` cast protections

## 2. Key Grammar Rules

### 2.1. Program Structure

```antlr
program : header* statement* EOF ;
header : USE ID SEMI ;
```

A program is an optional sequence of headers followed by a sequence of statements and an end-of-file.

### 2.2 Statements

```antlr
statement
    : varDecl           # Variable declaration (e.g., !make INT x <- 5;)
    | trackDecl         # Timeline track creation
    | assignment        # Variable assignment
    | arrayOpStat       # Array operations (APPEND, CLEAR)
    | ifStat            # Conditional block (!if)
    | loopStat          # Loop block (!loop)
    | untilStat         # Until block (!until)
    | shoutStat         # Console output (!shout)
    | funcDef           # Function definition (!define)
    | audioOpStat       # Audio manipulation (SHIFT, MOVE, VOL, etc.)
    | saveStat          # Save to file (!save)
    | playStat          # Play audio (PLAY)
    | returnStat        # Return from function (!out)
    | breakStat         # Break loop (!break)
    | continueStat      # Continue loop (!continue)
    | callStat          # Function call statement
    | block             # Nameless scope
    | debugDumpStat     # Console memory dump for debugging
    ;
```

### 2.3 Variable Declaration & Assignment

```antlr
varDecl : EXCLAM_MARK MAKE type ID (ASSIGN expr)? SEMI ;

assignment 
    : target ASSIGN expr SEMI 
    | target ADD_ASSIGN expr SEMI 
    | target SUB_ASSIGN expr SEMI
    | target MULT_ASSIGN expr SEMI
    | target DIV_ASSIGN expr SEMI
    ;

target : ID (DOT ID (DOT STRING_VAL)?)? ;

type : TYPE_BOOL | TYPE_INT | TYPE_NUM | TYPE_CHAR | TYPE_STRING 
     | TYPE_NOTE | TYPE_SOUND | TYPE_VOID | TYPE_ARRAY | TYPE_INSTR 
     | TYPE_TIMELINE ;
```

**Type System:**
- `INT` / `NUMERICAL`: Integer and floating-point numeric values
- `BOOL`: Boolean (true/false)
- `CHAR` / `STRING`: Character and text values
- `NOTE` / `SOUND` / `INSTRUMENT`: Basic audio building blocks
- `TRACK` / `TIMELINE`: Multi-level audio arrangement structures
- `ARRAY`: Mixed-type data arrays

### 2.4 Audio & Domain-Specific Commands

```antlr
trackDecl : ID NEW TRACK ID SEMI ;

audioOpStat
    : SHIFT target BY expr SEMI
    | MOVE target TO expr SEMI
    | MUTE target SEMI
    | UNMUTE (target | ALL) SEMI
    | TRASH target SEMI
    | target VOL expr SEMI
    ;

playStat : PLAY target SEMI ;
saveStat : EXCLAM_MARK SAVE expr STRING_VAL SEMI ;
```

**Features:**
- Real-time manipulation of audio targets (shifting, moving, muting)
- Multi-level addressing support via `target` rule (e.g., `t1.violin."chorus"`)
- Direct audio playback and file saving

### 2.5 Control Flow Statements

```antlr
ifStat 
    : EXCLAM_MARK IF L_ANGLE expr R_ANGLE block 
      (EXCLAM_MARK OTHERWISE IF L_ANGLE expr R_ANGLE block)* (EXCLAM_MARK OTHERWISE block)?
    ;

loopStat 
    : EXCLAM_MARK LOOP L_ANGLE expr TIMES R_ANGLE block                                
    | EXCLAM_MARK LOOP L_ANGLE type ID FROM expr TO expr (BY expr)? R_ANGLE block                
    | EXCLAM_MARK LOOP L_ANGLE type ID ASSIGN expr R_ANGLE block                        
    ;

untilStat : EXCLAM_MARK UNTIL L_ANGLE expr R_ANGLE block ;
```

### 2.6 Function Definitions

```antlr
funcDef : EXCLAM_MARK DEFINE type ID L_ANGLE (type ID (COMMA type ID)*)? R_ANGLE block ;

callStat : ID L_PAREN (expr (COMMA expr)*)? R_PAREN SEMI ;

returnStat : EXCLAM_MARK OUT expr? SEMI ;
```

### 2.7 Expression Grammar

```antlr
expr
    : L_BRACKET (expr (COMMA expr)*)? R_BRACKET                               # ArrayExpr
    | ID L_PAREN (expr (COMMA expr)*)? R_PAREN                                # FunctionCallExpr
    | ID expr expr expr?                                                      # CreateSoundExpr
    | expr (AS STRING_VAL)? AT expr                                           # TrackEventExpr
    | expr L_BRACKET expr COLON expr R_BRACKET                                # SliceExpr   
    | expr L_BRACKET expr R_BRACKET                                           # IndexExpr    
    | L_PAREN expr R_PAREN                                                    # ParensExpr
    | (NOT_KW) expr                                                           # NotExpr
    | (PLUS | MINUS) expr                                                     # UnaryExpr
    | expr (MULT | DIV_OP | COLON) expr                                       # MulDivExpr   
    | expr (PLUS | MINUS ) expr                                               # AddSubMixExpr
    | expr AMPERSAND expr                                                     # ConcatExpr
    | expr (EQ | NEQ | L_ANGLE | R_ANGLE | L_ANGLE_EQ | R_ANGLE_EQ) expr      # RelationalExpr 
    | expr AND_OP expr                                                        # AndExpr
    | expr OR_OP expr                                                         # OrExpr
    | NOTE_VAL | INT_VAL | NUM_VAL | BOOL_VAL | CHAR_VAL | STRING_VAL | target # Literals & Targets
    | LENGTH expr                                                             # LengthOfExpr 
    | EMPTYSOUND                                                              # EmptySoundExpr   
    | ISOLATE target                                                          # IsolateExpr
    | POP ID                                                                  # PopExpr                       
    ;
```

**Operator Overloading & Features:**
- `+` operator doubles as an audio mixing tool (`AddSubMixExpr`)
- `&` operator handles standard concatenation and audio chaining (`ConcatExpr`)
- Audio creation is streamlined without brackets (`CreateSoundExpr`)

### 2.8 Lexical Tokens

```antlr
NOTE_VAL   : [A-G] ('#' | 'b')? [0-9] ;
INT_VAL    : [0-9]+ ;
NUM_VAL    : [0-9]+ '.' [0-9]+ ;
BOOL_VAL   : 'true' | 'false' | 'TRUE' | 'FALSE' ;
CHAR_VAL   : '\'' . '\'' ;
STRING_VAL : '"' ~["]* '"' ;

ID         : [a-zA-Z_][a-zA-Z0-9_]* ;
WS         : [ \t\r\n]+ -> skip ;
COMMENT    : '$' ~[\r\n]* -> skip ;
```

### 2.9 Explicit Type Casting

```antlr
expr : L_ANGLE type R_ANGLE expr ; # CastExpr
```

The language supports explicit type casting for basic data types (`INT`, `NUMERICAL`, `BOOL`, `STRING`, `CHAR`). It handles safe string conversions, truncation of floating-point numbers, and boolean evaluations natively.

## 3. System Overview

### 3.1. Ton Compiler Pipeline

```text
User Program (Ton_program.txt)
          ↓
    ┌─────────────┐
    │   Lexer     │  (TonLexer.cpp)
    │ Tokenization│
    └─────────────┘
          ↓
    ┌─────────────┐
    │   Parser    │  (TonParser.cpp)
    │  AST Build  │
    └─────────────┘
          ↓
    ┌────────────────────────┐
    │  Syntax Error Listener │  (TonSyntaxErrorListener.cpp)
    │  Intercepts ANTLR errs │
    └────────────────────────┘
          ↓ (If 0 errors)
    ┌────────────────────────┐
    │  Declaration Listener  │  (TonDeclarationListener.cpp)
    │  Hoisting / Scoping    │
    └────────────────────────┘
          ↓
    ┌────────────────────────┐
    │      Typechecker       │  (TonTypeChecker.cpp)
    │   Static Type Safety   │
    └────────────────────────┘
          ↓ (If validation passes)
    ┌────────────────────────┐
    │     Interpreter        │  (TonInterpreter.cpp)
    │   Visitor Execution    │
    └────────────────────────┘
          ↓
    Program Output / Audio / Results
```

### 3.2. Execution Flow

#### Step 1: Tokenization
```text
Source Code → TonLexer → Token Stream
```

#### Step 2: Parsing
```text
Token Stream → TonParser → Parse Tree (AST)
```

#### Step 3: Error Checking
```text
Parse Tree → TonSyntaxErrorListener → Error Report
(if errors > 0: STOP)
```

#### Step 4: Semantic Analysis & Hoisting
```text
Parse Tree → TonDeclarationListener & TonTypeChecker
(if validation fails: STOP)
```

#### Step 5: Interpretation
```text
Parse Tree → TonInterpreter → Execution Results
```

## 4. Implementation Details

### 4.1 Project Structure

The directory layout follows C++ best practices:

```text
├── docs/                 
├── examples/             
│   ├── error_examples/         
│   ├── math_examples/          
│   ├── Music_examples/         
│   └── type_checker_examples/  
├── external/             
├── include/              
│   ├── core/
│   ├── interpreter/
│   ├── listener/
│   └── typechecker/
└── src/                  
    ├── interpreter/
    ├── listener/
    └── typechecker/
```

### 4.2 Core Data Structures & Audio Engine

Ton is not just a language parser; it includes a built-in digital audio workstation (DAW) engine to handle musical types natively.

#### 4.2.1 Musical Notes and Frequencies
The `Note` struct translates standard musical pitches (e.g., "C#4") into mathematical data required for audio synthesis. It maps pitch strings to semitone offsets using a static lookup table (`pitchToSemitone`) and calculates frequencies based on the A4 = 440Hz standard. It also translates notes to standard MIDI numbers (0-127), where A4 corresponds to MIDI number 69.

```cpp
double getFrequency() const {
    return 440.0 * std::pow(2.0, getOffsetFromA4() / 12.0);
}
```

The struct supports full comparison operators (`==`, `!=`, `<`, `<=`, `>`, `>=`) based on MIDI number conversion, enabling sorting and range checks on notes.

#### 4.2.2 Sound Synthesis and Buffers
The `Sound` class holds raw audio sample data (`std::vector<float> samples`). The engine natively supports waveform generation at a professional 44.1kHz sample rate (`static constexpr int sampleRate = 44100`).

```cpp
void generateSineWave(Note note, int durationMs) {
    // Clears buffer, calculates total samples, generates sine wave
    // using: sin(2π * frequency * time) for each sample point
}
```

The `Sound` structure safely overloads the `*` operator, allowing the user to amplify or attenuate volume by simply multiplying the object (`sound * 0.5`). A symmetric global overload enables scalar-on-left multiplication (`0.5 * sound`). A `normalize()` method prevents clipping by scaling all samples relative to the largest absolute value. The class also provides placeholder methods for Saw and Square wave synthesis, with a centralized `generateSynthWave()` dispatcher that routes to the appropriate waveform generator based on a string name ("sine", "saw", "square").

#### 4.2.3 Instrument Abstraction
The `Instrument` class represents a sound generator with three possible backend types (defined in `InstrumentType` enum):
- **Synth**: Built-in synthesis functions (sine wave by default)
- **SoundFont**: MIDI preset index for external SoundFont rendering
- **RawSample**: Audio data loaded from a file via the `AudioFile` library

Constructors differentiate between these modes: default synthesis, SoundFont preset binding, and file-based sample loading with automatic diagnostic output.

#### 4.2.4 Multitrack Timeline Rendering
The `Timeline` struct acts as a master container. It holds multiple `Track` objects (each with a name, volume, mute flag, and vector of `TrackEvent` structures), which in turn hold `TrackEvent` structures (a `Sound` triggered at a specific millisecond, optionally tagged with an alias for targeted operations).

The `renderFinalSound()` method handles complex audio mixing:

```cpp
Sound renderFinalSound() const {
    // First pass: calculate maximum buffer size across all tracks
    // Second pass: superimpose sample values with per-track volume scaling
    // Muted tracks are skipped, track volume applied during mixing
    // resultSound.samples[startSample + i] += ev.sound.samples[i] * track.volume;
}
```

The method performs two passes: first calculating the maximum required buffer size by scanning all track events, then iterating through all active tracks to safely superimpose sample values. Muted tracks are skipped entirely, and each track's volume multiplier is applied during the mixing process.

#### 4.2.5 Variable Memory Management (`Scope<T>`)
Memory and namespaces are managed via a generic, recursively linked `Scope` class. This allows lexical scoping for nested blocks, where the interpreter first checks the local namespace map (`values` and `types` stored in `std::map`), and recursively falls back to the `parent` scope if the variable is not found.

The `Scope` class maintains two parallel maps:
- `values`: Stores the actual variable values (or line numbers during the declaration pass)
- `types`: Stores type annotations as strings for static analysis

Key operations:
- **`define()`**: Always inserts locally into the current scope (used for new declarations)
- **`get()`**: Recursively searches up the scope chain; throws if not found
- **`set()`**: Recursively searches up the scope chain to update an existing variable; throws if not found
- **`existsLocally()`**: Checks only the current scope (used for duplicate declaration detection)
- **`exists()`**: Recursively checks all parent scopes
- **`resolveType()`**: Recursively searches for a variable's type annotation

The distinction between `set()` (update existing) and `define()` (create new) enforces the language's semantic rule that variables must be declared before assignment, while preventing accidental shadowing through the `existsLocally()` check during the declaration pass.

#### 4.2.6 Built-in Sound Library
The engine provides a predefined set of ready-to-use instruments mapped to specific MIDI preset indices from the General MIDI standard. Users can initialize them via the `USE` header.
- **Synthesizers (`SYNTHS`):** `sine`, `saw`, `square`
- **Sampled Instruments (`SAMPLE_INSTRUMENTS`):** 13 curated presets including `piano`, `organ`, `guitar`, `bass`, `strings`, `drums`, and orchestral elements.

### 4.3 Main Execution Pipeline (main.cpp)

The entry point establishes the multi-pass architecture, registering custom listeners and protecting the runtime environment from `std::bad_any_cast` exceptions caused by the ANTLR4 C++ target.

```cpp
int main(int argc, const char* argv[]){
    // File stream initialization...
    // Lexer & Parser setup with custom error listeners
    
    // Halt execution if syntax errors exist
    if (lexer.getNumberOfSyntaxErrors() + parser.getNumberOfSyntaxErrors() > 0) return 1;

    try {
        // Phase 1: Hoisting declarations (ParseTreeWalker)
        // Phase 2: Execution (Interpreter visitor)
    } 
    catch (const std::bad_any_cast& e) {
        // Catch runtime type mismatches caused by std::any cast failures
        return 1;
    }
    // ... catch other std::exception and fatal errors ...
}
```

### 4.4 Error Handling Architecture

#### 4.4.1 Custom Error Listener (TonSyntaxErrorListener)

Ton actively suppresses raw, confusing ANTLR4 exceptions in favor of a custom-built diagnostic system. The listener intercepts `RecognitionException` events and transforms them into readable hints by querying the grammar vocabulary.

```cpp
void TonSyntaxErrorListener::syntaxError(antlr4::Recognizer *recognizer, 
                                         antlr4::Token *offendingSymbol, 
                                         size_t line, 
                                         size_t charPositionInLine, 
                                         const std::string &msg, 
                                         std::exception_ptr e) {
    std::string tokenText = (offendingSymbol != nullptr) ? offendingSymbol->getText() : "Unrecognized sign";
    std::string message;
    std::string expected = "";

    // Extract expected tokens from vocabulary if exception exists
    if (e != nullptr) {
        try {
            std::rethrow_exception(e);
        } catch (const antlr4::RecognitionException &re) {
            if (re.getOffendingState() != (size_t)-1) {
                const antlr4::dfa::Vocabulary &vocab = recognizer->getVocabulary(); 
                expected = re.getExpectedTokens().toString(vocab);
            } else {
                expected = "Could not determine expected tokens (Invalid State)";
            }
        } catch (...) {}
    }

    // Map raw ANTLR messages to user-friendly Ton messages
    if (msg.find("mismatched input") != std::string::npos){
        message = "Unexpected sign or word.";
        if (!expected.empty()) message += "\n    Expected one of: " + expected;
    }
    else if (msg.find("missing") != std::string::npos){
        message = "A missing sign";
        if (!expected.empty()) message += "\n    Try adding: " + expected;
    }
    // ... Additional message mapping (no viable alternative, extraneous input, etc.) ...
    else {
        message = msg;
    }

    // Display cleanly formatted error to the user
    std::cerr << "\n>>> [SYNTAX ERROR] Line " << line << ", Column " << charPositionInLine << ":\n"
              << "    Problem with: '" << tokenText << "'\n"
              << "    " << message << "\n";
}
```

### 4.5 Variable Scoping and Semantic Pre-processing

The `TonDeclarationListener` performs a critical pre-processing pass over the AST. It builds the symbol table, establishes lexical scopes, and validates semantic rules before runtime execution.

#### 4.5.1 Block and Scope Management

Scoping is managed using a nested `std::shared_ptr<Scope<int>>` structure. A new scope is automatically pushed for function bodies, loops, and nameless blocks (`{ ... }`), preventing variable leakage.

```cpp
void TonDeclarationListener::enterBlock(TonParser::BlockContext *ctx) {
    // Detect if parent is function definition or loop
    // Prevent creating duplicate scopes if the parent already created one
    if (!isFuncBody && !isLoopBody) {
        currentScope = std::make_shared<Scope<int>>(currentScope);
    }
}
```

#### 4.5.2 Duplicate Declaration Detection

Variable and track declarations are intercepted to prevent naming collisions within the same local scope. The listener leverages the `existsLocally()` method of `Scope`, which checks only the current scope map rather than recursing up the parent chain.

```cpp
void TonDeclarationListener::enterVarDecl(TonParser::VarDeclContext *ctx){
    // Check if variable already exists in the local scope
    if(currentScope->existsLocally(varName)){
        throw std::runtime_error("Variable redeclaration error...");
    }
    currentScope->define(varName, type, currentLine);
}
```

#### 4.5.3 Flow Control Validation

The listener tracks the depth of loops (`loopLevel`) to ensure that `!break` and `!continue` statements are strictly used inside valid looping contexts.

```cpp
void TonDeclarationListener::enterBreakStat(TonParser::BreakStatContext *ctx) {
    if (loopLevel == 0) {
        throw std::runtime_error("'!break' statement is not allowed outside of a loop.");
    }
}
```

#### 4.5.4 Context-Aware Assignments (Timeline Routing)

The listener heavily validates assignments (`exitAssignment`), splitting logic based on whether the target is a standard variable or a multi-level `TIMELINE` structure. Three scenarios are handled:

- **Scenario A**: Standard variable assignment with strict type checking
- **Scenario B1**: Assignment to a specific alias within a Timeline track (e.g., `mySong.bassline."start"`), validating that only `SOUND` or `TRACK_EVENT` types are assigned
- **Scenario B2**: Whole-track assignment (e.g., `mySong.bassline <- [...]`), requiring `ARRAY` or `TRACK_EVENT` types

#### 4.5.5 Explicit Scope Resolution
To handle deep nesting (e.g., inside loops or function calls), the `resolveScope` mechanism allows for explicit upward scope traversal. By utilizing `elderRef()`, the interpreter can bypass the local namespace and intentionally target variables in outer scopes, effectively solving variable shadowing issues without breaking strict lexical scoping rules.

### 4.6 Static Analysis (Typechecker)

The `TonTypeChecker` module interacts closely with the Declaration Listener, verifying semantic correctness for expressions to prevent illegal operations on data types. It returns type names as `std::any`.

#### 4.6.1 Audio Domain Operations

The typechecker implements strict rules for domain-specific musical types (`SOUND`, `NOTE`). Audio creation validates that the first argument is a `NOTE` and the second is an `INT` (duration). Mathematical operations enforce constraints such as prohibiting division on `SOUND` types while allowing multiplication by numeric scalars.

```cpp
// CreateSound validation: arg1 must be NOTE, arg2 must be INT
// MulDiv validation: SOUND / x is forbidden, SOUND * NUMERICAL is allowed
```

#### 4.6.2 Dynamic Arrays & UNKNOWN Types

Ton arrays can hold mixed types. The static analyzer handles this dynamically by returning an `UNKNOWN` type upon extraction, deferring the final check to the runtime interpreter. This is a deliberate design choice since arrays like `[1, "text", C#4]` contain elements of different types that cannot be statically determined.

```cpp
std::any TonTypeChecker::visitIndexExpr(TonParser::IndexExprContext *ctx) {
    // Verify index is INT
    // STRING indexing returns CHAR (static knowledge)
    // ARRAY indexing returns UNKNOWN (mixed-type arrays)
}
```
#### 4.6.3 Implicit Type Coercion
The interpreter implements a robust implicit type conversion system (`TonInterpreter::coerceType`) at runtime. It automatically and safely converts primitives when assigning variables or passing function arguments. For example:
- `BOOL` can be evaluated as numeric `1`/`0` or `1.0`/`0.0`.
- `INT` and `FLOAT` (`NUMERICAL`) are automatically promoted or truncated depending on the expected parameter type.
This minimizes strict-typing friction for the user while maintaining memory safety in the C++ backend.

### 4.7 Runtime Execution Engine (TonInterpreter)

The `TonInterpreter` is the core execution engine of the language, utilizing the Visitor pattern (`antlr4::tree::AbstractParseTreeVisitor`) to evaluate the AST. It handles environment setup, dynamic memory assignment, control flow via C++ exceptions, and domain-specific polymorphic operations.

#### 4.7.1 Asset Initialization & Environment Fallbacks

Upon instantiation, the interpreter dynamically locates the required SoundFont file (`FluidR3_GM.sf2`) using a cascading fallback mechanism. It checks environment variables, local debug/build directories, and finally the user's home directory (`$HOME/.ton/`).

```cpp
std::string TonInterpreter::findSoundFontPath() {
    std::string fileName = "FluidR3_GM.sf2";

    // 1. Check Environment Variable
    if (const char* envPath = std::getenv("TON_SOUNDFONT_PATH")) {
        std::filesystem::path p(envPath);
        if (std::filesystem::exists(p)) return p.string();
    }

    // 2. Check local relative paths (for IDE/Terminal debugging)
    std::vector<std::filesystem::path> possiblePaths = {
        std::filesystem::path("data") / fileName,              
        std::filesystem::path("..") / "data" / fileName,       
        std::filesystem::path("..") / ".." / "data" / fileName 
    };

    // 3. Check User's Home Directory
    const char* homeDir = std::getenv("HOME") ? std::getenv("HOME") : std::getenv("USERPROFILE");
    if (homeDir) {
        std::filesystem::path home(homeDir);
        possiblePaths.push_back(home / ".ton" / fileName);
    }

    // Return the first existing path, fallback to relative "data/"
    for (const auto& path : possiblePaths) {
        if (std::filesystem::exists(path)) return path.string();
    }
    return (std::filesystem::path("data") / fileName).string();
}
```

#### 4.7.2 Control Flow Implementation (Exceptions)

Ton implements control flow mechanisms (`!break`, `!continue`, `!out`) natively by throwing custom C++ exceptions (`BreakException`, `ContinueException`, `ReturnException`). The AST Visitors corresponding to loops (`visitLoopStat`, `visitUntilStat`) catch these exceptions to alter the execution path without deeply nesting state flags.

```cpp
std::any TonInterpreter::visitUntilStat(TonParser::UntilStatContext *ctx) {
    while (true){
        // ... evaluate boolean condition ...
        if (condition) break;
        
        try {
            visit(ctx->block()); 
        } 
        catch (BreakException&) {
            break;
        } 
        catch (ContinueException&) {
            continue;
        }
    }
    return {};
}

std::any TonInterpreter::visitReturnStat(TonParser::ReturnStatContext *ctx){
    std::any valueToReturn = {};
    if(ctx->expr()){
        valueToReturn = visit(ctx->expr());
    }
    // Halts current function execution and passes value up the call stack
    throw ReturnException(valueToReturn);
}
```

#### 4.7.3 Call Stack & Function Execution

To prevent stack overflow crashes from infinite recursion, the interpreter enforces a strict `MAX_STACK_DEPTH`. During a function call, a new isolated `Scope` is created, arguments are evaluated and type-checked at runtime, and the execution is pushed to the new context.

```cpp
std::any TonInterpreter::executeFunctionLogic(const std::string& funcName, const std::vector<TonParser::ExprContext*>& argsCtx){
    this->validateStackDepth(); // Throws if currentStackDepth >= MAX_STACK_DEPTH

    // ... fetch function definition and evaluate passed arguments ...

    auto previousScope = currentScope;
    currentScope = std::make_shared<Scope<std::any>>(previousScope);
    this->currentStackDepth++;

    // Parameter binding & runtime type validation
    for(size_t i = 0; i < expectedargs; i++){
        // ... extract expected type and evaluate argument type ...
        if (!typeMatch) {
            currentScope = previousScope;
            this->currentStackDepth--;
            throw std::runtime_error("Argument '" + paramName + "' in function '" + funcName + "' must be of type " + paramType + ".");
        }
        currentScope->define(paramName, paramType, argval);
    }

    std::any result = {};
    try{
        visit(funcdefctx->block());
        // ... handle void returns ...
    } catch(const ReturnException& ret){
        result = ret.returnValue;
        // ... validate return type against function signature ...
    } catch(...){
        // Restore state on fatal error
        currentScope = previousScope;
        this->currentStackDepth--;
        throw;
    }
    
    currentScope = previousScope;
    this->currentStackDepth--;
    return result;
}
```

#### 4.7.4 Polymorphic Audio Operators

The interpreter elegantly handles domain-specific polymorphism. For example, the `+` operator acts as mathematical addition for numbers, concatenation for strings, and *audio mixing* for sounds. The `LENGTH` keyword dynamically calculates sizes for data structures or maximum playback duration in milliseconds for audio objects.

```cpp
std::any TonInterpreter::visitLengthOfExpr(TonParser::LengthOfExprContext *ctx) {
    std::any val = visit(ctx->expr());

    if (val.type() == typeid(std::string)) {
        return static_cast<int>(std::any_cast<std::string>(val).length());
    }
    else if (val.type() == typeid(std::vector<std::any>)) {
        return static_cast<int>(std::any_cast<std::vector<std::any>>(val).size());
    }
    else if (val.type() == typeid(Sound)) {
        Sound s = std::any_cast<Sound>(val);
        // Calculate audio duration in milliseconds based on sample count
        double durationSec = static_cast<double>(s.samples.size()) / s.sampleRate;
        return static_cast<int>(durationSec * 1000.0);
    }
    else if (val.type() == typeid(Timeline)) {
        Timeline tl = std::any_cast<Timeline>(val);
        int maxMs = 0;
        // Scan all tracks and events to find the absolute end time
        for (const auto& trackPair : tl.tracks) {
            for (const auto& ev : trackPair.second.events) {
                double durationSec = static_cast<double>(ev.sound.samples.size()) / ev.sound.sampleRate;
                int endMs = ev.startTimeMs + static_cast<int>(durationSec * 1000.0);
                if (endMs > maxMs) maxMs = endMs;
            }
        }
        return maxMs;
    }
    // ... handle invalid types ...
}
```

#### 4.7.5 Audio File Export (`!save`)

The `!save` command serves as the final rendering step. It takes a `SOUND` or `TIMELINE` object, processes it, normalizes the waveform to prevent clipping, and exports it directly to disk as a mono `.wav` file using the `AudioFile` library.

```cpp
std::any TonInterpreter::visitSaveStat(TonParser::SaveStatContext *ctx) {
    // ... extract filename and evaluate target object ...
    Sound soundToSave;

    if (exportedValue.type() == typeid(Sound)) {
        soundToSave = std::any_cast<Sound>(exportedValue);
    } 
    else if (exportedValue.type() == typeid(Timeline)) {
        Timeline tl = std::any_cast<Timeline>(exportedValue);
        soundToSave = tl.renderFinalSound(); 
    }
    // ... validation omitted ...

    soundToSave.normalize();

    AudioFile<float> audioFile;
    audioFile.setNumChannels(1);
    audioFile.setNumSamplesPerChannel(soundToSave.samples.size());
    audioFile.setSampleRate(Sound::sampleRate);
    audioFile.samples[0] = soundToSave.samples;

    if (audioFile.save(fileName)) {
        std::cout << ">>> [SYSTEM] Successfully exported SOUND to: " << fileName << std::endl;
    } 
    // ... error handling ...
    return {};
}
```

#### 4.7.6 Memory Debugging Utility
Ton features a built-in state inspection tool (`visitDebugDumpStat`) that allows users to dump the entire execution context to the console. When triggered, it walks recursively up the environment chain and prints a formatted, aligned table of all current variables, their designated types, initialization status, and current values. Complex memory structures (like `ARRAY`, `SOUND`, or `TIMELINE`) are gracefully summarized, making script debugging highly efficient without external tools.

```bash
==================== [TON DEBUG DUMP] ====================
Triggered at line: 70

  VARIABLE NAME       TYPE           INITIALIZED    CURRENT VALUE
  -----------------------------------------------------------------
  current_volume      INT            FALSE          [Uninitialized / Complex Type]
  late_initialized    INT            TRUE           777
  local_unassigned    INT            FALSE          [Uninitialized / Complex Type]
  pi_value            NUMERICAL      FALSE          [Uninitialized / Complex Type]
  track_events        ARRAY          FALSE          [Uninitialized / Complex Type]
  --- Parent Scope (Level 1) ---
  global_tempo        INT            FALSE          [Uninitialized / Complex Type]
  global_unassigned   INT            FALSE          [Uninitialized / Complex Type]
  playMelody          FUNCTION       TRUE           [Uninitialized / Complex Type]
  user_name           STRING         FALSE          [Uninitialized / Complex Type]
==========================================================

```

#### 4.7.7 Audio Polymorphism Mechanics
The interpreter distinguishes between audio mixing and audio concatenation on a low mathematical level:
- **Mixing (`+` operator):** The `visitAddSubMixExpr` iterates through the sample arrays of two `Sound` objects, mathematically superimposing (adding) the float values of parallel samples to play them simultaneously.
- **Concatenation (`&` operator):** The `visitConcatExpr` utilizes `std::vector::insert` to sequentially append the raw buffer of the right-hand `Sound` to the end of the left-hand `Sound`, enabling rapid, seamless chronological chaining.