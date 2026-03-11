//
// Created by kurchin_iu on 10.03.2026.
//
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>

using namespace std;
struct BirthdayReminder {
    vector<string> birthdayList;
    vector<string> nameList;
};

void userNameInit (BirthdayReminder& birthdayReminder, bool& logicContinueProgram) {
    string userName;
    cout << "\nName:";
    getline(cin,userName);

    if (userName == "end") {
        logicContinueProgram = false;
    } else {
        birthdayReminder.nameList.push_back(userName);
    }


    //birthdayReminder.nameList.clear();
}
void dateBirthdInit (BirthdayReminder& birthdayReminder) {;
    string dateBirthd;
    bool checkDateMain = true;
    do {
        char delimiter1, delimiter2;
        cout << "\nBirthday date in format: 01/01/1999";
        cout << "\nDate Birthday: ";
        getline(cin,dateBirthd);

        int day = 0,
            month = 0,
            year = 0;

        stringstream ss(dateBirthd);
        ss >> day >> delimiter1 >> month >> delimiter2 >> year;

        bool checkDelimit = delimiter1 == '/' && delimiter2 == '/';
        bool checkDate = (day > 0 && day <= 31) && (month > 0 && month <= 12) && (year > 0 && year <= 2027);
        checkDateMain = checkDate && checkDelimit;
        if (!checkDateMain) {
            cout << "\nInvalid date in format.";
        }
    } while (!checkDateMain);

    birthdayReminder.birthdayList.push_back(dateBirthd);
};

void CalculatingDateBirth (BirthdayReminder& birthdayReminder) {

    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);

    stringstream ssCurrent;
    int dayCurrent = 0,
        monthCurrent = 0,
        yearCurrent = 0;
    char delimiter;

    //if (birthdayReminder.birthdayList.size() != birthdayReminder.nameList.size()) {
    //    cout << "\nData completeness error, please try again.";
    //    exit (0);
    //}



    ssCurrent << put_time(localtime(&now_time), "%d:%m:%Y");
    ssCurrent >> dayCurrent >> delimiter >> monthCurrent >> delimiter >> yearCurrent;

    for (int i = 0; i < birthdayReminder.birthdayList.size(); i++) {
        int day = 0,
            month = 0,
            year = 0;

        stringstream ss(birthdayReminder.birthdayList[i]);
        ss >> day >> delimiter >> month >> delimiter >> year;

        if (monthCurrent == month && dayCurrent == day) {
            cout << "\nIt's " << birthdayReminder.nameList[i] << " birthday today!"
                    "\nDon't forget to wish him/her a happy birthday." << endl;
        }
        else if (monthCurrent <= month && dayCurrent <= day) {
            cout << "\nAt " << birthdayReminder.nameList[i] << " is in " << month - monthCurrent << " months and " << day - dayCurrent << " days." << endl;
        } else {
            cout << "\nAt " << birthdayReminder.nameList[i] << " birthday has passed!" << endl;
        }
    }
}

int main () {
    BirthdayReminder birthdayReminder;
    cout << "\nThe signal for finishing entering birthdays is ~end~ entered as a name.";

    bool logicContinueProgram = true;

    while (logicContinueProgram) {
        userNameInit (birthdayReminder, logicContinueProgram);
        if (!logicContinueProgram) {
            cout << "\nYou have stopped the recording process." << endl;
            break;
        }
        dateBirthdInit (birthdayReminder);
    }
    CalculatingDateBirth (birthdayReminder);
    return 0;
}