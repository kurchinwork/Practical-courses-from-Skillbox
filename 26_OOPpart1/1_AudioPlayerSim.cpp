//
// Created by kurchin_iu on 17.03.2026.
//
#include <iostream>
#include <vector>

using namespace std;

class MusicTrack {
    public:
    string nameTrack = "",
           artistTrack = "";
    int trackLength = 0;
};

class AudioPlayerSim {
    public:
    vector<vector <string>> CDdisk;
    vector<MusicTrack> tracks;

    void initializeTracks(MusicTrack Track) {
        tracks.push_back(Track.nameTrack);
        tracks.push_back(Track.artistTrack);
        tracks.push_back(Track.trackLength);

    }

    void play(MusicTrack Track) {
        cout << "\nNow playing: " << Track.nameTrack <<
                "\nArtist track: " << Track.artistTrack <<
                "\nDuration:" << Track.trackLength;
    };
    void stop() {

    }
    void pause() {

    }
    void resume() {

    }
};



int main() {

    return 0;
}