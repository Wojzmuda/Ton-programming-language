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
```
$ This is a comment
```

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
### Array Indexing & Slicing
Tøn provides a robust syntax for accessing elements within an `ARRAY` using square brackets `[]`.

**Indexing (`array[index]`)**
Retrieves a single element. Arrays are 0-indexed. Negative indices count backwards from the end of the array (e.g., `-1` is the last element). Requesting an out-of-bounds index is strict and will throw a runtime error.

```text
!make ARRAY nums <- [10, 20, 30];
!make INT first <- nums[0];  $ Returns 10
!make INT last <- nums[-1];  $ Returns 30
Slicing (array[start:end])
Extracts a sub-array starting at the start index up to, but not including, the end index. Unlike indexing, slicing is highly forgiving: out-of-bounds ranges are safely clamped to the array's limits, and logically invalid ranges simply return an empty array without crashing the execution.

```text
!make ARRAY sub <- nums[0:2];    $ Returns [10, 20]
!make ARRAY safe <- nums[1:100]; $ Returns [20, 30] (Safely clamped)

### Operators
Tøn supports standard programming operators for logic and math, as well as unique operators designed specifically for audio manipulation.

**Assignment Operators**
* `<-` : Standard assignment (e.g., `!make INT x <- 5;`).
* `+<-`, `-<-`, `*<-`, `/<-` : Compound assignment (modifies the existing variable, e.g., `x +<- 2;`).

**Arithmetic Operators**
* `+` : Addition.
* `-` : Subtraction.
* `*` : Multiplication.
* `/` : Division.

**Relational Operators**
* `==` : Equal to.
* `!=` : Not equal to.
* `<` : Less than.
* `>` : Greater than.
* `<=` : Less than or equal to.
* `>=` : Greater than or equal to.

**Logical Operators**
* `AND` : Logical AND (e.g., `TRUE AND FALSE`).
* `OR` : Logical OR.
* `NOT` : Logical NOT (e.g., `NOT TRUE`).

**Audio-Specific Operators**
* `+` (Mix) : When applied to `SOUND` or `TRACK` objects, it overlays their audio waves, playing them simultaneously.
* `&` (Concat) : Glues two audio objects sequentially, making the second sound play immediately after the first one finishes.
  
## 3. Audio Construction & Timelines

### Generating Sounds
You can generate a `SOUND` by using an instrument/synth, a note, and a duration (in milliseconds).

```text
!make SOUND bass <- synth C2 2000;
!make SOUND beep <- synth E4 250;
```

### Timelines and Tracks
To arrange music, you must create a `TIMELINE` and add `TRACK`s to it.

```text
!make TIMELINE mySong;
mySong NEW TRACK bassline;
mySong NEW TRACK melody;
```

### Placing Sounds on a Track (`AT`, `[]`)
Use Event Lists `[]` and the `AT` keyword to specify the exact millisecond a sound should play. Assigning multiple sounds to the same time (e.g., `AT 0`) automatically mixes their waves to create chords.

```text
mySong.bassline <- [bass AT 0, bass AT 2000];
```

### Tagging Sounds (`AS`)
Use `AS` to assign a unique label (alias) to a specific sound event so you can manipulate it later on the timeline.

```text
mySong.melody <- [beep AS "start" AT 0, beep AT 500];
```

## 4. Audio Manipulation Operators
Tøn provides domain-specific operators to manipulate tracks and objects on the timeline.

* **`SHIFT <target> BY <time>`**: Shifts a selected sound or track forward/backward by a given number of milliseconds. Used for creating broken rhythms, delays, or moving blocks.

    ```text
    SHIFT mySong.melody."start" BY 250;
    ```

* **`MOVE <target> TO <time>`**: Moves a selected object to an entirely new position on the timeline.

    ```text
    MOVE mySong.melody TO 5000;
    ```

* **`MUTE <target:target>`**: Mutes a specific track or segment.
* **`ISOLATE <target>`**: Acts as a "Solo" button. Mutes all other tracks within the project, rendering only the selected one.
* **`UNMUTE target | ALL`**: Reverts a mute or completely resets all isolations.
* **`TRASH <target:target>`**: Deletes a sound or cuts it within a specified range (Slicing and editing).
* **`PLAY <target>`**: Plays the generated project or track live.
* **`LENGTH <target>`**: Returns the total duration of a sound, track, timeline in ms and array, string in a number.
* **`DIVIDE <time>`**: Divides a sound into two parts at the given point in time.

### Arithmetic Mixing and Concatenation
* **Concatenation (`&`)**: Glues sounds together sequentially.
* **Mixing (`+`)**: Overlays audio waves on top of each other.

## 5. Control Flow
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
## 6. Functions & Scoping

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
In Tøn, curly braces `{ }` are not restricted just to functions or loops. You can place an anonymous block anywhere in your code to create a temporary, isolated environment. Variables created inside an anonymous block are destroyed as soon as the block ends, which is excellent for memory management during heavy audio synthesis.

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

### Scoping Rules (Dynamic Scoping)
Tøn utilizes **Dynamic Scoping**, which is a highly powerful and unique feature for a music scripting language. 

Unlike traditional languages (where a function only sees its own parameters), in Tøn, a function has access to the variables of **the environment from which it was called**. This means functions can act as intelligent, context-aware "macros".

**Example of Dynamic Scoping:**
```text
!define VOID play_contextual_bass <> {
    $ The function uses 'track_tempo' even though it was never passed as an argument!
    !make SOUND bass_hit <- synth C2 track_tempo;
    mySong.bassline <- [bass_hit AT 0];
}

{
    $ We set the context here
    !make INT track_tempo <- 500;
    !make TIMELINE mySong;
    mySong NEW TRACK bassline;
    
    $ When called, the function looks into THIS block for 'track_tempo' and 'mySong'
    play_contextual_bass(); 
}
```
*Note: While Dynamic Scoping offers great flexibility for musical scripting, be careful with variable naming to avoid unintentionally overwriting variables in the calling environment.*
## 7. Exporting
To compile and save your final composition as a `.wav` file (with a polyphonic mix of all tracks), use the `!save` command.

```text
!save mySong "hit_song.wav";
```

## 8. Complete Example
Here is a full example script generating a simple track:

```text
USE PIANO;

!shout "Generowanie utworu...";

$ Create sounds
!make SOUND bas <- synth C2 2000;
!make SOUND nuta <- synth E4 250;

$ Initialize timeline and tracks
!make TIMELINE utwor;
utwor NEW TRACK bassline;
utwor NEW TRACK melodia;

$ Place sounds on tracks
utwor.bassline <- [bas AT 0, bas AT 2000];
utwor.melodia <- [nuta AS "start" AT 0, nuta AT 500, nuta AT 1000];

$ Manipulate the timeline
SHIFT utwor.melodia."start" BY 250;

$ Export the result
!save utwor "hit.wav";
```
