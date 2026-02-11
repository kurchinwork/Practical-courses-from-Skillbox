//
// Created by kurch on 10.02.2026.
//
#include <fstream>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string initListFish = "FilesForTask_3\\initListFish.txt",
       savedFishInCart = "FilesForTask_3\\cart.txt";

void gameTitle () {
    cout << "\n~~~~~~~~~~~~~ Welcome ~~~~~~~~~~~~~"
            "\n                to                 "
            "\n      Fishing in the C++ River     "
            "\n~~~~~~~~~~~~~ !!!!!!! ~~~~~~~~~~~~~" << endl;
    cout << "\nList of fish living in the river:"
            "\nPike"
            "\nCarp"
            "\nPerch"
            "\nBream"
            "\nZander"
            "\nRoach"
            "\nCatfish" << endl;
    cout << "\nYou need to enter the name of the fish you want to catch and there is a chance you will catch it."
            "\nOnly a certain number of fish can fit in the net."
            "\nYou have 5 attempts to go out into the river in a boat to catch the fish of your dreams!";
}
void outFileContent (string& adressFile) {
    ifstream fileToOutput (adressFile);
    string lineForReading;
    if (fileToOutput.is_open()) {
        fileToOutput >> lineForReading;
        while (getline (fileToOutput, lineForReading)) {
            cout << lineForReading << endl;
        }
    }
    else {
        cout << "\nCritical error, programm files is damage!"
                "\nTerminating program.";
        exit (-1);
    }
    fileToOutput.close();
}
void saveInit (string& fishDropToCart, string& savedFiles) {
    ofstream savedProgress (savedFiles, ios::app);
    if (savedProgress.is_open()) {
        savedProgress << fishDropToCart << endl;
    }
    savedProgress.close ();
}
bool checkFileExists (string& fileName) {
    ifstream file (fileName);
    if (file.is_open()) {
        return 1;
    } else {
        return 0;
    }
}
bool checkUserInput (string& userInput) {
    for (char& c : userInput) {
        if (c < 'a' || c > 'z')
            return false;
    }
    return true;
}
void gameLogicCheckFishInList(string& findFishInList) {
    srand(time(nullptr)); //ловля рыб с шансом 50/50 думал уменьшить шанс путем сравнения
    ifstream fileWithFishInRiver (initListFish);
    string fishFromRiver;
    if (fileWithFishInRiver.is_open()) {
        int countCatchFish = 0;
        while (getline (fileWithFishInRiver, fishFromRiver)) {
            int initRand = rand() % 2;
            if (findFishInList == fishFromRiver) {
                if (initRand == 1) { // <<<<<вот тут думал значение рандома выставить от 0 до 100 и проверять initRand четное или нет и больше ли например 50 и меньше 77, но не стал усложнять
                    cout << "\nCool, you caught a fish!";
                    countCatchFish+=1;
                    saveInit(findFishInList, savedFishInCart);
                } else {
                    cout << "\nThe fish got away!";
                }
            }
        }

        //для отображения количетсва рыбов и названия рыба
        if (countCatchFish > 0) {
            cout << "\nYou catch " << countCatchFish << " fish " << findFishInList << endl;
        } else {
            cout << "\nThis kind of fish "<< findFishInList <<" doesn't live in that river.";
        }
    }

}

int main () {
    //сперва проверка файлов игры
    if (checkFileExists(initListFish) && checkFileExists(savedFishInCart)) {
        cout << "\n***The files has been successfully connected***" << endl;
    } else {
        cout << "\n*****************Error**********************!"
                "\n***The files has been not successfully connected***";
        return 1;
    }

    gameTitle();
    for (int i = 1; i <= 5; i++) {
        cout << "\n\n~~~~~~~~~~~~~Swim #" << i << endl;
        string userFishSelecting = " ";
        bool checkInput = true;

        //контроль ввода
        while (checkInput) {
            cout << "\nEnter the name of the fish:";
            cin >> userFishSelecting;
            if (checkUserInput(userFishSelecting)) {
                checkInput = false;
            }
            else {
                cout << "\nInvalid input! Try again!"
                        "\nOnly low symbol!";
            }
        }
        gameLogicCheckFishInList(userFishSelecting);

        cout << ""
            "\nDo you want to know what's in the basket?"
            "\nInput 1 for yes, else input another digit:";
        int choice;
        cin >> choice;

        if (choice == 1) {
            outFileContent(savedFishInCart);
        }

    }
    return 0;
}