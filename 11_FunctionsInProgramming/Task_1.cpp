//
// Created by kurchin ilya on 11.12.2025.
//

#include <iostream>

std::string encrypt_caesar(std::string text, int k) {
    std::string encodedText;

    for (char& symbolInText : text) {
        if (symbolInText >= 'A' && symbolInText <= 'Z') {
            symbolInText = 'A' + (symbolInText - 'A' + k) % 26;
        }
        else if (symbolInText >= 'a' && symbolInText <= 'z') {
            symbolInText = 'a' + (symbolInText - 'a' + k) % 26;
        }
        if (symbolInText == ' ') {
            symbolInText = ' ';
        }
        encodedText += symbolInText;
    }
    return encodedText;

}

int main() {
    int k;
    std::string text;

    std::cout << "Enter the text to encrypt: "; std::getline(std::cin, text); std::cout << "\n";
    std::cout << "Enter the cipher shift:= "; std::cin >> k; std::cout << "\n";

    std::cout << "Encrypted text: " << encrypt_caesar(text, k) << "\n";
}