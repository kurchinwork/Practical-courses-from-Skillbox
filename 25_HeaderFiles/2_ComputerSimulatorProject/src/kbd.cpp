//
// Created by kurchin_iu on 16.03.2026.
//
//функция позволяющая ввести данные в буфер

#include <string>
#include <iostream>
#include <limits>
#include "simComp.h"

using namespace std;

void kbrd() {
    if (sim.status.ram == true) {
        cout << "\nThere is data in memory, please save it first before entering new data.";
    } else {
        cout << "\nKeyBoard is run" << endl;

        int num_i = 0;
        cout << "\nEnter a 8 num:" << endl;
        for (int i = 0; i < 8; i++) {
            cout << "#" << i + 1 << " :";

            //ввалидация ввода
            while (!(cin >> num_i)) {
                cin.clear();                                         // сбрасываем флаг ошибки
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем буфер
                cout << "Error! Enter integer: #" << i + 1 << " :";
            }

            ramInsert(num_i);
            sim.status.ram = true;
        }
        cout << "\nKeyBoard is done" << endl;
    }

}