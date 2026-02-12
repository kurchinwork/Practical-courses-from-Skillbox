//
// Created by kurch on 09.02.2026.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

bool checkString (string& name, string& surName, string& salary, string& datePayMent) {
    for (char checkSymbol : name) {
        bool foundFail = (checkSymbol >= 'a' && checkSymbol <= 'z' || checkSymbol >= 'A' && checkSymbol <= 'Z');
        if (!foundFail) {
            cout << "\nError in specifying the name!";
            return false;
        }

    }
    for (char checkSymbol : surName) {
        bool foundFail = (checkSymbol >= 'a' && checkSymbol <= 'z' || checkSymbol >= 'A' && checkSymbol <= 'Z');
        if (!foundFail) {
            cout << "\nError in specifying the surname!";
            return false;
        }
    }
    for (char checkSymbol : salary) {
        bool foundFail = (checkSymbol >= '0' && checkSymbol <= '9');
        if (!foundFail) {
            cout << "\nError in specifying the salary!";
            return false;
        }

    }
    if (datePayMent.length() != 10) {
        cout << "\nError: Date must be at least 10 characters!" << datePayMent.length();

        return false;
    }
    int dayInDayPayment = stoi(datePayMent.substr(0,2)),
        monthInDayPayment = stoi(datePayMent.substr(4,2)),
        yearInDayPayment = stoi(datePayMent.substr(6,4));
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
void fileForWrite(string& adressFileForWork){
    ofstream filecsv(adressFileForWork,ios::app);
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
        string name = " ",
               surName = " ",
               salary = " ",
               datePayMent = " ";

        bool validationInput = true;
        while (validationInput) {
            cin >> name >> surName >> salary >> datePayMent;
            if (!checkString (name, surName, salary, datePayMent)) {
                cout << "\nTry input again!:";
            } else {
                validationInput = false;
            }
        }

        string LineForWrite = name + " " + surName + " " + salary + " " + datePayMent;
        filecsv << LineForWrite << endl;
    }

    filecsv.close();
}
void fileForRead (string& adressFileForWork) {
    ifstream fileForRead(adressFileForWork);
    if (!fileForRead.is_open()) {
        cout << "\nThe file has been failed.";
        exit(1);
    } else {
        cout << "\n***The file has been successfully connected***\n";
    }

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

    cout << "\n*******************************************************"
            "\nFile contents:" << endl;
    while (getline(fileForRead, lineFromFile)) {
        istringstream parcingLine(lineFromFile);

        while (parcingLine >> name >> surName  >> salary >> datePayMent) { // обработка каждого слова
            totalSalaryBudget += salary;
            if (maxSalary < salary) { // услов я максимального
                maxSalary = salary;
                nameWithMaxSalary = name;
                surNameWithMaxSalary = surName;
                maxdatePayMent = datePayMent;
            }
        }

        cout << lineFromFile << endl;
    }

    cout << "\n*******************************************************"
            "\nAmount spent on paying salaries: " << totalSalaryBudget
         << "\nThe biggest payment was received " << surNameWithMaxSalary
         << " " << nameWithMaxSalary << " " << maxSalary << " at " << maxdatePayMent
         << "\n*******************************************************" << endl;

    fileForRead.close();
}

int main () {
    string adressFileForWork = "FilesForTask_1\\salary.csv";
    int choice = 0;

    cout << "\nThis program allows you to read the contents of a file or append to an existing file."
            "\nTo select the path manually, press 1; if you want to use the default, press 0.:"; cin >> choice;
    if (choice == 1) {
        cout << "Enter the path to the file, just don't forget about \\\\";
        cin >> adressFileForWork;
    }

    while (true) {
        choice = 0;
        cout << "\nWhat do you want to do?"
        "\nPress 1 if you only want to read;"
        "\nPress 2 if you want to add a record to the file (if the file hasn't been created yet, it will be created automatically)."
        "\nPress -1 for close programm"
        "\nYour choice: "; cin >> choice;
        if (choice == -1) {
            cout << "Program terminates...";
            return 0;
        }
        if (choice == 1) {
            fileForRead (adressFileForWork);
        }
        if (choice == 2) {
            fileForWrite(adressFileForWork);
        }
    }
}