#include <iostream>
#include <string>

using namespace std;

enum notes {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {
    string achord;
    int note = 0;

    cout << "Enter your achord from 0 to 7: ";
    cin >> achord;



    for (int i = 0; i < achord.length(); i++) {
        char currentSymbol = achord[i];
        int numbNote = currentSymbol - '0';

        if (achord[i] < '0' || achord[i] > '7') {
            cout  << "\nAs invalid element!: " << achord[i];
            return 1; // Для остановки программы так можно?
        }

        int noteMsk = 1 << (numbNote - 1);
        note = note | noteMsk;
    }

    cout << "\nNotes in chord: ";

    if (note & DO) {
        cout << "DO ";
    }
    if (note & RE) {
        cout << "RE ";
    }
    if (note & MI) {
        cout << "MI ";
    }
    if (note & FA) {
        cout << "FA ";
    }
    if (note & SOL) {
        cout << "SOL ";
    }
    if (note & LA) {
        cout << "LA ";
    }
    if (note & SI) {
        cout << "SI ";
    }

    return 0;
}