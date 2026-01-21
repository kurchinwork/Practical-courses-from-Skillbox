//
// Created by kurch on 19.01.2026.
//
#include <iostream>
using namespace std;

void outConditPimpl (bool arr[12][12]) {
    int coutPoopIsReal = 0;
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (arr[i][j] == true) {
                cout << 'O' << ' ';
            } else if (arr[i][j] == false) {
                cout << 'X' << ' ';
                coutPoopIsReal++;
            }
        }
        cout << endl;
    }
    cout << "Poop x" << coutPoopIsReal << endl;
}

bool chkPimpl(bool arr[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (arr[i][j] == true) {
                return true;
            }
        }
    } return false;
}


int main() {
    /*
    bool pipPoop [12][12] {
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},
        {true, true, true, true, true, true, true, true, true, true, true, true},};*/
    cout << "\nThe bubble wrap is absolutely intact!\n";
    bool pipPoop [12][12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            pipPoop[i][j] = true;
        }
    }

    outConditPimpl(pipPoop);

    while (chkPimpl(pipPoop)) {
        int begin_i, begin_j, end_i, end_j;

        //Проверка ввода
        while (true) {
            cout << "Start coordinates[?][?]:"; cin >> begin_i >> begin_j;
            cout << "End coordinates[?][?]:"; cin >> end_i >> end_j;
            if (begin_i >= 0 && begin_j >= 0 && begin_i <= end_i && begin_j <= end_j && end_i <= 12 && end_j <= 12)
                break;
            cout << "The coordinates were entered incorrectly.\n";
        }

        for (int i = begin_i; i < end_i; i++) {
            for (int j = begin_j; j < end_j; j++) {
                pipPoop[i][j] = false;
            }
        }

        outConditPimpl(pipPoop);
    }
}