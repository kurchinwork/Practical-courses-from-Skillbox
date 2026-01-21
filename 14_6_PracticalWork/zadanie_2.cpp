//
// Created by kurch on 16.01.2026.
//

#include <iostream>
using namespace std;

void outArray(char gamePlate[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << gamePlate[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int countRound = 0;
    char gamePlate[3][3] {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };

    cout << "Welcome to the classic game of tic-tac-toe!\n"
            "The first player starts the game with X\n";
    outArray(gamePlate);

    while (countRound < 9) {
        int stepPlayer_i, stepPlayer_j;
        bool approveInput = false;

        while (!approveInput) {

            //Ход первого игрока с проверкой ввода
            cout << "\nPlayer #1 make your choice [1-3?][1-3?]:"; cin >> stepPlayer_i >> stepPlayer_j; stepPlayer_i--; stepPlayer_j--;
            if (stepPlayer_i >= 0 && stepPlayer_i <= 2
                && stepPlayer_j >= 0 && stepPlayer_j <= 2
                && gamePlate[stepPlayer_i][stepPlayer_j] != 'O'
                && gamePlate[stepPlayer_i][stepPlayer_j] != 'X') {
                    gamePlate[stepPlayer_i][stepPlayer_j] = 'X';
                    approveInput = true;
                    ++countRound;
                    outArray(gamePlate);
            } else {
                cout << "The entered values are incorrect!\n"
                        "Player #1, please repeat your input.\n";
            }
        }
        //Проверка выигрышных позиций
        if ((gamePlate[0][0] == 'X' && gamePlate[0][1] == 'X' && gamePlate[0][2] == 'X') ||
            (gamePlate[1][0] == 'X' && gamePlate[1][1] == 'X' && gamePlate[1][2] == 'X') ||
            (gamePlate[2][0] == 'X' && gamePlate[2][1] == 'X' && gamePlate[2][2] == 'X') ||

            (gamePlate[0][0] == 'X' && gamePlate[1][0] == 'X' && gamePlate[2][0] == 'X') ||
            (gamePlate[0][1] == 'X' && gamePlate[1][1] == 'X' && gamePlate[2][1] == 'X') ||
            (gamePlate[0][2] == 'X' && gamePlate[1][2] == 'X' && gamePlate[2][2] == 'X') ||

            (gamePlate[0][0] == 'X' && gamePlate[1][1] == 'X' && gamePlate[2][2] == 'X') ||
            (gamePlate[0][2] == 'X' && gamePlate[1][1] == 'X' && gamePlate[2][0] == 'X'))

            {
            cout << "\nPlayer #1 is win. Congratulate!\n";
            break;
            }

        //Проверка на ничью
        if (countRound >= 9) {
            cout << "\nA draw is declared\n";
            break;
        }

        approveInput = false; //Обнуление условия
        //Ход второго игрока с проверкой ввода
        while (!approveInput) {
            cout << "\nPlayer #2 make your choice [1-3?][1-3?]:"; cin >> stepPlayer_i >> stepPlayer_j; stepPlayer_i--; stepPlayer_j--;
            if (stepPlayer_i >= 0 && stepPlayer_i <= 2
                && stepPlayer_j >= 0 && stepPlayer_j <= 2
                && gamePlate[stepPlayer_i][stepPlayer_j] != 'O'
                && gamePlate[stepPlayer_i][stepPlayer_j] != 'X') {
                gamePlate[stepPlayer_i][stepPlayer_j] = 'O';
                approveInput = true;
                ++countRound;
                outArray(gamePlate);
                } else {
                    cout << "The entered values are incorrect!\n"
                            "Player #2, please repeat your input.\n";
                }
        }

        //Проверка выигрышных позиций
        if ((gamePlate[0][0] == 'O' && gamePlate[0][1] == 'O' && gamePlate[0][2] == 'O') ||
            (gamePlate[1][0] == 'O' && gamePlate[1][1] == 'O' && gamePlate[1][2] == 'O') ||
            (gamePlate[2][0] == 'O' && gamePlate[2][1] == 'O' && gamePlate[2][2] == 'O') ||

            (gamePlate[0][0] == 'O' && gamePlate[1][0] == 'O' && gamePlate[2][0] == 'O') ||
            (gamePlate[0][1] == 'O' && gamePlate[1][1] == 'O' && gamePlate[2][1] == 'O') ||
            (gamePlate[0][2] == 'O' && gamePlate[1][2] == 'O' && gamePlate[2][2] == 'O') ||

            (gamePlate[0][0] == 'O' && gamePlate[1][1] == 'O' && gamePlate[2][2] == 'O') ||
            (gamePlate[0][2] == 'O' && gamePlate[1][1] == 'O' && gamePlate[2][0] == 'O'))
            {
            cout << "\nPlayer #2 is win. Congratulate!\n";
            break;
            }
    }
}