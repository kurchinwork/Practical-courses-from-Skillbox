//
// Created by kurchin ilya on 18.12.2025.
//

#include <iostream>

int main() {
    std::string residents[10];
    int numAppart_1, numAppart_2, numAppart_3;

    std::cout << "Please take into account the rules for maintaining the database:\n"
                 " - no more than 10 apartments.\n";
    std::cout << "Enter the tenant's name: ";
    for (int i = 0; i < 10; ++i) {
        if (i > 0 && i < 10)
            std::cout << "Who is live in #" << i + 1 << " apart?: " << residents[i];
        std::cin >> residents[i]; std::cout << std::endl;
    }

    std::cout << "Perhaps you want to selectively remember who lives in three apartments?\n"
                 "Enter the apartment numbers sequentially: ";

    std::cin >> numAppart_1 >> numAppart_2 >> numAppart_3;

    if (numAppart_1 > 10 || numAppart_2 > 10 ||numAppart_3 > 10) {
        std::cout << "I hope you remember that there are only 10 apartments?\n";
        if (numAppart_1 > 10)
            std::cout << "This value is: #" << numAppart_1 << std::endl;
        if (numAppart_2 > 10)
            std::cout << "This value is: #" << numAppart_2 << std::endl;
        if (numAppart_3 > 10)
            std::cout << "This value is: #" << numAppart_3 << std::endl;
        return 0;
    }
    std::cout << "In apartment number #" << numAppart_1 <<" lives a tenant named: " << residents[0 + numAppart_1 - 1] << std::endl;
    std::cout << "In apartment number #" << numAppart_2 <<" lives a tenant named: " << residents[0 + numAppart_2 - 1] << std::endl;
    std::cout << "In apartment number #" << numAppart_3 <<" lives a tenant named: " << residents[0 + numAppart_3 - 1] << std::endl;
}