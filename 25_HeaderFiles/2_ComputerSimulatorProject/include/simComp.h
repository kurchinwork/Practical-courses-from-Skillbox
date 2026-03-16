//
// Created by kurchin_iu on 16.03.2026.
//
#pragma once

#ifndef COMPSIM_SIMCOMP_H
#define COMPSIM_SIMCOMP_H

#include <vector>
#include <string>

struct status {
    bool save = false,
         ram = false;
};
struct file {
    std::string nameFile = "";
};
struct compSim {
    std::vector <int> buffer;
    std::string command = "";

    file file;
    status status;
};


void commandList();
void kbrd();
void ramInsert (int& NumInsert);
void ramClear ();

std::string command ();

void saveFunc ();
void loadFunc ();
void display ();

int sum ();

extern compSim sim;

#endif //COMPSIM_SIMCOMP_H