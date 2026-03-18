//
// Created by kurchin_iu on 17.03.2026.
//
#include <iostream>
#include <vector>

using namespace std;

class MusicTrack {
    public:
    string nameTrack = "Unknown",
           artistTrack = "Unknown artist";
    int trackLength = 0;
};

class AudioPlayerSim {
public:
    vector<MusicTrack> playlist;
    bool stopped = false;
    bool isPlaying = false;


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
        if (playing) {
            cout << "\nStopping...";
        } else {
            cout << "\nNot a penny is lost";
        }
    }
    void pause() {
        if (playing) {
            cout << "\nPaused...";
        } else {
            cout << "\nPlaying...";
        }
    }
    void next() {

    }
};



int main() {

    return 0;
}