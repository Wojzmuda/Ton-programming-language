# Tøn Language: Core Syntax & Programming

This section focuses on the programming fundamentals of the language: types, variables, control flow, and functions.


---


## Table of Contents

* [1. Comments](#1-comments)
* [2. Data Types](#2-data-types)
* [3. Basic Syntax & Variables](#3-basic-syntax--variables)
* [4. Control Flow](#4-control-flow)
* [5. Functions & Scoping](#5-functions--scoping)
* [6. Detailed Variable Lifecycle & Memory Management](#6-detailed-variable-lifecycle--memory-management)
* [7. Complex Datatypes: Strings and Arrays](#7-complex-datatypes-strings-and-arrays)


---

## 1. Comments

Use the `$` symbol for single-line comments.
```
$ This is a comment
```

---

## 2. Data Types

Tøn is a strongly typed language. Every variable and function must have a clearly defined type.

### Standard Types
* **`BOOL`**: Logical values (`TRUE` / `FALSE`).
* **`INT`**: Integers.
* **`NUMERICAL`**: Floating-point numbers for precise calculations.
* **`CHAR`**: Single characters (e.g., `'C'`).
* **`STRING`**: Text strings (e.g., `"Hello"`).
* **`ARRAY`**: Collections of elements (e.g., `INT[]`).
* **`VOID`**: Indicates no return type (used in functions).

### Domain Types (Audio)

Tøn features built-in, advanced types designed specifically for music generation: **`NOTE`**, **`SOUND`**, **`INSTRUMENT`**, **`TIMELINE`**, and **`TRACK`**. The complete guide to using these types is located in the Audio Engine documentation.

---



## 3. Basic Syntax & Variables

### Variable Declaration (`!make`)
Use `!make` to declare variables, followed by the type, name, and assignment operator `<-`.

```
!make INT tempo <- 120;
!make STRING greeting <- "Hello Music!";
```

### Output to Screen (`!shout`)
Prints text to the console.

```
!shout "Generating track...";
```

### Operators

Tøn supports a classic set of operators for logic and mathematics:

* **Assigment:** `<-`
* **Arithmetic:** `+`, `-`, `*`, `/`
* **Relational:** `==` (equal to), `!=` (not equal to), `<`, `>`, `<=`, `>=`
* **Logical:** `AND`, `OR`, `NOT`

> **Note:** Some operators are additionaly overloaded for Audio types. For more information, read [Audio Engine Documentation](./audio.md)

---

## 4. Control Flow
Conditionals and loops in Tøn use angle brackets `< >` for their expressions.
### If / Otherwise Statements
```text
!if <x > 10> {
    !shout "Greater than 10";
}
!otherwise if <x == 10> {
    !shout "Exactly 10";
}
!otherwise {
    !shout "Less than 10";
}
```

### Loops (`!loop` & `!until`)
You can loop a specific number of times, over a range, or until a condition is met.

```text
$ Loop a specific number of times
!loop <4 TIMES> {
    !shout "Beat!";
}

$ Loop with an iterator
!loop <INT i FROM 1 TO 8> {
    $ code here
}

$ Loop until a condition is true
!until <x == 0> {
    x -<- 1;
}
```
## ***:exclamation: TODO: LIFE CYCLE OF ARGUMENTS IN LOOP <> :exclamation:***

*Note: You can use `!break` to exit a loop early, or `!continue` to skip the current iteration and proceed to the next one.*

---


## 5. Functions & Scoping

Tøn allows you to encapsulate logic into functions and manage memory dynamically using block scopes. 

### Defining Functions
Functions are created using the `!define` keyword, followed by the return type, the function name, and its arguments inside angle brackets `< >`. Use the `!out` keyword to return a value.

```text
!define STRING introduce <INT arg1, INT arg2> {
    !if <arg1 > arg2> {
        !out "High";
    }
    !otherwise {
        !out "Low";
    }
}
```

### Calling Functions
How you call a function depends strictly on its return type:
1. **Value-Returning Functions** (`INT`, `SOUND`, `STRING`, etc.): Must be used as part of an expression (e.g., assigned to a variable or used in a mathematical equation).
2. **`VOID` Functions**: Do not return a value. They are executed as standalone statements and do not use the `!out` keyword.

```text
$ 1. Calling a function that returns a value
!make STRING result <- introduce(15, 10);

$ 2. Calling a VOID function
!define VOID play_intro <> {
    !shout "Starting the track...";
}

play_intro(); $ Standalone execution
```

### Anonymous Blocks
In Tøn, curly braces `{ }` are not restricted just to functions or loops. You can place an anonymous block anywhere in your code to create a temporary, isolated environment. Variables created inside an anonymous block are destroyed as soon as the block ends. Details on variables lifecycle in [chapter 6](#6-detailed-variable-lifecycle--memory-management).

```text
!make INT global_counter <- 1;

{
    $ This variable only exists inside these braces
    !make SOUND temporary_noise <- synth C4 100;
    
    $ We can modify variables from the outside
    global_counter <- 2; 
}

$ !shout temporary_noise; <-- THIS WOULD CAUSE AN ERROR
!shout global_counter;    $ Outputs: 2
```

---

## 6. Detailed Variable Lifecycle & Memory Management

Tøn manages memory automatically based on **block scopes** (`{ }`).

The lifecycle of any variable in Tøn follows three strict phases:

### 1. Declaration

A variable is born the moment the `!make` instruction is executed. From this point on, it occupies memory.

### 2. Visibility & Usage

The variable remains alive and accessible:

* Inside the block where it was created.
* Inside any nested blocks `{ }` created within that parent block.

### 3. Destruction

The exact moment the execution reaches the closing brace `}` of the block where the variable was defined, the variable is instantly destroyed. The memory it occupied is immediately freed. Therefore, variables created in global scope will occupy the memory until the program ends.

### Example of the Lifecycle

```ton
!make INT project_tempo <- 120;  $ Born in the global scope

{
    !make SOUND heavy_synth <- synth C2 5000; $ Born here
    
    $ Both variables are alive and can interact
    !make SOUND processed_synth <- heavy_synth * 1.5;
    
} $ <-- 'heavy_synth' and 'processed_synth' die here. Memory is freed.

$ !shout heavy_synth; <-- ERROR: Variable no longer exists.
!shout project_tempo; $ Still alive, outputs 120

```

### Good Practise Advise

If you are generating complex, multi-layered sounds (like bouncing multiple synths together before placing them on a track), it is highly recommended to do so inside **Anonymous Blocks**. This ensures that the intermediate, temporary audio files are deleted from your RAM immediately after they are mixed into the final variable, preventing your script from crashing due to memory limits.


Oto gotowy rozdział do dodania na samym końcu pliku `syntax.md`. Opisuje on dokładnie działanie ciągów znaków (Strings) oraz tablic (Arrays) zgodnie z tym, co pozwala osiągnąć Twój interpreter.

---

## 7. Complex Datatypes: Strings and Arrays

Tøn provides support for managing text and collections of data. While audio is the primary focus of the language, these complex datatypes are essential for labeling tracks, debugging, and managing sequences of variables.

### Strings (`STRING`)

Strings are used to store text and its values must be enclosed in double quotes (`" "`).

**Concatenation**
You can easily glue strings together using the addition operator (`+`).

```text
!make STRING prefix <- "Track name: ";
!make STRING title <- "Midnight Sonata";
!make STRING full_title <- prefix + title;

!shout full_title; $ Outputs: Track name: Midnight Sonata

```

**String Comparison**
Strings support relational operators, making it easy to build logic around text names or aliases. You can check for equality (`==`, `!=`) or alphabetical order (`<`, `>`).

```text
!make STRING mode <- "CHORUS";

!if <mode == "CHORUS"> {
    !shout "Applying chorus effect...";
}

```

**Retrieving Length**
???

### Arrays (`ARRAY`)

Arrays are collections of items grouped together under a single variable name. They are defined using square brackets `[ ]` with elements separated by commas.

**Creation and Assignment**
You can create an array of numbers, notes, or even sounds.

```text
!make ARRAY sequence <- [1, 2, 3, 4];
!make ARRAY notes <- [C4, E4, G4];

```

**Iterating Over Arrays (Foreach Loop)**
???

**Retrieving Array Length**

???

