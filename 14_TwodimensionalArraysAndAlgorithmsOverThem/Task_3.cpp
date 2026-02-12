//
// Created by kurch on 16.01.2026.
//

#include <iostream>
#include <cstdlib>

using namespace std;

void verifMx (int mxA[4][4], int mxB[4][4]) {
    cout << "The equality of matrices is checked...\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (mxA[i][j] != mxB[i][j]) {
                cout << "The matrices are not equal!\n";
                exit(1);
            }
        }
    }
    cout << "Test passed\n";
}
void diagonalMx (int mxA[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i != j) {
                mxA[i][j] = 0;
            }
        }
    }
}
void outArray(int mxA[4][4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << mxA[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    //Стиль ввода для задания
/*
    int mxA[4][4], mxB[4][4];
    cout << "Enter the elements of the matrix A:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mxA[i][j];
        }
    }

    cout << "Enter the elements of the matrix B:\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mxB[i][j];
        }
    }*/
    //Стиль ввода для облегчения задания
    int mxA[4][4] {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}};
    int mxB[4][4] {
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4},
        {1, 2, 3, 4}};

    verifMx (mxA, mxB);
    diagonalMx(mxA);
    outArray(mxA);
}