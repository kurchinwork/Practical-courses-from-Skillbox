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
    livingRoom = 0.0f;

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
}
void initPlot() {
    plotSqr strctPlot;

    cout << "\nEnter the following information:"
            "\n   Plot name:"; getline(cin, strctPlot.titlePlot);

    cout << "Plot number (integer numbers only), sqr of garages, sqr of bathhouses, and sqr barns (0.0 format for every):" << endl;
    cin >> strctPlot.numberPlot
        >> strctPlot.garage
        >> strctPlot.bathhouse
        >> strctPlot.barn;
}
void initHouse () {
    house descriptHouse;

    cout << "\nHow many floors are there in the building?"; cin >> descriptHouse.countFloor;
    cout << "\nEnter the proposed rooms in stages; if the room is not available, enter 0.";

   for (int i = 0; i < descriptHouse.countFloor; i++) {
        vector<float> allSqrFloor;

        resettingElements();

        cout << "\nEnter data floor #" << i + 1 << "."
                "\nEnter the following information:"
                "\n   Sqr for bedroom, childrensroom, livingroom, kitchen, bathroom:" << endl;

        cin >> descriptHouse.bedroom
            >> descriptHouse.childrensRoom
            >> descriptHouse.livingRoom
            >> descriptHouse.kitchen
            >> descriptHouse.bathroom;

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
