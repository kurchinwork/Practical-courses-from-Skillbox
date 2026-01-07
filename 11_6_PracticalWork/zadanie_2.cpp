//
// Created by kurchin ilya on 12.12.2025.
//

#include <iostream>

bool validMail (std::string eMail) {
    for (char& symbolInLocal : eMail) {
        bool symbolValid = false;
        if (symbolInLocal >= 'a' && symbolInLocal <= 'z') {
            symbolValid = true;
        } else if (symbolInLocal >= 'A' && symbolInLocal <= 'Z') {
            symbolValid = true;
        } else if (symbolInLocal >= '0' && symbolInLocal <= '9') {
            symbolValid = true;
        } else if (symbolInLocal == '.'
            || symbolInLocal == '-'
            || symbolInLocal == '_'
            || symbolInLocal == '@') {
            symbolValid = true;
            }
        if (!symbolValid) {
            std::cout << symbolInLocal << " is not a valid symbol.\n";
            return false;
        }
    }
    return true;
}
bool leftSymbol(std::string eMail) {
    std::string leftSymbol;

    for (int i = 1; i < eMail.length(); i++) {
        if (eMail[i] == '@' && eMail[i - 1] == '@') {
            std::cout << "More than two @ in a row.\n";
            return false;
        }
    }

    for (int i = 0; i < eMail.length(); i++) {
        if (eMail[i] == '@') {
            break;
        }
        leftSymbol += eMail[i];
        if (leftSymbol.length() > 64) {
            std::cout << "The left side is too long.\n";
            return false;
        }

        else if (i > 0 && leftSymbol[i] == '.' && leftSymbol[i - 1] == '.') {
            std::cout << "More than two dots in a row.\n";
            return false;
        }

        else if (i == 0 && (leftSymbol[0] == '.' || leftSymbol[0] == '@')) {
            std::cout << "The left side cannot start with a dot or @.\n";
            return false;
        }
    }
    return true;
}
bool rightSymbol(std::string eMail) {
    int atPosition = -1;

    for (int i = 0; i < eMail.length(); i++) {
        if (eMail[i] == '@') {
            atPosition = i;
            break;
        }
    }

    if (atPosition == -1) {
        std::cout << "No @ symbol found.\n"
            "The address is not valid.\n";
        return false;
    }

    if (atPosition + 1 >= eMail.length()) {
        std::cout << "No domain after @.\n"
            "The address is not valid.\n";
        return false;
    }

    for (int i = atPosition + 1; i < eMail.length(); i++) {
        if (eMail[i] == '_') {
            std::cout << "Underscore '_' is not allowed in the domain part.\n"
                "The address is not valid.\n";
            return false;
        }
    }
    return true;
}

int main() {
    std::cout << "Please remember the rules for entering your email address:"
                 "\n - it should not contain special characters.";
    std::string eMail;
    std::cout << "\nEnter your eMail: "; std::cin >> eMail; std::cout << "\n";

    if (validMail(eMail) && leftSymbol(eMail) && rightSymbol(eMail)) {
        std::cout << eMail << " - is valid eMail address!\n";
    } else {
        std::cout << eMail << " - is NOT valid eMail address!\n";
    }
}