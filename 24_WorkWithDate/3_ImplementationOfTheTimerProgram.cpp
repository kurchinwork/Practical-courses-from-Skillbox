//
// Created by kurchin_iu on 10.03.2026.
//
#include <iostream>
#include <sstream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

int main () {
    int minuts = 0,
        seconds = 0,
        totalSec = 0;

    string timerSet;
    char delimiter = ':';
    stringstream currentTimeParce;

    bool checkTimeSet = (minuts >= 0 && minuts < 60) && (seconds > 0 && seconds < 60);

    do {
        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);

        currentTimeParce << put_time(localtime(&now_time), "%H:%M:%S");
        cout << "\nCurrent time: " << currentTimeParce.str() << endl;

        cout << "\nEnter timer set (only in format mm:ss):"; cin >> timerSet;

        stringstream timerInit(timerSet);
        timerInit >> minuts >> delimiter >> seconds;

        bool checkTimeSet = (minuts >= 0 && minuts < 60) && (seconds >= 0 && seconds < 60);

        if (!checkTimeSet) {
            cout << "\nInvalid time in format."
                    "\nMax timer set 59:59";
            currentTimeParce.str("");
        } else {
            break;
        }
    } while (true);

    totalSec = minuts * 60 + seconds; // общее количество секунд для таймера
    cout << "\nTimer has benn started!" << endl;
    auto now = chrono::system_clock::now();
    auto target_time = now + chrono::seconds(totalSec);

    while (chrono::system_clock::now() < target_time) {
        auto current = chrono::system_clock::now();
        auto remaining = chrono::duration_cast<chrono::seconds>(
            target_time - current
        ).count();

        // remaining содержит количество оставшихся секунд
        int rem_minutes = remaining / 60;
        int rem_seconds = remaining % 60;

        cout << setfill('0') << setw(2) << rem_minutes << ":"
             << setfill('0') << setw(2) << rem_seconds << endl;

        // задержка
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "\nDing!"
            "\nDing!"
            "\nDing!";

    return 0;
}