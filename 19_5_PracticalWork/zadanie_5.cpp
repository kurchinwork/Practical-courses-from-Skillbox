//
// Created by kurch on 05.02.2026.
//
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int gameScoreUser = 0,
    gameScorePC = 0;

int offsetFunc(int &initOffset) {
    vector<int> sectorList = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    static vector<int> usedSectors; // использованные сектора

    // Корректируем offset
    while (initOffset > 13)
        initOffset -= 13;
    if (initOffset == 0)
        initOffset = 13;
    int sector = initOffset;

    // Ищем свободный сектор
    while (find(usedSectors.begin(), usedSectors.end(), sector) != usedSectors.end()) {
        sector++; // пробуем следующий
        if (sector > 13)
            sector = 1;
        if (usedSectors.size() >= 13) {
            sector = 0; // все сектора использованы
            break;
        }
    }
    // Добавляем в использованные
    if (sector >= 1 && sector <= 13) {
        usedSectors.push_back(sector);
    }

    return sector;
}
void gameTitle() {
    cout << "\n\n"
     "==================================================\n"
     "|                                                |\n"
     "|               WHAT? WHERE?? WHEN???            |\n"
     "|                                                |\n"
     "==================================================\n\n"
     "                    Game Rules:\n"
     "--------------------------------------------------\n"
     "* You play against the computer over 6 rounds\n"
     "* You enter a number that determines the question\n"
     "* Correct answer = point for you\n"
     "* Wrong answer = point for computer\n"
     "* Answer must be: one word, lowercase, symbol\n"
     "--------------------------------------------------\n\n"
     "==================================================\n"
     "                    GOOD LUCK!\n"
     "==================================================\n\n";
}
void mainGameFunction(ifstream &questionFile, ifstream &askFile) {
    gameTitle();
    for (int stepGame = 1; stepGame <= 6; stepGame++) {
        int initOffset = -1;
        while (initOffset < 0) {
            cout << "\n~~~~~~~Round #" << stepGame <<
                "\n~Enter the roulette shift:"; cin >> initOffset;
            if (initOffset < 0)
                cout << "ONLY positive values!\n";
        } // контроль ввода

        int targetLineForQuesti = offsetFunc(initOffset), // строка вопроса которую надо отобразить
            currentLineQuesti = 1;
        std::string lineQuesti;

        while (std::getline(questionFile, lineQuesti)) {
            if (currentLineQuesti == targetLineForQuesti) {
                cout << lineQuesti << endl;
            }
            currentLineQuesti++;
        } // вывод вопроса

        string answerUser = " ";
        cout << "Enter your answer: "; cin >> answerUser;

        int targetLineForAsk = targetLineForQuesti, // строка ответа которую надо отобразить
        currentLineAsk = 1;
        std::string lineAsk;

        while (std::getline(askFile, lineAsk)) {
            if (currentLineAsk == targetLineForAsk) {
                cout << "Correct answer: " << lineAsk << endl;
            }
            currentLineAsk++;
        } // вывод ответа

        if (answerUser == lineAsk) {
            gameScoreUser++;
        } else {
            gameScorePC++;
        }
    }

}

int main() {
    cout << "\n~~Checking game fales...";
    ifstream questionFile ("FilesForTask_5\\questi.txt");
    ifstream askQuestionFile ("FilesForTask_5\\aski.txt");



    if (questionFile.is_open() && askQuestionFile.is_open()) {
        cout << "\n~~All is okay\n"
                "\nStarting game...\n";
        mainGameFunction(questionFile, askQuestionFile);

        cout << "\nScore:"
                "\n User: " << gameScoreUser <<
                "\n PC: " << gameScorePC;

        if (gameScoreUser > gameScorePC) {
            cout << "\nThe user has won!";
        } else {
            cout << "\nThe computer has won!"
                    "\nDon't be upset, try again.";
        }

        questionFile.close();
        askQuestionFile.close();
    } else {
        cout << "\nFiles is failed!"
                "\nExting...";
    }
}
