//
// Created by kurch on 26.01.2026.
//
#include <iostream>

using namespace std;
int main () {

    string firstNum = "";
    string secondNum = "";

    cout << "Enter the whole number part."
            "\nBe sure to use a number with a period after the end of the number:";
    cin >> firstNum;

    if (firstNum.find('.') == string::npos) {
        cout << "\nWhere is the dot in the line?\n"
                "Okay, I'll add it myself.\n";
        firstNum += ".";
    }


    cout << "\nEnter the part of the number after the period,\n"
            "the line can't start with a period or a comma.\n"
            "Only the left part of the number:";
    cin >> secondNum;

    double result = stod (firstNum+secondNum);
    std::cout << result << std::endl;

    return 0;
}