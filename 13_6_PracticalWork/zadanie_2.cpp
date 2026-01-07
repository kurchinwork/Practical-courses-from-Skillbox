//
// Created by kurchin ilya on 07.01.2026.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<float> prices {2.5, 4.25, 3.0, 10.0};
    vector<int> items {1, 1, 0, 3};

    cout << "\nPrices on product:" << endl;
    for (int i = 0; i < prices.size(); i++) {
        cout << prices[i] << " ";
    }

    cout << "\nCount products:" << endl;
    for (int i = 0; i < items.size(); i++) {
        cout << items[i] << " ";
    }

    float total = 0.0f;
    for (int i = 0; i < items.size(); i++) {
        if (items[i] >= 0 && items[i] <= prices.size()) {
            total += prices[items[i]];
        }
    }

    cout << "\nTotal cost: " << total;
}