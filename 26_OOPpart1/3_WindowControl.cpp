//
// Created by kurchin_iu on 20.03.2026.
//
#include <iostream>

using namespace std;

class Window {
private:
    int total_Height = 50,
        total_Width = 80;

    int init_Height = 0,
        init_Width = 0;

    int startCoordH = 0,
        startCoordW = 0;

    int moveHeight = 0,
        moveWidht = 0;

    bool move = false,
         resize = true;

public:
    void out() {
        for (int y = 0; y < total_Height; y++) {
            for (int x = 0; x < total_Width; x++) {
                if (resize) {
                    // границы окна
                    bool inWindowX = (x >= startCoordW && x < startCoordW + init_Width);
                    bool inWindowY = (y >= startCoordH && y < startCoordH + init_Height);

                    if (inWindowX && inWindowY) {
                        // внутри окна
                        if (x == startCoordW || x == startCoordW + init_Width - 1 ||
                            y == startCoordH || y == startCoordH + init_Height - 1) {
                            cout << "#";  // граница окна
                            } else {
                                cout << " ";  // Внутренность окна
                            }
                    } else {
                        cout << ".";
                    }
                } else {
                    cout << ".";
                }
            }
            cout << endl;
        }
    }
    void resized() {
        cout << "\nEnter Height window: ";cin >> init_Height;
        cout << "\nEnter Width window: ";cin >> init_Width;

        cout << "\nEnter start coord H: "; cin >> startCoordH;
        cout << "\nEnter start coord W: "; cin >> startCoordW;
        cin.ignore();
        bool parametrs = startCoordH >= 0
                      && startCoordW >= 0
                      && startCoordH < total_Height
                      && startCoordW < total_Width
                      && startCoordH + init_Height <= total_Height
                      && startCoordW + init_Width <= total_Width;

        if (parametrs) {
            resize = true;
        } else {
            resize = false;
            cout << "\nYour window parameters are out of range." << endl;
        }
    }
    void moved() {
        cout << "\nEnter move Height window: ";cin >> moveHeight;
        cout << "\nEnter move Width window: ";cin >> moveWidht;

        bool parametrs = moveHeight >= 0 && moveWidht >=0
                      && moveHeight < total_Height
                      && moveWidht < total_Width
                      && startCoordH + init_Height + moveHeight <= total_Height
                      && startCoordW + init_Width + moveWidht <= total_Width;
        if (parametrs) {
            move = true;
        }
    }
};
void listCommands() {
    cout << "\nEnter command: "
        "\n~move - to move the window;"
        "\n~resize - to scale the window;"
        "\n~display - to display the window;"
        "\n```````````````````````"
        "\n~command - for list all all commands Adio player;"
        "\n~close - for exit." << endl;
}

int main() {
    Window window;
    listCommands();
    string command = "";
    do {

        cout << "\nEnter command: "; cin >> command; cin.ignore();
        if (command == "move") {
            window.moved();
        }
        if (command == "resize") {
            window.resized();
        }
        if (command == "display") {
            window.out();
        }
    } while(command != "close");

    return 0;
}