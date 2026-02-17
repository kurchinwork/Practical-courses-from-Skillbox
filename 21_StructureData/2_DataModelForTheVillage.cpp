//
// Created by kurch on 13.02.2026.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct house {

    float bedroom = 0.0f,
    kitchen = 0.0f,
    bathroom = 0.0f,
    childrensRoom = 0.0f,
    livingRoom = 0.0f,
    totalSqr = 0.0f;

    int countFloor = 0;
    vector<vector<float>> sqrFloor;

};
struct plotSqr {

    int numberPlot = 0;
    string titlePlot = "";

    float garage = 0.0f,
          bathhouse = 0.0f,
          barn = 0.0f,
          plotSqrt = 0.0f;

};

void resettingElements () {
    house descriptHouse;

    descriptHouse.bedroom = 0.0f;
    descriptHouse.childrensRoom = 0.0f;
    descriptHouse.livingRoom = 0.0f;
    descriptHouse.kitchen = 0.0f;
    descriptHouse.bathroom = 0.0f;
} //Обнуляю элементы для ввода данных поэтажам вызываю в initHouse
void initPlot() {
    plotSqr strctPlot;

    cout << "\n\tEnter the following information"
            "\nPlot name:"; getline(cin, strctPlot.titlePlot);

    cout << "Plot number (integer numbers only): "; cin >> strctPlot.numberPlot;
    cout << "<< Next data on 0.0f format >>\n";
    cout << "Sqr of garages: "; cin >> strctPlot.garage;
    cout << "Sqr of bathhouses: "; cin >> strctPlot.bathhouse;
    cout << "Sqr barns:"; cin >> strctPlot.barn;
} //сначала юзер вводит инфу об участке потом вводит дом и тд
void initHouse () {
    house descriptHouse;

    cout << "\nHow many floors are there in the building?"
            "\nEnter:"; cin >> descriptHouse.countFloor;
    cout << "Enter the proposed rooms in stages; if the room is not available, enter 0.";

   for (int i = 0; i < descriptHouse.countFloor; i++) {
       vector<float> allSqrFloor;
       resettingElements();

       cout << "\nEnter data floor #" << i + 1 << "." << endl;
       cout << "Sqr of bedroom: "; cin >> descriptHouse.bedroom;
       cout << "Sqr of childrens: "; cin >> descriptHouse.childrensRoom;
       cout << "Sqr of living: "; cin >> descriptHouse.livingRoom;
       cout << "Sqr of kitchen: "; cin >> descriptHouse.kitchen;
       cout << "Sqr of bathroom: "; cin >> descriptHouse.bathroom;

        if (!(descriptHouse.bedroom < 0 ||
            descriptHouse.childrensRoom < 0 ||
            descriptHouse.livingRoom < 0 ||
            descriptHouse.kitchen < 0 ||
            descriptHouse.bathroom < 0)) {

            allSqrFloor.push_back(descriptHouse.bedroom);
            allSqrFloor.push_back(descriptHouse.childrensRoom);
            allSqrFloor.push_back(descriptHouse.livingRoom);
            allSqrFloor.push_back(descriptHouse.kitchen);
            allSqrFloor.push_back(descriptHouse.bathroom);
            descriptHouse.sqrFloor.push_back(allSqrFloor);

            //Необходимо сюда добавить логику складывания поэтажной площади и типа вывести сколько квадратов дом
            //Потом организовать функцию что юзер вводит желаемую площадь расчета после идет расчет от занятой площади

            } else {
                cout << "\nInvalid Value";
                exit(1);
            }
    }
}

int main () {
    initPlot();
    initHouse();
}
