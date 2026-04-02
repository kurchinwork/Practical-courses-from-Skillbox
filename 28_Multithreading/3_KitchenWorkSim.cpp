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
public:
    Dish(string name, int time) : nameDish(name), cookingTime(time) {}

    friend class KitchenWorkSim;
};

class KitchenWorkSim {
private:
    vector<Dish> dishsList;
    int countCookedDish = 0;
    int deliveryInProgress = 0;

public:

    void OutDishDone (string nameDish, int cookingTime) {
        this_thread::sleep_for(chrono::seconds(cookingTime));

        lock_guard lock(cooking_mx);
        cout << "\n~~~~~~!!!!!!!!!!!~~~~~~"
                "\nDish: " << nameDish << " will be cooking at " << cookingTime << " sec."<< endl;
        countCookedDish++;

        cout << "\n\nEnter name dish "
                "\n(or 'List'/'Done'): " << endl;
        cout.flush(); //это команда, которая принудительно выталкивает всё содержимое буфера в консоль «прямо сейчас».
    }
    void StartDelivery(int id) {

        this_thread::sleep_for(chrono::seconds(30));

        lock_guard lock(cooking_mx);
        cout << "\n~~~~~~DOSTAVKA SUCCESS~~~~~~"
                "\nOrder #" << id << " has been delivered!" << endl;

        cout << "Enter name dish (or 'List'/'Delivery'/'Done'): ";
        cout.flush();
    }


    //сразу передаю конструктор для добавления в вектор
    void AddDishInList (string nameDish, int cookingTime) {
        dishsList.emplace_back(nameDish, cookingTime);

        thread treadCooking(& KitchenWorkSim::OutDishDone, this, nameDish, cookingTime);

        // ЗАПУСК ПОТОКА: (памятка)
        // 1. &KitchenWorkSim::OutDishDone — адрес метода
        // 2. this — указатель на текущий объект класса
        // 3. nameDish, cookingTime — аргументы метода

        // Отсоединяем поток, чтобы он жил своей жизнью
        treadCooking.detach();



    }

    void OutDishList () {
        for (int i = 0; i < dishsList.size(); i++) {
            cout << "Dish #"<< i + 1 << " : " << dishsList.at(i).nameDish << " cooking " << dishsList.at(i).cookingTime << " sec."<< endl;
        }
        lock_guard lock(cooking_mx);
    }

    void delivery () {
        lock_guard lock(cooking_mx);
        if (countCookedDish <= 0) {
            cout << "Net gotovih blud" << endl;
        } else {
            countCookedDish--; // забираем одно готовое блюдо
            deliveryInProgress++;

            cout << "\nKurjer starting dostavka..." << endl;

            // поток доставки
            thread t(&KitchenWorkSim::StartDelivery, this, deliveryInProgress);
            t.detach();

        }
    }
};

int main() {
    KitchenWorkSim kitchenWorkSim;

    srand(time(0));

    string command;

    cout << "Enter the dishes you want to add to the cooking list." << endl
         << "~Done - stops initialize list" << endl
         << "~List - out all dishes" << endl <<
            "~Delivery - to give zakaz to dostavka" << endl;

    do {
        command = "";

        cout << "Enter name dish:";
        cin >> command;

        if (command == "Done") break;
        if (command == "List") {
                kitchenWorkSim.OutDishList();
        }
        if (command == "Delivery") {
            kitchenWorkSim.delivery();
        } else {
            kitchenWorkSim.AddDishInList(command, rand() % 10 + 5);
        }

    } while (true);
}

