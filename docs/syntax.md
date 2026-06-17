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

### Delayed Assignment (Uninitialized Variables)
You can declare a variable without immediately assigning a value to it by omitting the `<-` operator. However, Tøn enforces strict memory safety: you **cannot** read or use this variable until it has been explicitly assigned a value.

```text
!make INT counter;       $ Variable is born, but empty
!shout counter;          $ <-- ERROR: Variable is declared but uninitialized.

counter <- 1;            $ Value is assigned
!shout counter;          $ Now it works! Outputs: 1
```

### Output to Screen (`!shout`)
It evaluates expressions at runtime and prints their representation directly to the console. 

You are allowed to pass all available data types to `!shout` statement, however the complex types might be printed as `[COMPLEX OBJECT]` due to the inherent inability to convert them to text.

You can also print multiple independent values in a single statement by separating them with a comma (`,`).

```ton
!shout "Tempo is set to:", 120, "BPM";
```

### Operators

Tøn supports a classic set of operators for logic and mathematics:

* **Assignment:** `<-`
* **Arithmetic:** `+`, `-`, `*`, `/`
* **Relational:** `==` (equal to), `!=` (not equal to), `<`, `>`, `<=`, `>=`
* **Logical:** `AND`, `OR`, `NOT`

> **Note:** Some operators are additionally overloaded for Audio types. For more information, read [Audio Engine Documentation](./audio.md)

---

## 4. Type Conversions  and Rules
The language supports both explicit and implicit type conversions.

### Implicit Conversions
Implicit conversions happen automatically in the background whenever the context requires it — most notably during variable assignments (e.g., assigning a `NUMERICAL` to an `INT` variable), passing arguments to functions, or evaluating mathematical/logical expressions.

Tøn will perform the following conversions implicitly:
* `INT` -> `NUMERICAL` *(type promotion - converts an integer to a floating-point number)*
* `NUMERICAL` -> `INT` *(type demotion - performs **truncation** of the decimal part)*
* `INT/NUMERICAL` -> `BOOL` *(evaluates to **FALSE** when number is exactly **0 / 0.0**, and **TRUE** otherwise)*
* `BOOL` -> `INT/NUMERICAL` -> *(evaluates **0 / 0.0** when **FALSE** and **1 / 1.0** when **TRUE** to the number)*

### Explicit Conversions
Additionaly, the language provides **cast** operator: `<NEW_TYPE>expression`. It can be used to manually force any of the implicit conversions mentioned above, and also to perform the following:

* `<CHAR> STRING` *(works only when given `STRING` has a length of exactly 1)*
* `<STRING> CHAR` *(creates a `STRING` of size one with the given `CHAR`)*
* `<STRING> INT/NUMERICAL` *(constructs a `STRING` representation of the given number)*
* `<INT/NUMERICAL> STRING` *(creates a number from a given `STRING`)*

> **Note:** `STRING` -> `INT/NUMERICAL` conversion will succeed only if the given `STRING` contains a valid number. Otherwise, the interpreter will produce a runtime error.

### Casting in Practice

To explicitly cast a value from one type to another, place the target type inside angle brackets `< >` directly before the expression or variable.

Here is a short example demonstrating both implicit and explicit conversions in action:
```ton
$ Implicit conversion (INT is automatically promoted to NUMERICAL)
!make NUMERICAL myNumber <- 42;

$ Explicitly casting a NUMERICAL to a STRING
!make STRING textNumber <- "34";
!make INT number <- <INT>textNumber;

$ 3. Explicitly casting a NUMERICAL down to an INT (truncates decimals)
!make NUMERICAL price <- 19.99;
!make INT flatPrice <- <INT>price;

!shout number; $ output: 34
!shout flatPrice;  $ output: 19
```
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

$ Loop with a custom step using BY
!loop <INT i FROM 10 TO 0 BY -2> {
    !shout i; $ Outputs: 10, 8, 6, 4, 2, 0
}

$ Loop with previously declared variable
!make INT a <- 3;
!loop <a FROM 2 TO 54> {
}
!shout a;    $ Outputs: 54

