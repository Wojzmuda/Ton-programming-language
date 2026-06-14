#pragma once
#include<string>
#include <vector>
#include "AudioFile.h"
#include <map>

enum class InstrumentType {
    SoundFont,
    RawSample, // For now we leave that
    Synth      // Built-in synth function (eg Sine Wave)
};

class Instrument {
private:
    std::string name;

    InstrumentType type;

    std::vector<double> sampleData;

    // something for SoundFont (?)
    int midiPresetIndex = -1;

public:
    Instrument(std::string n) : name{n}, type{InstrumentType::Synth} {}

    Instrument(std::string n, int preset) : name{n}, type{InstrumentType::SoundFont}, midiPresetIndex{preset} {}

    Instrument(std::string n, std::string filePath) : name(n) {
        AudioFile<double> audioFile;
        if (audioFile.load(filePath)) {
            sampleData = audioFile.samples[0];
            std::cout << ">>> [SYSTEM] Loaded sample for " << name << " (" << sampleData.size() << " samples)\n";
        } else {
            std::cerr << ">>> [ERROR] Could not load sample: " << filePath << "\n";
        }
    }

    inline std::string getName() const {
        return this->name;
    }
    inline InstrumentType getType() const {
        return this->type;
    }
    inline int getMidiPresetIndex() const {
        return this->midiPresetIndex;
    }
};


struct Note {
    std::string pitchClass; 
    int octave;

    Note(std::string p, int o) {
        pitchClass = p;
        octave = o;
    }
    
    Note() {
        pitchClass = "C";
        octave = 4;
    }
    inline static const std::map<std::string, int> pitchToSemitone = {
        {"C", -9}, {"C#", -8}, {"Db", -8}, {"D", -7}, {"D#", -6}, {"Eb", -6},
        {"E", -5}, {"F", -4}, {"F#", -3}, {"Gb", -3}, {"G", -2}, {"G#", -1},
        {"Ab", -1}, {"A", 0}, {"A#", 1}, {"Bb", 1}, {"B", 2}
    };

    int getOffsetFromA4() const {
        int semitoneOffset = 0;
        auto it = pitchToSemitone.find(pitchClass);
        if (it != pitchToSemitone.end()) {
            semitoneOffset = it->second;
        }

        int octaveOffset = (octave - 4) * 12;
        return semitoneOffset + octaveOffset;
    }

    double getFrequency() const {
        return 440.0 * std::pow(2.0, getOffsetFromA4() / 12.0);
    }

    int toMidiNumber() const {
        // Nuta A4 to w standardzie MIDI numer 69.
        // Środkowe C4 to numer 60 (69 - 9).
        return 69 + getOffsetFromA4();
    }
};


class Sound {
public:
    std::vector<float> samples;

    void generateSineWave(Note note, int durationMs) {
        samples.clear();
        int totalSamples = (durationMs / 1000.0) * sampleRate;
        samples.reserve(totalSamples);
        for (int i = 0; i < totalSamples; ++i) {
            double time = (double)i / sampleRate;
            double sampleValue = std::sin(2.0 * M_PI * note.getFrequency() * time);
            samples.push_back(sampleValue);
        }
    }
    void generateSawWave(Note note, int durationMs) {
        // TODO
        samples.clear();
        return;
    }
    void generateSquareWave(Note note, int durationMs) {
        // TODO
        samples.clear();
        return;
    }

public:
    static constexpr int sampleRate = 44100;
    void generateSynthWave(std::string synthName, Note note, int durationMs) {
        if (synthName == "sine") {
            this->generateSineWave(note, durationMs);
        }
        else if (synthName == "saw") {
            this->generateSawWave(note, durationMs);
        }
        else if (synthName == "square") {
            this->generateSawWave(note, durationMs);
        }
        else {
            throw std::runtime_error("no such synth");
        }
    }

    float getLargestValue() const {
        float maxValue = 0;
        for (const auto& val : samples) {
            float currentValue = std::abs(val);
            if (currentValue > maxValue) {
                maxValue = currentValue;
            }
        }
        return maxValue;
    }

    void normalize() {
        float value = this->getLargestValue();
        if (value > 0.0f && value != 1.0f) {
            for (auto& x : samples) {
                x /= value;
            }
        }
    }

    Sound operator*(double multiplier) const {
        Sound amplifiedSound;
        amplifiedSound.samples.reserve(this->samples.size());
        for (float val : this->samples) {
            amplifiedSound.samples.push_back(static_cast<float>(val * multiplier));
        }
        return amplifiedSound;
    }

    Sound() {}
};

inline Sound operator*(double multiplier, const Sound& sound) {
    return sound.operator*(multiplier);
}


