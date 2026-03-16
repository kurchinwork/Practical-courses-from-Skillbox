//
// Created by kurchin_iu on 16.03.2026.
//
#include <string>
#include <iostream>
#include "../include/simComp.h"

compSim sim;

void commandList() {
    std::cout << "\n~Command list:"
            "\n~~sum - command for total sum all num"
            "\n~~input - command for input num"
            "\n~~display - command for output num"
            "\n~~save - command for save num"
            "\n~~load - command for load num"
            "\n-----------------------------"
            "\n~~list - command for show all commands"
            "\n~~exit - command for exit";
}

std::string command () {
    std::cin >> sim.command;
    return sim.command;
}