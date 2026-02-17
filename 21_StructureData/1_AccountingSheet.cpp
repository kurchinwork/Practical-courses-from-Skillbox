//
// Created by kurch on 13.02.2026.
//
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

const char* fileAdress = "FileForTask_1\\salary.csv";
struct account {
    string lineFromFile,
        name = " ",
        surName = " ",
        datePayMent = " ",
        nameWithMaxSalary = " ",
        surNameWithMaxSalary = " ",
        maxdatePayMent = " ";

    int salary = 0,
        totalSalaryBudget = 0,
        maxSalary = 0;
};
struct commands {
    string choice = " ";
};

bool checkString (account& elementsAccount) {
    for (char checkSymbol : elementsAccount.name) {
        bool foundFail = (checkSymbol >= 'a' && checkSymbol <= 'z' || checkSymbol >= 'A' && checkSymbol <= 'Z');
        if (!foundFail) {
            cout << "\nError in specifying the name!";
            return false;
        }

    }
    for (char checkSymbol : elementsAccount.surName) {
        bool foundFail = (checkSymbol >= 'a' && checkSymbol <= 'z' || checkSymbol >= 'A' && checkSymbol <= 'Z');
        if (!foundFail) {
            cout << "\nError in specifying the surname!";
            return false;
        }
    }

    if (elementsAccount.salary <= 0) {
        cout << "\nError in specifying the salary!";
        return false;
    }
    if (elementsAccount.datePayMent.length() != 10) {
        cout << "\nError: Date must be at least 10 characters!" << elementsAccount.datePayMent.length();
        return false;
    }
    int dayInDayPayment = stoi(elementsAccount.datePayMent.substr(0,2)),
        monthInDayPayment = stoi(elementsAccount.datePayMent.substr(4,2)),
        yearInDayPayment = stoi(elementsAccount.datePayMent.substr(6,4));

    if (dayInDayPayment < 0 || dayInDayPayment > 31) {
        cout << "\nError in specifying the date of day!";
        return false;
    }
    if (monthInDayPayment < 0 || monthInDayPayment > 12) {
        cout << "\nError in specifying the month of day!";
        return false;
    }
    if (yearInDayPayment < 2022 || yearInDayPayment > 2026) {
        cout << "\nError in specifying the years"
                "\nOnly 2022 to 2026.";
        return false;
    }

    return true;
}
void fileForWrite(account& elementsAccount, const char * file){
    ofstream filecsv(file,ios::app);
    if (!filecsv.is_open()) {
        cout << "\nThe file has been failed.";
        exit(1);
    } else {
        cout << "\n***The file has been successfully connected***\n";
    }

    cout << "\nHow many lines do you want to enter into the file?:";
    int countLines = 0; cin >> countLines;

    cout << "\nEnter the data in the following format:"
        "\nFirst Name LastName 5000 (Salary) 01.01.2026 (Payment details)." << endl;


    for (int i = 0; i < countLines; i++) {
        bool validationInput = true;
        while (validationInput) {
            cin >> elementsAccount.name >> elementsAccount.surName >> elementsAccount.salary >> elementsAccount.datePayMent;
            if (!checkString (elementsAccount)) {
                cout << "\nTry input again!:";
            } else {
                validationInput = false;
            }
        }

        string LineForWrite = elementsAccount.name + " " + elementsAccount.surName + " " + to_string (elementsAccount.salary) + " " + elementsAccount.datePayMent;
        filecsv << LineForWrite << endl;
    }
    filecsv.close();
}
void fileForRead (account& elementsAccount, const char * file) {
    ifstream fileForRead(file);
    if (!fileForRead.is_open()) {
        cout << "\nThe file has been failed.";
        exit(1);
    } else {
        cout << "\n***The file has been successfully connected***\n";
    }
    int salary = 0,
        totalSalaryBudget = 0,
        maxSalary = 0;

    cout << "\n*******************************************************"
            "\nFile contents:" << endl;
    while (getline(fileForRead, elementsAccount.lineFromFile)) {
        istringstream parcingLine(elementsAccount.lineFromFile);

        while (parcingLine >> elementsAccount.name >> elementsAccount.surName  >> salary >> elementsAccount.datePayMent) { // обработка каждого слова
            totalSalaryBudget += salary;
            if (maxSalary < salary) {
                maxSalary = salary;
                elementsAccount.nameWithMaxSalary = elementsAccount.name;
                elementsAccount.surNameWithMaxSalary = elementsAccount.surName;
                elementsAccount.maxdatePayMent = elementsAccount.datePayMent;
            }
        }

        cout << elementsAccount.lineFromFile << endl;
    }

    cout << "\n*******************************************************"
            "\nAmount spent on paying salaries: " << totalSalaryBudget
         << "\nThe biggest payment was received " << elementsAccount.surNameWithMaxSalary
         << " " << elementsAccount.nameWithMaxSalary << " " << maxSalary << " at " << elementsAccount.maxdatePayMent
         << "\n*******************************************************" << endl;

    fileForRead.close();
}


int main () {
    commands cmdFromUser;
    account elementsAccount;
    while (true) {
        cout << "\nWhat do you want to do?"
        "\nList commands:"
        "\n\tadd - for add line in file;"
        "\n\tlist - for read line from file;"
        "\n\texit - for exit from programm."
        "\nInput commands: "; cin >> cmdFromUser.choice;
        if (cmdFromUser.choice == "exit") {
            cout << "Program terminates...";
            return 0;
        }
        if (cmdFromUser.choice == "list") {
            fileForRead (elementsAccount, fileAdress);
        }
        if (cmdFromUser.choice == "add") {
            fileForWrite(elementsAccount, fileAdress);
        }
    }
}
