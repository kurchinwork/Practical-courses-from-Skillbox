//
// Created by kurch on 27.01.2026.
//
#include <iostream>
using namespace std;

void outInitlist (int* initList) {
    for (int i = 10; i > 0; i--) {
        cout << initList[i] << " ";
    }
}

int main () {
    int list[10];
    for (int i = 0; i <= 10; i++) {
        list[i] = i;
    }
    outInitlist(list);

    return 0;
}