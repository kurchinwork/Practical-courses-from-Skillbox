#include <iostream>
#include <string>

int main() {
    std::string input;
    
    std::cout << "Enter a word or string: ";
    std::getline(std::cin, input);
    int wordCount = 0;
    bool inWord = false;
    
    for (char c : input) {
        if (c != ' ') {
            if (!inWord) {
                wordCount++;
                inWord = true;
            }
        } else {
            inWord = false;
        }
    }
    std::cout << "Count a word: " << wordCount << std::endl;
}