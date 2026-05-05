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
    std::map<std::string, Track> tracks;
};
