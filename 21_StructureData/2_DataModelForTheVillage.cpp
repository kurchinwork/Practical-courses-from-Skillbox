//
// Created by kurch on 13.02.2026.
//
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

struct house {

    float bedroom = 0.0f,
    kitchen = 0.0f,
    bathroom = 0.0f,
    childrensRoom = 0.0f,
    livingRoom = 0.0f,
    totalSqrHouse = 0.0f;

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

    //здесь не завожу вектор поскольку параметров участка которые содержатся в переменных считаю достаточно

};

void resettingElements (house& descriptHouse) {
    descriptHouse.bedroom = 0.0f;
    descriptHouse.childrensRoom = 0.0f;
    descriptHouse.livingRoom = 0.0f;
    descriptHouse.kitchen = 0.0f;
    descriptHouse.bathroom = 0.0f;
} //Обнуляю элементы для ввода данных по этажам вызываю в initHouse
void initPlot(plotSqr& strctPlot) {
    cout << "\n\tEnter the following information"
            "\nPlot name:"; getline(cin, strctPlot.titlePlot);

    cout << "Plot number (integer numbers only): "; cin >> strctPlot.numberPlot;
    cout << "<< Next data on 0.0f format >>\n";
    cout << "Sqr of garages: "; cin >> strctPlot.garage;
    cout << "Sqr of bathhouses: "; cin >> strctPlot.bathhouse;
    cout << "Sqr barns:"; cin >> strctPlot.barn;
    cout << "Total sqr plot: "; cin >> strctPlot.plotSqrt;
} //сначала юзер вводит инфу об участке потом вводит дом и тд
void initHouse (house& descriptHouse) {
    cout << "\nHow many floors are there in the building?"
            "\nEnter:"; cin >> descriptHouse.countFloor;
    cout << "Enter the proposed rooms in stages; if the room is not available, enter 0.";
    descriptHouse.totalSqrHouse = 0.0f;
    for (int i = 0; i < descriptHouse.countFloor; i++) {
        vector<float> allSqrFloor;
        resettingElements(descriptHouse);

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

            descriptHouse.totalSqrHouse += accumulate(allSqrFloor.begin(), allSqrFloor.end(), 0.0f);

            descriptHouse.sqrFloor.push_back(allSqrFloor);

            } else {
                cout << "\nInvalid Value";
                exit(1);
            }
    }
}
void outInfAboutPlotAndHouse (plotSqr& plotSqr, house& descriptHouse) {
    cout << "\nYou have entered the following parameters for plot number #" << plotSqr.numberPlot <<
            "\n~Name: " << plotSqr.titlePlot <<
            "\n~Size of garages: " << plotSqr.garage << " sq m"
            "\n~Size of bathhouses: " << plotSqr.bathhouse << " sq m"
            "\n~Size of barn: " << plotSqr.barn<< " sq m"
            "\n~Total size plot: " << plotSqr.plotSqrt << " sq m";

    cout << "\n\n*****************************************************"
            "\nOn the plot '" << plotSqr.titlePlot << "' place house with " << descriptHouse.countFloor << " floors."
            "\nTotal sqr house: " << descriptHouse.totalSqrHouse << " sq m";

    float totalSqrAllBuildingOnPlot = descriptHouse.totalSqrHouse  + plotSqr.garage + plotSqr.barn + plotSqr.bathhouse;
    float percentageOfаOccupiedTerritory = (totalSqrAllBuildingOnPlot / plotSqr.plotSqrt) * 100.0f;
    cout << "\nPercentage of occupied territory " << percentageOfаOccupiedTerritory << "%";
}


int main () {
    house descriptHouse;
    plotSqr strctPlot;
    initPlot(strctPlot);
    initHouse(descriptHouse);
    outInfAboutPlotAndHouse(strctPlot, descriptHouse);
}
