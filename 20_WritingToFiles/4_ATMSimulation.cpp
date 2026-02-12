//
// Created by kurch on 10.02.2026.
//
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;
const char* mainBinFile = "FilesForTask_4\\content.bin";
struct denominationOfBanknotes {
    int count5k = 0,
        count2k = 0,
        count1k = 0,
        count05k = 0,
        count02k = 0,
        count01k = 0;

    const int
    MaXcount5k = 50,
    MaXcount2k = 100,
    MaXcount1k = 150,
    MaXcount05k = 200,
    MaXcount02k = 250,
    MaXcount01k = 250;
};

bool checkFileExists (const string& fileName) {
    ifstream file (fileName);
    if (file.is_open()) {
        return 1;
    } else {
        return 0;
    }
}
bool validOperation (char& smbl) {
    while (true) {
        cout << "?:";
        cin >> smbl;
        if (smbl == '-') {
            return false;
        }
        if (smbl == '+') {
            //Хотел организовать проверку логина пароля для доступа к функциям сервиса, но показалось излишним усложнять
            //предполагал хранить в отдельном файле *csv список (который в теории мог быть бы на сервере например) с хранилищем логинов и паролей сервисников
            //и сранивать loginFromCin == loginFromFileCSV && passwordFromCin == passwordFromFileCSV и после выполнения условия только потом давть доступ
            return true;
        }
        if (smbl == 'x') {
            exit (0);
        }
        cout << "\nPlease re-enter! Only allowed characters." << endl;
    }
}



