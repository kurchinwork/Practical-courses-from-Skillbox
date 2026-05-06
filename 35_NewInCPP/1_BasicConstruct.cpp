//
// Created by kurchin_iu on 06.05.2026.
//
#include <iostream>

int main () {
    std::initializer_list<int> listOne {1, 2, 3, 4, 5};
    for (auto list: listOne)
        std::cout << list << " ";

    return 0;
}