//
// Created by Ellies on 14.03.2026.
//

#ifndef SURGERYSIMULATOR_STRCTSIM_H
#define SURGERYSIMULATOR_STRCTSIM_H
#include <string>

struct status {
    bool scalpel = false,
         hemostat = false,
         tweezers = false,
         suture = false,
         completeOperation = false;

};

struct structSim {
    status status;

    std::string command = "";

    double cut_X0 = 0.0f,
           cut_X1 = 0.0f,
           totalCut = 0.0f;

};
extern structSim sim;

void title ();
void listCommands ();
void scalpel ();
void hemostat ();
void tweezers ();
void suture ();

bool logicEndOperation ();
std::string selectCommand ();


#endif //SURGERYSIMULATOR_STRCTSIM_H