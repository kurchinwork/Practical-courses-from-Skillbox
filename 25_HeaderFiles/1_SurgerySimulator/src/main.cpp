//
// Created by Ellies on 14.03.2026.
//
#include <iostream>
#include <chrono>
#include <thread>
#include "strctSim.h"

using namespace std;

int main () {
    title();
    listCommands();
    do {
        selectCommand();
        if (sim.command == "scalpel") {
            if (sim.status.scalpel == true) {
                cout << "\nYou've already made an incision. "
                        "\nFirst, you need to operate on it or stitch it up.";
            } else {
                scalpel ();
            }
        }
        if (sim.command == "operation") {
            if (sim.status.suture == true) {
                cout << "\nYou have already stitched the suture, "
                        "\nstart the operation again "
                        "\nif you forgot something in the patient :(";
            } else {
                if (sim.status.scalpel == true) {
                    cout << "\nYou have started the operation."
                            "\nWait 10 sec..";
                    for (int i = 10; i != 0; i--) {
                        cout << "\n" << i << " sec.";
                        this_thread::sleep_for(chrono::seconds(1));
                    }
                    cout << "You have completed the operation.";//думал здесь сделать шанс успеха проведния операции но пожалел пациента)
                } else {
                    cout << "\nUse a scalpel first!";
                    scalpel ();
                }
            }
        }
        if (sim.command == "hemostat") {
            hemostat();
        }
        if (sim.command == "tweezers") {
            tweezers();
        }
        if (sim.command == "suture") {
            suture ();
        }
        if (sim.command == "list") {
            listCommands();
        }
        if (sim.command == "exit") {
            if (logicEndOperation()) {
                cout << "\nYou can complete the operation safely.";
                break;
            } else {
                cout << "\nYou have not completed the operation, are you sure you want to exit?"
                        "\nRepreat enter command ~exit~ if yes else another command.";
                selectCommand();
                if (sim.command == "exit") {
                    return 1;
                }
            }
        }
    } while (!sim.status.completeOperation);
    return 0;
}