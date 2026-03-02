//
// Created by kurch on 02.03.2026.
//
#include <iostream>
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

using namespace std;

int main() {
        int numDay;
        cout << "Enter num day:"; cin >> numDay;
        if (numDay < 1 || numDay > 7) {
                cout << "Invalid input. Please try again." << endl;
                return 0;
        }
        if (numDay == MONDAY)
                cout << "Monday" << endl;
        if (numDay == TUESDAY)
                cout << "Tuesday" << endl;
        if (numDay == WEDNESDAY)
                cout << "Wednesday" << endl;
        if (numDay == THURSDAY)
                cout << "Thursday" << endl;
        if (numDay == FRIDAY)
                cout << "Friday" << endl;
        if (numDay == SATURDAY)
                cout << "Saturday" << endl;
        if (numDay == SUNDAY)
                cout << "Sunday" << endl;
        return 0;
}