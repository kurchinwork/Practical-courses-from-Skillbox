//
// Created by kurchin_iu on 16.03.2026.
//
#include <iostream>
#include <string>
#include "../include/simComp.h"

//функция сложения 8 чисел

int sum () {
    int sum = 0;
    for (int i = 0; i < sim.buffer.size(); i++) {
        sum += sim.buffer[i];
    }
    return sum;
}