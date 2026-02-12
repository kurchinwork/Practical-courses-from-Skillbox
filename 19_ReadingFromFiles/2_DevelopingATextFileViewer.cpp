//
// Created by kurch on 04.02.2026.
//
#include <fstream>
#include <iostream>

using namespace std;

void mainTask (ifstream &inputFile) {

    inputFile.seekg(0, ios::end);
    streampos fileSize = inputFile.tellg();
    inputFile.seekg(0, ios::beg);

    int fileSized = fileSize;

    string lineInFile;
    if (fileSized >= 500) {
        int sizeForRead = 0;
        cout << "\nFile size: " << fileSized << " byte."
                                                        "\nFiles larger than 500 bytes are not read automatically.";
        while (sizeForRead <= 0) {
            cout << "\nEnter the size of the file to read:";
            cin >> sizeForRead;

            if (sizeForRead <= 0) {
                cout << "\nThe value must not be less than or equal to 0!";
            }
        } //контроль ввода, вводим сколько бит хотим пррочитаь
        string lineInFile;
        long long totalRead = 0;

        while (totalRead < sizeForRead && getline(inputFile, lineInFile)) {
            cout << lineInFile << endl;
            totalRead += lineInFile.size() + 1; // +1 для символа новой строки
            // Если строка была пустой, getline не добавляет \n в lineInFile
            if (inputFile.eof() && !inputFile.fail()) {
                totalRead++; // Компенсируем отсутствие \n в последней строке
            }
        }
    } else {
        cout << "\nFile contents:\n\n";
        while (getline (inputFile, lineInFile)) {
            cout << lineInFile << endl;
        }
    }
}


int main () {
    ifstream fileForRead("FilesForTask_2\\textForTest.txt", ios::binary);
    if (fileForRead.is_open()) {
        cout << "\n***The file has been successfully connected***\n";
        mainTask(fileForRead);
    } else {
        cout << "\nThe file has been failed.";
        return 1;
    }

    fileForRead.close();
    return 0;
}