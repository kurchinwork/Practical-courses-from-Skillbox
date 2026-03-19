//
// Created by kurchin_iu on 17.03.2026.
//
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class CDdisk {

private:
    struct Track{

        string nameTrack = "Unknown",
               artistTrack = "Unknown artist";
        int trackLength = 0;

        Track (string nmTrck, string artstTrck, int trckLnght) {
        nameTrack = nmTrck;
        artistTrack = artstTrck;
        trackLength = trckLnght;
        }
    };
    vector<Track> AllTracks;

public:
    //метод добавление треков на диск
    void addTrack(string nameTrack, string artistTrack, int trackLength) {
        AllTracks.push_back(Track(nameTrack, artistTrack, trackLength));
    }

    //метод вывода всех треков с диска
    void outAllTracksOnCD() {
        if (AllTracks.empty()) {
            cout << "\nCD disk with tracks is empty";
            return;
        }
        else {
            cout << "\nCD disk with "<< AllTracks.size() <<" tracks is:";
            for (int i =0; i < AllTracks.size(); i++) {
                cout << "\nTrack #"<< i + 1 << " "<<AllTracks[i].nameTrack
                     << "\nArtist:  " << AllTracks[i].artistTrack
                     << "\nDuration: " << AllTracks[i].trackLength << " sec. "<<endl;
            }
        }
    }

    int getSizePlaylist () {
        return AllTracks.size();
    }
    void getTrack(int i) {
        cout << "\nTrack #"<< i + 1 << " "<<AllTracks[i].nameTrack
             << "\nArtist:  " << AllTracks[i].artistTrack
             << "\nDuration: " << AllTracks[i].trackLength << " sec. "<<endl;
    }
};

class CDPlayer {
    private:
    bool playing = false;
    bool stop = false;
    bool pause = false;

    int indexTrack = 0;
    CDdisk* currentDisk = nullptr;

public:
    void setDisk(CDdisk* disk) {
        currentDisk = disk;
    }
    void autoSelectTrack() {
        if (currentDisk->getSizePlaylist() == 0) {
            cout << "\nNo tracks on disk!" << endl;
            return;
        } else {
            int index = rand() % currentDisk->getSizePlaylist();
            indexTrack = index;
            currentDisk->getTrack(index);
        }

    }
    void play() {
        if (playing == false) {
            playing = true;
            stop = false;
            cout << "\nPlaying..." << endl;
            autoSelectTrack();
        } else {
            cout << "\nThe song is playing";
            currentDisk->getTrack(indexTrack);
        }
    }

    void paused() {
    if (!playing && !pause) {
            cout << "\nPlay the song first";
        } else if (playing) {
            pause = true;
            playing = false;
            cout << "\nPaused..." << endl;
        } else {
            cout << "\nContinuing..";
            pause = false;
            playing = true;
            currentDisk->getTrack(indexTrack);
        }
    }
    void next() {
        playing = true;
        pause = false;
        stop = false;
        cout << "\nPlaying..." << endl;
        autoSelectTrack();
    }
    void stoped() {
        playing = false;
        pause = false;
        stop = true;
        cout << "\nPlaying is stopped" << endl;
    }
};

void initListTrack(CDdisk &disk) {
    disk.addTrack("2007", "pxdxlsky, alxmxv, rxdxmir, steshaa", 122);
    disk.addTrack("Never Broke Again", "xxxmanera", 108);
    disk.addTrack("Vielleicht Vielleicht", "MilleniumKid, JBS, Holy Priest, itgmq Hardstyle", 161);
    disk.addTrack("nightvision", "lannarie", 118);
    disk.addTrack("MAMA MA - INSTRUMENTAL Slowed", "SXLLX", 90);
    disk.addTrack("ON THE VERGE", "TEENWXVE", 90);
}
void listCommands() {
    cout << "\nEnter command: "
        "\n~album - for out list all track;"
        "\n~play - for start play music;"
        "\n~pause - for pause music and continue;"
        "\n~next - for next music;"
        "\n~stop - for stop music;"
        "\n```````````````````````"
        "\n~command - for list all all commands Adio player;"
        "\n~exit - for exit Adio player." << endl;
}


int main() {
    srand(time(NULL));
    CDdisk disk;
    CDPlayer player;
    player.setDisk(&disk);

    initListTrack(disk);
    cout << "\nThe music disk has been successfully connected." << endl;

    string command = "";
    listCommands();
    do {
        cout << "\nEnter command: ";
        cin >> command;
        if (command == "album") {
            disk.outAllTracksOnCD();
        } else if (command == "play") {
            player.play();
        } else if (command == "pause") {
            player.paused();
        } else if (command == "next") {
            player.next();
        } else if (command == "stop") {
            player.stoped();
        } else if (command == "commands") {
            listCommands();
        } else if (command != "exit") {
            cout << "\nInvalid command entered."
                    "\nTry again" << endl;
        }
    } while (command != "exit");

    return 0;
}
