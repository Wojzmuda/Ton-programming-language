# Tøn Language: Diagnostics & Tooling

Tøn is designed not just to execute code, but to actively assist the developer. This document outlines the built-in diagnostic tools, memory safety features, and debugging commands available in the Tøn interpreter. 

---

## 1. Smart Typo Suggestions (Levenshtein Algorithm)

Tøn features an intelligent, scope-aware suggestion system for unresolved identifiers. 

When you attempt to use a variable, array, or function that does not exist, the interpreter uses the **Levenshtein distance algorithm** to scan your current memory scope (including parent blocks). If it finds a similarly named identifier, it will suggest it directly in the error console.

**Example:**
```text
!make STRING playlist <- "My Songs";
!shout playlst; 
```

**Console Output:**
```text
[Error] Line 2: Variable 'playlst' is not defined. Suggestion: Did you mean 'playlist'?
```
*Note: The suggestion engine integrates seamlessly with functions, array operations (`APPEND`, `POP`), and standard variable assignments.*

---

## 2. Strict Initialization Checks

Tøn prioritizes memory safety and predictable audio generation. The Type Checker ensures that no variable is used before it is explicitly assigned a value. 
While you can declare a variable to reserve memory (e.g., `!make INT counter;`), any attempt to read from it, use it in a mathematical operation, or pass it to an audio node without initializing it first will be intercepted by the interpreter's type checker before execution.

**Example:**
```text
!make INT tempo;
!make INT new_tempo <- tempo + 10;
```

**Console Output:**
```text
[Error] Variable 'tempo' is declared but uninitialized.
```

---

## 3. Memory State Dump (`!debug;`)

Tøn provides the `!debug;` statement. Placing this anywhere in your code will halt the interpreter and print a detailed table of the current memory scope directly to your terminal. It displays every living variable, its associated data type, initialization status, and current value, organized by hierarchical memory levels.

**Usage:**
```text
...
!make INT global_tempo <- 125;
!make STRING user_name <- "Aleksander";

{
    !make INT current_volume <- 90;
    !make INT local_unassigned;
    !debug;
}
...
```

**Console Output Example:**
```text
==================== [TON DEBUG DUMP] ====================
Triggered at line: 70

  VARIABLE NAME       TYPE           INITIALIZED    CURRENT VALUE
  -----------------------------------------------------------------
  current_volume      INT            TRUE           90
  local_unassigned    INT            FALSE          [Uninitialized / Complex Type]
  --- Parent Scope (Level 1) ---
  global_tempo        INT            TRUE           125
  user_name           STRING         TRUE           "Aleksander"
===========================================================
```
*Use `!debug;` as a diagnostic probe to verify that temporary audio variables are being correctly destroyed when their block ends, and to inspect values at runtime.*