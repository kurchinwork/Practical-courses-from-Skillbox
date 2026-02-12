#include <iostream>

int main() {
    std::cout << "\nEnter a long real number: ";
    std::string digit; std::cin >> digit;

    bool logic_digitIn = true;
    bool foundDigitAfterPoint = false;
    bool pointFound = false;

    if (!(digit.empty()) &&
        (
            (digit[0] >= '0' && digit[0] <= '9') ||
            digit[0] == '-' ||
            digit[0] == '.'
        )
    ) {
    } else {
        logic_digitIn = false;
    }

    for (int i = 1; i < digit.length(); ++i) {
        if (digit[i] == '.') {
            if (pointFound) {
                logic_digitIn = false;
            } else {
                pointFound = true;
            }
        } else if (digit[i] >= '0' && digit[i] <= '9') {
            if (pointFound) {
                foundDigitAfterPoint = true;
            }
        } else {
            logic_digitIn = false;
        }
    }

    if (pointFound && !foundDigitAfterPoint) {
        logic_digitIn = false;
    }

    if (logic_digitIn) {
        std::cout << "\nYes, your number is real.\n";
    } else {
        std::cout << "\nNO, your number is NOT real.\n";
    }
}