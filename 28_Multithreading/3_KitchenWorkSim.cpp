//
// Created by kurchin_iu on 31.03.2026.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <vector>

using namespace std;

mutex cooking_mx;

class Dish {
private:
    string nameDish = "Unknown";
    int cookingTime = 0;

    bool statusLocked = false;
public:
    Dish(string name, int time) : nameDish(name), cookingTime(time) {}

    friend class KitchenWorkSim;
};

class KitchenWorkSim {
private:
    vector<Dish> dishsList;
public:

    void OutDishDone (string nameDish, int cookingTime) {
        this_thread::sleep_for(chrono::seconds(cookingTime));

        cout << "~~~~~~!!!!!!!!!!!~~~~~~"
                "\nDish: " << nameDish << " will be cooking at " << cookingTime << " sec."<< endl;
    }

    //сразу передаю конструктор для добавления в вектор
    void AddDishInList (string nameDish, int cookingTime) {
        dishsList.emplace_back(nameDish, cookingTime);
        OutDishDone(nameDish, cookingTime);




    }

    void OutDishList () {
        for (int i = 0; i < dishsList.size(); i++) {
            cout << "Dish #"<< i + 1 << " : " << dishsList.at(i).nameDish << " cooking " << dishsList.at(i).cookingTime << " sec."<< endl;
        }
    }



};

int main() {
    KitchenWorkSim kitchenWorkSim;

    srand(time(0));

    string command;

    cout << "Enter the dishes you want to add to the cooking list." << endl
         << "~Done - stops initialize list" << endl
         << "~List - out all dishes" << endl;

    do {
        command = "";

        cout << "Enter name dish:";
        cin >> command;

        if (command == "Done") break;
        if (command == "List") {
            kitchenWorkSim.OutDishList();
        } else {
            kitchenWorkSim.AddDishInList(command, rand() % 10 + 5);
        }
    } while (true);
}

