//
// Created by kurch on 27.01.2026.
//
#include <iostream>
using namespace std;

bool findSubstring(const char* firstString, const char* secondString) {
    for (int i = 0; firstString[i] != '\0'; i++) {
        int j = 0;
        while (secondString[j] != '\0' && firstString[i + j] == secondString[j]) {
            j++;
        }
        if (secondString[j] == '\0') {
            return true;
        }
    }
    return false;
}
        /*
        int numbOfMatches = 0;
        for (int i = 0; firstString[i] != '\0'; i++) {
            for (int j = 0; secondString[j] != '\0'; j++) {
                if (firstString[i] == secondString[j])
                    numbOfMatches++;
            }
        }
        if (numbOfMatches == 0) {
            return false;
        } else {
            return true;
        }*/


int main () {
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    if (findSubstring (a, b) == true) {
        cout << "\nThe second string is a substring of the first: "<< a << ", " << b <<endl;
    }
    if (findSubstring (a, c) == true) {
        cout << "\nThe third string is a substring of the first: "<< a << ", " << c <<endl;
    }
    if ((findSubstring (a, b) == false) && (findSubstring (a, c) == false)) {
        cout << "\nNone of the expressions is a substring of the first!" << a << ", " << b << ", " << c <<endl;
    }

    return 0;
}