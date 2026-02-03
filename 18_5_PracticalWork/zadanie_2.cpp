//
// Created by kurch on 03.02.2026.
//
#include <iostream>
using namespace std;

int jumpFunc(int countSt, int maxJump = 3) {
    if (countSt == 0) {
        return 1;
    }

    if (countSt < 0) {
        return 0;
    }

    int ways = 0;
    for (int jump = 1; jump <= maxJump; jump++) {
        ways += jumpFunc(countSt - jump, maxJump);
    }

    return ways;
}
int main () {
    int countSteps = 0,
        jumpOver = 0;

    cout << "Enter the number of steps:"; cin >> countSteps;
    cout << "The number that can jump over:"; cin >> jumpOver;
    cout << jumpFunc(countSteps, jumpOver);

    return 0;
}