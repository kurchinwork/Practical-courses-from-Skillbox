//
// Created by kurchin_iu on 16.03.2026.
//
//организовать буфер который хранит числа и очищается после работы
#include <vector>
#include <iostream>
#include "simComp.h"

void ramInsert (int& NumInsert) {
    sim.buffer.push_back(NumInsert);
}

void ramClear () {
    if (!sim.buffer.empty()){
        sim.buffer.clear(); // удаляю элементы безопасно
        sim.status.ram = false;
        std::cout << "\nBuffer is empty.";
        } else {
            std::cout << "\nBuffer is empty.";
    }
}