$ Foreach Loop: Iterate directly over an ARRAY
!make ARRAY playlist <- [10, 20, 30];
!loop <INT item <- playlist> {
    !shout item; $ Iterates through every element in 'playlist'
}
```

### Lifecycle of Loop Arguments
When you declare an iterator or a variable directly inside the angle brackets of a `!loop` statement (e.g., `INT i` in a `FROM ... TO` loop), that variable is bound **strictly** to the loop's internal scope. 

It is born when the loop starts and completely destroyed the moment the loop finishes its execution. You cannot access or shout a loop iterator from outside of its block.

```text
!loop <INT i FROM 1 TO 3> {
    !shout i; $ Outputs: 1, 2, 3
}
$ !shout i; <-- THIS WOULD CAUSE AN ERROR: Variable 'i' is not defined.

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
1. **Value-Returning Functions** (`INT`, `SOUND`, `STRING`, etc.): May be used as part of an expression (e.g., assigned to a variable or used in a mathematical equation) or called as standalone statements.
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

### Parent Scope Access (`ELDER::`)
By default, if a variable is shadowed by a local variable with the same name, or if you need explicit access to a variable defined in a higher enclosing block, you can use the `ELDER::` prefix. Every `ELDER::` moves one level up in the memory tree.

```text
!make INT x <- 100;
{
    !make INT x <- 5;
    !shout x;          $ Outputs: 5 (local)
    !shout ELDER::x;   $ Outputs: 100 (from the parent block)
    
    ELDER::x <- 999;   $ Modifies the global variable!
}
```

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

### Good Practice Advise

If you are generating complex, multi-layered sounds (like bouncing multiple synths together before placing them on a track), it is highly recommended to do so inside **Anonymous Blocks**. This ensures that the intermediate, temporary audio files are deleted from your RAM immediately after they are mixed into the final variable, preventing your script from crashing due to memory limits.

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

#### Retrieving String Length
Tøn provides `LENGTH` operator which can be used on `ARRAY` object and returns a positive `INT` number.
```
!make STRING x <- "May the force be with you";
!make INT x_len <- LENGTH x;
!shout x_len;
$ prints 25
```

### Arrays (`ARRAY`)

Arrays are collections of items grouped together under a single variable name. They are defined using square brackets `[ ]` with elements separated by commas.

#### Creation and Assignment
You can create an array of numbers, notes, or even sounds.

```text
!make ARRAY sequence <- [1, 2, 3, 4];
!make ARRAY notes <- [C4, E4, G4];

```
#### Retrieving Array Length
Tøn provides `LENGTH` operator which can be used on `ARRAY` object and returns a positive `INT` number.
```
!make ARRAY x <- ["may", "the", "force", "be", "with", "you"];
!make INT x_len <- LENGTH x;
!shout x_len;
$ prints 6
```

#### Array Indexing & Slicing
Tøn provides a robust syntax for accessing elements within an `ARRAY` using square brackets `[]`.

**Indexing (`array[index]`)**
Retrieves a single element. Arrays are 0-indexed. Negative indices count backwards from the end of the array (e.g., `-1` is the last element). Requesting an out-of-bounds index is strict and will throw a runtime error.

```text
!make ARRAY nums <- [10, 20, 30];
!make INT first <- nums[0];  $ Returns 10
!make INT last <- nums[-1];  $ Returns 30
```
**Slicing (array[start:end])**
Extracts a sub-array starting at the start index up to, but not including, the end index. Unlike indexing, slicing is highly forgiving: out-of-bounds ranges are safely clamped to the array's limits, and logically invalid ranges simply return an empty array without crashing the execution.

```text
!make ARRAY sub <- nums[0:2];    $ Returns [10, 20]
!make ARRAY safe <- nums[1:100]; $ Returns [20, 30] (Safely clamped)
```
### Dynamic Array Operations
Tøn allows you to modify the contents of an `ARRAY` dynamically during execution using specific domain keywords.

* **`APPEND <expr> TO <array>`**: Adds a new element to the end of the specified array.
* **`POP <array>`**: Removes the last element from the array and returns it. Because it returns a value, `POP` must be used as part of an expression (e.g., assigned to a variable).
* **`CLEAR <array>`**: Completely empties the array, removing all its elements.

```text
!make ARRAY playlist <- ["Track A", "Track B"];

$ Add a new element
APPEND "Track C" TO playlist;  

$ Remove and capture the last element
!make STRING lastSong <- POP playlist;  $ Returns "Track C"

$ Empty the array
CLEAR playlist;  $ playlist is now [ ]
```