void depositMoney () {
    srand(time(nullptr));

    if (!checkFileExists(mainBinFile)) {
        cout << "\nFile has been not connected!"
                "\nATM is empty." << endl;
    } else {
        cout << "\nFile has been connected!" << endl;
    }

    denominationOfBanknotes denominate;
    ifstream workFile (mainBinFile, ios::binary);
    workFile.read(reinterpret_cast<char*>(&denominate), sizeof(denominate));
    workFile.close();

    cout  << "\n~~~~~~~~~~~~ State ATM ~~~~~~~~~~~~"
             "\nDenominate~~~Current~~~~~Const need"
             "\n5000         " << denominate.count5k << "       " << denominate.MaXcount5k <<
             "\n2000         " << denominate.count2k << "       " << denominate.MaXcount2k <<
             "\n1000         " << denominate.count1k << "       " << denominate.MaXcount1k <<
             "\n500          " << denominate.count05k << "       " << denominate.MaXcount05k <<
             "\n200          " << denominate.count02k << "       " << denominate.MaXcount02k <<
             "\n100          " << denominate.count01k << "       " << denominate.MaXcount01k << endl;

    int needBalance5 = denominate.MaXcount5k - denominate.count5k,
        needBalance2 = denominate.MaXcount2k - denominate.count2k,
        needBalance1 = denominate.MaXcount1k - denominate.count1k,
        needBalance05 = denominate.MaXcount05k - denominate.count5k,
        needBalance02 = denominate.MaXcount02k - denominate.count02k,
        needBalance01 = denominate.MaXcount01k - denominate.count01k;

    for (int i = 0; i < needBalance5; i++) {
        if (rand() % 2 == 0) denominate.count5k++;
    }
    for (int i = 0; i < needBalance2; i++) {
        if (rand() % 2 == 0) denominate.count2k++;
    }
    for (int i = 0; i < needBalance1; i++) {
        if (rand() % 2 == 0) denominate.count1k++;
    }
    for (int i = 0; i < needBalance05; i++) {
        if (rand() % 2 == 0) denominate.count05k++;
    }
    for (int i = 0; i < needBalance02; i++) {
        if (rand() % 2 == 0) denominate.count02k++;
    }
    for (int i = 0; i < needBalance01; i++) {
        if (rand() % 2 == 0) denominate.count01k++;
    }

    cout  << "\n~~~~~~~~~~~~ State ATM ~~~~~~~~~~~~"
                 "\nDenominate~~~Current~~~~~Const need"
                 "\n5000         " << denominate.count5k << "       " << denominate.MaXcount5k <<
                 "\n2000         " << denominate.count2k << "       " << denominate.MaXcount2k <<
                 "\n1000         " << denominate.count1k << "       " << denominate.MaXcount1k <<
                 "\n500          " << denominate.count05k << "       " << denominate.MaXcount05k <<
                 "\n200          " << denominate.count02k << "       " << denominate.MaXcount02k <<
                 "\n100          " << denominate.count01k << "       " << denominate.MaXcount01k << endl;

    ofstream outWorkFile(mainBinFile, ios::binary);
    outWorkFile.write(reinterpret_cast<const char*> (&denominate), sizeof(denominate));
    outWorkFile.close();
}
void dispensedMoney () {
    denominationOfBanknotes atm;
    ifstream file(mainBinFile, ios::binary);
    file.read(reinterpret_cast<char*>(&atm), sizeof(atm));
    file.close();

    int totalMoney = atm.count5k * 5000 +
                     atm.count2k * 2000 +
                     atm.count1k * 1000 +
                     atm.count05k * 500 +
                     atm.count02k * 200 +
                     atm.count01k * 100;

    int amount;
    cout << "\n~~~~~~~~~~~~ Welcome to ATM ~~~~~~~~~~~~"
            "\nEnter the desired withdrawal amount:";
    cin >> amount;

    if (amount > totalMoney || amount < 0 || amount % 100 != 0) {
        cout << "\nInvalid amount!";
        return;
    }

    int remaining = amount;
    int give5k = 0, give2k = 0, give1k = 0, give500 = 0, give200 = 0, give100 = 0;

    if (remaining >= 5000 && atm.count5k > 0) {
        give5k = min(remaining / 5000, atm.count5k);
        remaining -= give5k * 5000;
    }

    if (remaining >= 2000 && atm.count2k > 0) {
        give2k = min(remaining / 2000, atm.count2k);
        remaining -= give2k * 2000;
    }

    if (remaining >= 1000 && atm.count1k > 0) {
        give1k = min(remaining / 1000, atm.count1k);
        remaining -= give1k * 1000;
    }

    if (remaining >= 500 && atm.count05k > 0) {
        give500 = min(remaining / 500, atm.count05k);
        remaining -= give500 * 500;
    }

    if (remaining >= 200 && atm.count02k > 0) {
        give200 = min(remaining / 200, atm.count02k);
        remaining -= give200 * 200;
    }

    if (remaining >= 100 && atm.count01k > 0) {
        give100 = min(remaining / 100, atm.count01k);
        remaining -= give100 * 100;
    }

    atm.count5k -= give5k;
    atm.count2k -= give2k;
    atm.count1k -= give1k;
    atm.count05k -= give500;
    atm.count02k -= give200;
    atm.count01k -= give100;

    ofstream outFile(mainBinFile, ios::binary);
    outFile.write(reinterpret_cast<const char*>(&atm), sizeof(atm));
    outFile.close();

    cout << "\n  OPERATION SUCCESSFULLY!" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Get:" << endl;
    if (give5k > 0)  cout << "  5000 x " << give5k << " = " << give5k * 5000 << " RUB." << endl;
    if (give2k > 0)  cout << "  2000 x " << give2k << " = " << give2k * 2000 << " RUB." << endl;
    if (give1k > 0)  cout << "  1000 x " << give1k << " = " << give1k * 1000 << " RUB." << endl;
    if (give500 > 0) cout << "   500 x " << give500 << " = " << give500 * 500 << " RUB." << endl;
    if (give200 > 0) cout << "   200 x " << give200 << " = " << give200 * 200 << " RUB." << endl;
    if (give100 > 0) cout << "   100 x " << give100 << " = " << give100 * 100 << " RUB." << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Total: " << amount << " RUB." << endl;
}

int main() {
    while (true) {
        char choiceUser;
        cout << "\n Select operation ATM:"
                "\nInput '-' for get money."
                "\nInput '+' for to into service mode."
                "\nInput 'x' for exit" << endl;
        if (validOperation (choiceUser)) {
            depositMoney();
        } else {
            dispensedMoney();
        }
    }
}