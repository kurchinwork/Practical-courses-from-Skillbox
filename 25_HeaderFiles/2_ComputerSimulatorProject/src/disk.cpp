//
// Created by kurchin_iu on 16.03.2026.
//

//функция которая считывает или записывает числа в файл
#include "simComp.h"
#include <fstream>
#include <iostream>

using namespace std;

void saveFunc () {
    if (sim.status.ram == true) {
        string fileName = "";

        cout << "\nEnter name file:"; cin >> fileName;
        fileName = "../temp/" + fileName + ".txt";

        ofstream fileForSave(fileName);

        if (!fileForSave.is_open()) {
            cout << "\nThe file could not be saved.";
        } else {
            for (int i = 0; i < sim.buffer.size(); i++) {
                fileForSave << sim.buffer[i];  // записываем число
                if (i < sim.buffer.size() - 1) {
                    fileForSave << " ";  // пробел между числами кроме последнего
                }
            }
            fileForSave.close();
            sim.status.save = true; // флаг что сохранение прошло


        }
        if (sim.status.save) {
            cout << "\nFile with name :" << fileName << " be saved!";
        } else {
            cout << "\n!!!File with name :" << fileName << " NOT be  saved!!!";
        }
    }
}
void loadFunc () {
    if (sim.status.ram == true) {
        ramClear();
        cout << "\nThe buffer has been cleared.";
        sim.status.ram == false;
    }

    string fileName = "";
    cout << "\nEnter name file:"; cin >> fileName;
    fileName = "../temp/" + fileName + ".txt";

    ifstream fileForLoad(fileName);
    if (!fileForLoad.is_open()) {
        cout << "Error opening file! Possibly invalid name!";
    } else {
        int num;
        while (fileForLoad >> num) {
            sim.buffer.push_back(num);
        }
        fileForLoad.close();

        cout << "\nData from file be read successfully";

        sim.status.ram = true;
    }
}

