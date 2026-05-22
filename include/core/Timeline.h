#pragma once
#include "MusicBase.h"
#include <vector>
#include <string>
#include <map>

struct TrackEvent {
    Sound sound;
    int startTimeMs;
    std::string alias;
};

struct Track {
    std::string name;
    std::vector<TrackEvent> events;
    bool isMuted = false;
};

struct Timeline {
    std::string name;
    std::unordered_map<std::string, Track> tracks;


    Sound renderFinalSound() const {
        Sound resultSound;
        int maxSamples = Sound::sampleRate;

        for (const auto& [trackName, track] : tracks) {
            if (track.isMuted) {
                continue;
            }
            for (const auto& ev : track.events) {
                int endSample = (ev.startTimeMs / 1000.0) * Sound::sampleRate + ev.sound.samples.size();
                if (endSample > maxSamples) {
                    maxSamples = endSample;
                }
            }
        }

        resultSound.samples.assign(maxSamples, 0.0f);

        for (const auto& [trackName, track] : tracks) {
            if (track.isMuted) {
                continue;
            }
            for (const auto& ev : track.events) {
                int startSample = (ev.startTimeMs / 1000.0) * Sound::sampleRate;
                for (size_t i = 0; i < ev.sound.samples.size(); ++i) {
                    resultSound.samples[startSample + i] += ev.sound.samples[i];
                }
            }
        }
        return resultSound;
    }
};
