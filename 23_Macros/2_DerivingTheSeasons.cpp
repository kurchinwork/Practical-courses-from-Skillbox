//
// Created by kurch on 02.03.2026.
//
#include <iostream>
#define SUMMER //менять сезон здесь

int main () {
#ifdef SUMMER
    std::cout << "Summer" << std::endl;
    #endif
#ifdef AUTUMN
    std::cout << "Autumn" << std::endl;
#endif
#ifdef WINTER
    std::cout << "Winer" << std::endl;
#endif
#ifdef SPRING
    std::cout << "Spring" << std::endl;
#endif
}