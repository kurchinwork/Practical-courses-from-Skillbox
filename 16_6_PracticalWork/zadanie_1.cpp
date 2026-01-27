//
// Created by kurch on 26.01.2026.
//
#include <iostream>
#include <cstdio>
using namespace std;

bool symbolForContinue () {
    char initialSymbol;
    cout << "\nY/n?:"; cin >> initialSymbol;
        if (initialSymbol == 'Y' || initialSymbol == 'y') {
            return true;
        } else if (initialSymbol == 'N' || initialSymbol == 'n') {
            return false;
        }
}

int main() {
    string speedString = "";
    float speedValue = 0,
          speedInit = 0;
    int countOperation = 0;

    cout << "This program need for print value speed. If you want stop program press 'n'\n";
    while (countOperation < 5) {
        char bufferSpeed [12];
        cout << "Ented a speed:";

        //Организовал проверку ввода
        if (!(cin >> speedInit)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        speedValue += speedInit;
        sprintf(bufferSpeed, "%.1f km/h", speedValue);
        speedString = bufferSpeed;
        cout << "Speed delta:= " << speedString << endl;

        countOperation++;
        if (countOperation == 5) {
            cout << "\nCount operation is ended!\nDo you want to repeat?\n";
            if (symbolForContinue())
                countOperation = 0;
        }
    }

    return 0; /*Обязательно ли добавлять возвращение 0 в каждой программе?
    Сейчас оставил для удобства чтобы видеть что программа корректно отработала*/
}
