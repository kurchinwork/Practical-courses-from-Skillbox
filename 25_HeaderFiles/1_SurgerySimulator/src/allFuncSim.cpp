//
// Created by Ellies on 14.03.2026.
//
#include "strctSim.h"

#include <iostream>
using namespace std;

structSim sim;

void title () {
    cout << "\n~Select command for start operation!~"
            "\nDon't forget the sequence of actions"
            "\nFirst has be a scalpel!";
}
void listCommands () {
    cout << "\n````````````````"
            "\n~scalpel"
            "\n~hemostat"
            "\n~tweezers"
            "\n~suture"
            "\n~operation"
            "\n````````````````"
            "\nlist - for out all commands again"
            "\nexit - for exit from sim";
}

bool logicEndOperation () {
    return sim.status.scalpel && sim.status.hemostat && sim.status.suture && sim.status.tweezers; // потом дописать логику завершения операции
}
string selectCommand () {
    cout << "\nSelect command:";
    cin  >> sim.command;
    return sim.command;
}
void scalpel () {

    double x0 = 0.0f,
           x1 = 0.0f;

    cout << "\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
            "\n~You take the scalpel in your hands and are ready to make an incision.~"
            "\nEnter the coordinates of the start and "
            "\nend of the cut in millimeters:"
            "\nCoord X0 :="; cin >> x0;
    cout << "Coord X1 :="; cin >> x1;


    if (x0 < 0.0f || x1 < 0.0f || x1 < x0) {
        cout << "\nInvalid coordinates in your scalpel"
                "\nOnly positives num. Try again.";
    } else if (x0 > 1000.0f || x1 > 1000.0f) {
        cout << "\nInvalid coordinates in your scalpel"
                "\nDo you wanna kill a pacient??? Try again.";
    } else {
        sim.cut_X0 = x0; sim.cut_X1 = x1;
        sim.totalCut = sim.cut_X1 - sim.cut_X0;
        sim.status.scalpel = true;
        cout << "\nYou made the cut carefully: " << sim.totalCut << " mm size";
    }
}
void hemostat () {
    if (sim.status.scalpel) {
        cout << "\n~Specify the hemostat attachment point"
                "\n~~~only one num;"
        "\nYoure cut in " << sim.cut_X0 << " mm start\n"
        << sim.cut_X1 << " mm end\n" <<
        "\nTotal cut: " << sim.totalCut << " mm size";

        double coordAttachHemo_X0 = 0.0f;
        cout << "\nEnter the coordinate: "; cin >> coordAttachHemo_X0;

        if (coordAttachHemo_X0 < sim.cut_X0 || coordAttachHemo_X0 > sim.cut_X1) {
            cout << "\nInvalid coordinates in your cut"
                    "\nTry again.";
        } else {
            cout << "\nThe hemostat is installed";
            sim.status.hemostat = true;
        }
    } else {
        cout << "\nYou didn't make an incision.";
    }
}
void tweezers () {
    if (sim.status.scalpel) {
        cout << "\n~Specify the tweezers attachment point"
                "\n~~~only one num;"
        "\nYoure cut in " << sim.cut_X0 << " mm start\n"
        << sim.cut_X1 << " mm end\n" <<
        "\nTotal cut: " << sim.totalCut << " mm size";

        double coordAttachTweez_X0 = 0.0f;
        cout << "\nEnter the coordinate: "; cin >> coordAttachTweez_X0;

        if (coordAttachTweez_X0 < sim.cut_X0 || coordAttachTweez_X0 > sim.cut_X1) {
            cout << "\nInvalid coordinates in your cut"
                    "\nTry again.";
        } else {
            cout << "\nThe tweezerst is installed";
            sim.status.tweezers = true;
        }
    } else {
        cout << "\nYou didn't make an incision.";
    }
}
void suture () {
    if (sim.status.scalpel && sim.status.hemostat && sim.status.tweezers) {
        double suturX0 = 0.0f,
                suturX1 = 0.0f;

        cout << "\nCut size: " << sim.totalCut << " mm size"
                "\nCoord X0 =" << sim.cut_X0 << " mm size"
                "\nCoord X0 =" << sim.cut_X1 << " mm size";

        cout << "\nSpecify the location of the suture"
                "\n~Start suture coord: "; cin >> suturX0;
        cout << "\n~End suture coord: "; cin >> suturX1;

        if (suturX0 < sim.cut_X0 || suturX1 > sim.cut_X1) {
            cout << "\nYou've successfully sutured the wound!"
                     "\nThe operation is complete!";
            sim.status.completeOperation = true;
        } else {
            cout << "\nInvalid coordinates in your cut"
                    "\nTry again.";
        }


    } else {
        if (!sim.status.scalpel) {
            cout << "\nThere's nothing to stitch up, you didn't make an incision.";
        }
        if (!sim.status.hemostat) {
            cout << "\nInstall the hemostat first";
        }
        if (!sim.status.tweezers) {
            cout << "\nInstall the tweezers first";
        }
    }
}



