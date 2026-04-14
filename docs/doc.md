# Tøn Language Documentation

Tøn is a strongly typed, context-free programming language designed to compile directly into digitally generated audio rather than traditional text output. It is a Generative Arithmetic Music Language that allows you to script, mix, and manipulate musical events.

---

## 1. Core Concepts & Data Types

Tøn features standard programming types as well as specific domain types for music generation.

### Standard Types
* **`BOOL`**: Logical values (`TRUE` / `FALSE`).
* **`INT`**: Integers.
* **`NUMERICAL`**: Floating-point numbers for precise calculations.
* **`CHAR`**: Single characters (e.g., `'C'`).
* **`STRING`**: Text strings (e.g., `"Hello"`).
* **`ARRAY`**: Collections of elements (e.g., `INT[]`).
* **`VOID`**: Indicates no return type (used in functions).

### Domain Types (Audio)
* **`NOTE`**: Represents a musical note's frequency (e.g., `C4`, `F#5`).
* **`SOUND`**: A composite type representing a sound with a specific frequency and duration.
* **`INSTRUMENT`**: A loaded sample or generator (e.g., `SineWave`, `GUITAR`) used to synthesize a `SOUND`.
* **`TIMELINE`**: The main timeline of the entire musical track, grouping individual `TRACK` elements.
* **`TRACK`**: A single layer within a `TIMELINE` used to place `SOUND` objects at specific times.

---

## 2. Basic Syntax & Variables

### Comments
Use the `$` symbol for single-line comments.
```text
$ This is a comment