#include <iostream>
#include <ctime>
#include <vector>
#include <stdexcept>

class Item {
public:
    virtual ~Item(){}
};

class Fish : public Item {};
class Boot : public Item {};

void InitGameField(Item** field) {
    field[std::rand() % 9] = new Fish;
    for (int i = 0; i < 3; i++) {
        int sector;
        do {
            sector = std::rand() % 9;
        } while (field[sector] != nullptr);
        field[sector] = new Boot;
    }
}

void checkSector(const int& userNumSet, Item** field) {
    if (field[userNumSet] == nullptr) {
        std::cout << "Empty... Keep fishing!" << std::endl;
    }
    else if (dynamic_cast<Boot*>(field[userNumSet])) {
        throw std::runtime_error("GAME OVER! You caught a BOOT.");
    }
    else if (dynamic_cast<Fish*>(field[userNumSet])) {
        throw std::runtime_error("VICTORY! You caught a FISH!");
    }
}

bool checkInHistory(const int& userNum, std::vector<int>& historyStep) {
    if (userNum < 0 || userNum > 8)
        throw std::invalid_argument("Out of bounds (0-8)");

    for (int step : historyStep) {
        if (userNum == step)
            throw std::invalid_argument("Field already used");
    }
    historyStep.push_back(userNum);
    return true;
}

int main() {
    std::srand(std::time(nullptr));
    std::vector<int> historyStep;
    Item* Gamefield[9] = {nullptr};

    InitGameField(Gamefield);
    std::cout << "Game field is ready for play!" << std::endl;

    int counterStep = 0;
    while (true) {
        int userSetNumField;
        std::cout << "Enter sector: ";
        if (!(std::cin >> userSetNumField)) break;

        try {
            if (checkInHistory(userSetNumField, historyStep)) {
                counterStep++;
                checkSector(userSetNumField, Gamefield);
            }
        }
        catch (const std::invalid_argument &error) {
            std::cout << "Error: " << error.what() << std::endl;
        }
        catch (const std::runtime_error &finish) {
            std::cout << finish.what() << " Total steps: " << counterStep << std::endl;
            break;
        }
    }

    for (int i = 0; i < 9; i++) delete Gamefield[i];
    return 0;
}
