//
// Created by kurch on 09.02.2026.
//
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

string vectorToString(const vector<int>& vec) {
    stringstream ss;
    for (size_t i = 0; i < vec.size(); i++) {
        ss << vec[i];
        if (i != vec.size() - 1) {
            ss << " ";
        }
    }

    return ss.str();
}

void binaryArt (ofstream& fileForArt) {
    int wight = 0,
        hight = 0;

    cout << "Input a Wight:"; cin >> wight;
    cout << "Input a Hight:"; cin >> hight;


    for (int i = 0; i < hight; i++) {
        vector <int> lineForInsertToFile;
        string lineForInsertToFileStr;

        for (int j = 0; j < wight; j++) {
            int initRand = rand() % 2;
            lineForInsertToFile.push_back(initRand);
        }
        lineForInsertToFileStr = vectorToString (lineForInsertToFile);
        fileForArt << lineForInsertToFileStr << endl;
    }
}

int main () {
    srand(time(nullptr));

    ofstream fileArtTxt("FilesForTask_2\\art.txt");
    if (!fileArtTxt.is_open()) {
        cout << "\nThe file has been failed.";
        return 1;
    }
    cout << "\n***The file has been successfully connected***\n";
    while (true) {
        binaryArt(fileArtTxt);
        cout << "\nCompleted! Check the results file in the file browser."
                "\nDo you wanna try again? (input 1 for accept, another symbol for exit):";
        int choice;
        cin >> choice;

        if (choice != 1) {
            cout << "\nProgram as terminate...";
            return 0;
        }
    }




    return 0;
}