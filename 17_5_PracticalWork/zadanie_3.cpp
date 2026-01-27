//
// Created by kurch on 27.01.2026.
//
#include <iostream>
using namespace std;

bool findSubstring (const char* firstString, const char* secondString) {
    int numbOfMatches = 0;
    for (int i = 0; firstString[i] != '\0'; i++) {
        if (firstString[i] == secondString[i])
            numbOfMatches++;
        if (numbOfMatches == secondString.lenght())
            return true;
    }
}

int main () {
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

}