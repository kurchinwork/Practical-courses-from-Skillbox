//
// Created by kurch on 26.01.2026.
//
#include <iostream>
using namespace std;

bool symbolForContinue () {
    char initialSymbol;
    cout << "\nY/n?:"; cin >> initialSymbol;
        if (initialSymbol == 'Y' || initialSymbol == 'y')
            return true;
}

int main() {
    string speedString = "";
    float speedValue = 0;
    bool speedLogic = true;

    cout << "This program need for print value speed. If you want stop program press 'n'\n";
    while (speedLogic) {
        cout << "Ented a speed:"; cin >> speedValue;
        cout << "Speed delta:= " << sprintf(speedString, "%1f", speedValue) << endl;
        cout << "Do you want to continue?\n";
        if (!symbolForContinue())
            speedLogic = false;
    }
}
