//
// Created by kurchin_iu on 10.03.2026.
//
#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>

using namespace std;

struct time_Struct {
    bool statusTask = false;
    time_t start, end;
    vector<vector<string>> historyTimers;
    vector<string> lineForIntInHistory;
};
//struct checkStatus {
//    bool statusTask = true;
//};
//функция для накапливания статуса, чтобы обращаться к строке вектора допустим и записывать каждую данную
//функция вывода по команде статус
//функция бегина и энда         tmStrct.historyTimers.push_back(tmStrct.lineForIntInHistory); //для вывода истории и статуса

//сделать функцию конвертации из сек в мин и часы
vector<string> ReturnSecondsToHours (double seconds) {
    vector<string> lineForReturn;

    if (seconds > 0.0) {
        lineForReturn.push_back("  The task took " );
        if ((seconds / 3600) > 1) {
            double hours = seconds / 3600;
            seconds -= hours * 3600;
            lineForReturn.push_back(to_string(hours) + " h ");
        }

        if ((seconds / 60) > 1) {
            double minutes = seconds / 60;
            seconds -= minutes * 60;
            lineForReturn.push_back(" " + to_string(minutes) + " min ");
        }

        if (seconds > 0) {
            lineForReturn.push_back(" " + to_string(seconds) + " sec ");
        }
        lineForReturn.push_back(" to complete.");
    } else {
        lineForReturn.push_back(" !Time not registered.");
    }
    return lineForReturn;
}

void startTime (time_Struct& tmStrct) {
    if (tmStrct.statusTask == false) {

        tmStrct.statusTask = true;
        cout << "\nAll is okay!"
                "\nYou can do the task!"
                "\nEnter name task: ";
        string nameTask,
               currTimeForStart = " start in ";
        cin >> nameTask;


        tmStrct.lineForIntInHistory.push_back(nameTask);

        stringstream ss;

        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);

        ss << put_time(localtime(&now_time), "%H:%M:%S"); //привожу к SS чтобы добавить к вектору
        currTimeForStart += ss.str();

        time(&tmStrct.start); //старт отсчета

        tmStrct.lineForIntInHistory.push_back(currTimeForStart);
        cout << "Start time: " << put_time(localtime(&now_time), "%H:%M:%S");



    } else {
        cout << "\nAnother task has been started earlier, you need to complete it first!"
                "\nA new timer don't fixed time.";
    }
}
void endTime (time_Struct& tmStrct) {
    if (tmStrct.statusTask == true) {
        tmStrct.statusTask = false;

        time(&tmStrct.end); //конец таймера

        cout << "\nTimer has been stopped!" << endl;

        string nameTask,
               currTimeForEnd = " end in ";

        stringstream ss;

        auto now = std::chrono::system_clock::now();
        auto now_time = std::chrono::system_clock::to_time_t(now);

        ss << put_time(localtime(&now_time), "%H:%M:%S"); //привожу к SS чтобы добавить к вектору
        currTimeForEnd += ss.str();

        tmStrct.lineForIntInHistory.push_back(currTimeForEnd);

        for (const auto& str : tmStrct.lineForIntInHistory) {
            std::cout << str;
        }

        double seconds = difftime(tmStrct.end, tmStrct.start);
        tmStrct.historyTimers.push_back(tmStrct.lineForIntInHistory);
        tmStrct.historyTimers.push_back(ReturnSecondsToHours(seconds));

        tmStrct.lineForIntInHistory.clear();


        //добавление вектора в общий векктор статус
    } else {
        cout << "\nNoone task has been not started";
    }
}

//в статус сделал два положения, если таймер работает то выдает что таймер еще не выключен, иначе выводит всю историю
void status (time_Struct& tmStrct) {
    if (tmStrct.statusTask == true) {
        cout << "\nFirst need switch Off timer.";
    } else {
        if (tmStrct.historyTimers.empty()) {
            cout << "\nPreviously, the timers did not work.";
        } else {
            for (const auto& taskRecord : tmStrct.historyTimers) {
                // taskRecord - это vector<string> с данными одной задачи
                for (const auto& part : taskRecord) {
                    cout << part;  // Выводим каждую часть записи
                }
                cout << endl;  // Новая строка после каждой задачи
            }
        }
    }
}

int main () {
    time_Struct tmStrct;
    do {
        cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
                "\nChoice next commands and enter them:"
                "\n~begin~ for start following time task;"
                "\n~end~ for stop following time task;"
                "\n~status~ for output status all tasks;"
                "\n~exut~ for exit program."
                "\nEnter choised command: ";

        string command; cin >> command;
        if (command == "begin") {
            startTime (tmStrct);
        } else if (command == "end") {
            endTime (tmStrct);
        } else if (command == "status") {
            status(tmStrct);
        } else if (command == "exit") {
            break;
        } else {
            cout << "\nInvalid command. Try again.";
        }
    } while (true);

    return 0;
}