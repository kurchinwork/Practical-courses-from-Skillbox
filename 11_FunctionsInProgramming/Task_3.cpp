//
// Created by kurchin ilya on 13.12.2025.
//

#include <iostream>

bool checkForDot (const std::string &ip4) {
    int dot = 0;

    if (ip4.empty()) {
        std::cout << "IP address cannot be empty.\n";
        return false;
    }

    if (ip4[0] == '.' || ip4[ip4.length() - 1] == '.') {
        std::cout << "IP address cannot start or end with '.'.\n";
        return false;
    }

    for (int i = 0; i < ip4.length(); i++) {
        if (ip4[i] == '.') {
            ++dot;
        }

        if (ip4[i] == '.' && ip4[i + 1] == '.') {
            std::cout << "The address must not contain two consecutive dots.\n";
            return false;
        }
    }

    if (dot != 3) {
        std::cout << "The dot doesn't match 3.\n";
        return false;
    }
    return true;
}
bool get_address_part(const std::string &ip4) {
    std::string octet_1 = "", octet_2 = "", octet_3 = "", octet_4 = "";
    int octet_num = 1;

    for (int i = 0; i < ip4.length(); i++) {
        char c = ip4[i];
        if (c == '.') {
            octet_num++;
            continue;
        }
        if (octet_num == 1) {
            octet_1 += c;
        } else if (octet_num == 2) {
            octet_2 += c;
        } else if (octet_num == 3) {
            octet_3 += c;
        } else if (octet_num == 4) {
            octet_4 += c;
        }
    }

    if (octet_num != 4) {
        std::cout << "There must be no less than or more than 4 octets.\n";
        return false;
    }

    int value = 0;
    for (int i = 0; i < octet_1.length(); i++) {
        if (octet_1[i] < '0' || octet_1[i] > '9') {
            std::cout << octet_1[i] <<" - this symbol is not allowed.\n";
            return false;
        }

        if (octet_1.length() > 1 && octet_1[0] == '0') {
            std::cout << "Leading zero in octet is not allowed.\n";
            return false;
        }

        value = value * 10 + octet_1[i] - '0';
        if (value < 0 || value > 255) {
            std::cout << value <<" - this octet is invalid for Ip4.\n";
            return false;
        }
    }

    value = 0;
    for (int i = 0; i < octet_2.length(); i++) {
        if (octet_2[i] < '0' || octet_2[i] > '9') {
            std::cout << octet_2[i] <<" - this symbol is not allowed.\n";
            return false;
        }

        if (octet_2.length() > 1 && octet_2[0] == '0') {
            std::cout << "Leading zero in octet is not allowed.\n";
            return false;
        }

        value = value * 10 + octet_2[i] - '0';
        if (value < 0 || value > 255) {
            std::cout << value <<" - this octet is invalid for Ip4.\n";
            return false;
        }
    }

    value = 0;
    for (int i = 0; i < octet_3.length(); i++) {
        if (octet_3[i] < '0' || octet_3[i] > '9') {
            std::cout << octet_3[i] <<" - this symbol is not allowed.\n";
            return false;
        }

        if (octet_3.length() > 1 && octet_3[0] == '0') {
            std::cout << "Leading zero in octet is not allowed.\n";
            return false;
        }

        if (octet_4.length() > 1 && octet_4[0] == '0') {
            std::cout << "Leading zero in octet is not allowed.\n";
            return false;
        }

        value = value * 10 + octet_3[i] - '0';
        if (value < 0 || value > 255) {
            std::cout << value <<" - this octet is invalid for Ip4.\n";
            return false;
        }
    }

    value = 0;
    for (int i = 0; i < octet_4.length(); i++) {
        if (octet_4[i] < '0' || octet_4[i] > '9') {
            std::cout << octet_4[i] <<" - this symbol is not allowed.\n";
            return false;
        }

        value = value * 10 + octet_4[i] - '0';
        if (value < 0 || value > 255) {
            std::cout << value <<" - this octet is invalid for Ip4.\n";
            return false;
        }
    }

    return true;
}


int main () {
    std::string ip4;
    std::cout <<  "Please enter your details to verify that your address complies with the standard.\n"
                  "IP address: "; std::cin >> ip4;

    if (checkForDot (ip4) && get_address_part(ip4)) {
        std::cout << ip4 <<" - is valid\n";
    } else {
        std::cout << ip4 <<" - not valid\n";
    }
}