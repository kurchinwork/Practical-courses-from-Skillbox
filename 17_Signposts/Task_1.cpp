//
// Created by kurch on 27.01.2026.
//
#include <iostream>
using namespace std;

void swapInt(int* a, int* b) {
    swap (*a, *b);
}

int main () {
    int a = 10,
        b = 20;
    swapInt(&a, &b);
    cout << a << " " << b;

    return 0;
}