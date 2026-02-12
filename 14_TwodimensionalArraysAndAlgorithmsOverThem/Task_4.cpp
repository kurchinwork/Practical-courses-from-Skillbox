//
// Created by kurch on 16.01.2026.
//
#include <iostream>
using namespace std;
int main() {
    //Стиль ввода для задания
    /*
        int mxA[4][4], mxB[4], mxC[4];
        cout << "Enter the elements of the matrix A:\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> mxA[i][j];
            }
        }

        cout << "Enter the elements of the matrix B:\n";
        for (int i = 0; i < 4; i++) {
                cin >> mxB[i];
            }
        }*/
    //Стиль ввода для облегчения задания
    int mxA[4][4] {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}};

    int mxB[4] {1, 2, 3 ,4};
    int mxC[4] {0, 0, 0, 0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mxC[i] += mxA[i][j] * mxB[j];
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << mxC[i] << endl;
    }
}