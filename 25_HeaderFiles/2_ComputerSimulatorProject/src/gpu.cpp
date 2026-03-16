//
// Created by kurchin_iu on 16.03.2026.
//

//выводит числа из файла

#include "simComp.h"
#include <iostream>

void display () {
    if (!sim.buffer.empty()) {
        for (int i = 0; i < sim.buffer.size(); i++) {
            std::cout << sim.buffer[i] << " ";
        }
    } else {
        std::cout << "\nRam is empty";
    }
}