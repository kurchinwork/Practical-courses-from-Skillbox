//
// Created by kurch on 22.04.2026.
//
#include <iostream>
#include <ctime>

class Fish {};
class Boot {};

void InitGameField (void** field) {
    field[std::rand() % 9] = new Fish;

    for (int i = 0; i < 3; i++) {
        int sector = 0;

        do {
            sector = std::rand() % 9;
        } while (field[sector] != nullptr);

        field[sector] = new Boot;
    }
}

int main () {
    std::srand(std::time(nullptr));

    void* Gamefield[9] = {nullptr};

    InitGameField(Gamefield);

    std::cout << "Game field is ready for play!" << std::endl;

}