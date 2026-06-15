# Tøn Language: Audio Construction & Manipulation

Tøn is a Generative Arithmetic Music Language that allows you to script, mix, and manipulate musical events, designed to compile directly into digitally generated audio. This document covers the domain-specific types, timeline structures, and operators used to construct and edit audio.

---


## 1. The `USE` Keyword & Instrument Selection

The `USE` is used to load an instrument from SoundFont base. (For detailed setup, please visit [setup.md](./setup.md) file).
When you declare an instrument you will be able to use it when creating a `SOUND`.

#### There are following instruments available:
- `piano` - *YAMAHA GRAND PIANO*
- `organ` - *CHURCH ORGAN*
- `rock_organ` - *ROCK ORGAN*
- `guitar` - *NYLON STRING GUITAR*
- `overdrive` - *OVERDRIVE GUITAR*
- `bass` - *FINGERED BASS*
- `violin` - *VIOLIN*
- `cello` - *CELLO*
- `contrabass` - *CONTRABASS*
- `strings` - *STRINGS*
- `trumpet` - *TRUMPET*
- `flute` - *FLUTE*
- `drums` - *TAIKO DRUM*

Besides, when creating a `SOUND` you can always use synthetic sounds that are built into the language architecture (no `USE` statement required).
#### There are following synths available:
- `sine` - *SINE WAVE*
- `saw` - *SAW-SHAPED WAVE*
- `square` - *SQUARE-SHAPED WAVE*

## 2. Basic Music-Oriented Data Types


####  **NOTE**: 
Represents a musical note's frequency.
* **Note Notation Anatomy**: Literal notes in Tøn follow the International Pitch Notation (SPN) standard, combining a pitch name and an octave number. For example, in the note `C5`, the letter **`C`** represents the musical pitch (the note itself), while the number **`5`** represents the specific octave.
* **Sharps and Flats**: Tøn supports both sharp and flat accidentals placed immediately after the pitch letter. Sharps are denoted by the `#` symbol (e.g., `F#5` represents an F-sharp in the 5th octave), and flats are denoted by the `b` (lowercase B) symbol (e.g., `Fb5` or `Bb4`).

####  **SOUND**: 
Represents a single sound with a specific frequency, duration and instrument/synth.

To construct a `SOUND`, first specify the instrument or synth type followed by a `NOTE` object and duration (in milliseconds).

```text
USE PIANO;
!make SOUND melody_note <- sine C4 500; $ Creates a Sine Wave sound,
lasting 500ms, at C4 frequency

!make SOUND retro_beep <- piano E5 150;  $ Creates a Piano sound,
lasting 150ms, at E5 frequency
```


#### **TIMELINE**: 
The main timeline of the entire musical track, grouping individual `TRACK` elements.
#### **TRACK**: 
A single layer within a `TIMELINE` used to place `SOUND` objects at specific times.

---


## 3. Audio Construction & Timelines

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

---

## 4. Audio-Specific Operators

Tøn supports overloaded operators designed specifically for audio manipulation:

* **`+` (Mix)** : When applied to `SOUND` or `TRACK` objects, it overlays their audio waves, playing them simultaneously.
* **`&` (Concat)** : Glues two `SOUND` objects sequentially, making the second sound play immediately after the first one finishes.

---


## 6. Audio Manipulation Operators
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

## 7. Exporting and Playback

To compile and save your final composition as a `.wav` file (with a polyphonic mix of all tracks), use the `!save` command.

```text
!save mySong "path/to/hit_song.wav";

```

---

## 8. Complete Audio Example

Here is a full example script generating a simple track:

```text
USE PIANO;

!shout "Generowanie utworu...";

$ Create sounds
!make SOUND bas <- sine C2 2000;
!make SOUND nuta <- piano E4 250;

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