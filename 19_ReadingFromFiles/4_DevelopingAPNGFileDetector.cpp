//
// Created by kurch on 05.02.2026.
//
#include <iostream>
#include <fstream>
using namespace std;

void mainTask (ifstream &initFile) {
    char checkBytes[4];
    if (initFile.read(checkBytes, 4)) {
        if (checkBytes[0] == -119 &&
            checkBytes[1] == 'P' &&
            checkBytes[2] == 'N' &&
            checkBytes[3] == 'G') {
            cout << "\nFile is PNG format!";
        } else {
            cout << "\nFile is not PNG format!";
        }
    }
}

int main() {
    string insertTrackToFile = " ";
    cout << "\nPaste the path to the file, remember the double'\\':"; cin >> insertTrackToFile;
    ifstream inputFile (insertTrackToFile, ios::binary);
    //ifstream inputFile ("FilesForTask_4\\test.png", ios::binary);
    if (inputFile.is_open()) {
        cout << "***The file has been successfully connected***" << endl;
        mainTask(inputFile);
    } else {
        cout << "\nThe file has been failed.";
        return 1;
    }

    return 0;
}