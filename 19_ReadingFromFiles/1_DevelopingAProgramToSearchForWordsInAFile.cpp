//
// Created by kurch on 03.02.2026.
//
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void outVector (vector<string> &vecForOut) {
    cout << "\n\nFile contents:\n\n";
    for (int i= 0; i < vecForOut.size(); i++) {
        cout << vecForOut[i] << endl;
    }
}
void mainTask (ifstream &inputFile) {
        string readWordInFile; //переменная для текста из файла
        vector<string> textInFile;
        string wordForFind = "";

        while (inputFile >> readWordInFile) {
            textInFile.push_back(readWordInFile); //чтение из файла и добавление в конец
        }
        outVector(textInFile);

        cout << "\nEnter the word you want to find:"; cin >> wordForFind; cout << endl;

        int rptdWrds = 0;

        for (int i = 0; i < textInFile.size(); i++) {
            if (wordForFind == textInFile[i]) {
                rptdWrds++;
            }
        }
        cout << rptdWrds << endl;
        inputFile.close();
}

int main() {
    ifstream fileForRead("FilesForTask_1\\words.txt");

    if (fileForRead.is_open()) {
        cout << "\n***The file has been successfully connected***";
        mainTask(fileForRead);
    } else {
        cout << "\nThe file has been failed.";
        return 1;
    }

    return 0;
}