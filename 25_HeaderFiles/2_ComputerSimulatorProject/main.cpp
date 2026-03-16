#include <iostream>
#include "include/simComp.h"

using namespace std;

int main() {
    commandList();

    do {
        cout << "\nEnter command: "; command();

        if (sim.command == "sum") {
            if (sim.buffer.empty()) {
                cout << "\nThere is nothing to count...";
            } else {
                cout << "\nTotal sum all elements:";
                display(); cout << " = " << sum ();
            }

        } else if (sim.command == "input") {
            kbrd();
        } else if (sim.command == "display") {
            display ();
        } else if (sim.command == "save") {
            if (sim.buffer.empty()) {
                cout << "\nYou did not enter anything before saving.";
            } else {
                saveFunc ();
                if (sim.status.save) {
                    ramClear (); //если файл сохранен то освобождаю ram для того чтобы потом загрузить данные из load
                }
            }
        } else if (sim.command == "load") {
            loadFunc ();
        } else if (sim.command == "list") {
            commandList();
        } else if (sim.command != "exit") {
            cout << "\nInvalid command!: " << sim.command <<
                    "\nCommand only from command List!" << endl;
        }
    } while (!(sim.command == "exit"));
    return 0;
}