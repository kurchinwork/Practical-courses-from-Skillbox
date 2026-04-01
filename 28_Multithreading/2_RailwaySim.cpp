//
// Created by kurchin_iu on 31.03.2026.
//
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>
#include <iostream>

using namespace std;

class Train {
private:
    string nameTrain = "Untitled";
    int timeToRailway = 1;
public:
    Train (string name, int timeToRailway) {
        if (timeToRailway > 100) {
            timeToRailway = 100;
        }
        if (timeToRailway <= 0) {
            timeToRailway = 1;
        }
        this->nameTrain = name;
        this->timeToRailway = timeToRailway;
    }
    string getName() {
        return nameTrain;
    }
    int getTimeToRailway() {
        return timeToRailway;
    }
};

mutex station_mutex;

void trainMoving (string nameTrain, int timeToRailway) {
    this_thread::sleep_for(chrono::seconds(timeToRailway));

    station_mutex.lock();
    //cout << "lock";
    cout << "Train  " << nameTrain << " ARRIVED at the station! (Travel time: " << timeToRailway << "s)" << endl;

    cout << "Enter command ~detach~ for next:";
    string command;
    while (true) {
        cin >> command;
        if (command == "detach") {
            cout << "Train leave from station. Wait next train" << endl;
            break;
        } else {
            cout << "Invalid command. Try again." << endl;
        }
    }
    station_mutex.unlock();
    //cout << "unlock";
}


int main() {
    /*    int time = 0;
     *    cout << "\nSet time for train A:"; cin >> time;
    *     Train* trainA = new Train("A", time);
    *
    *     cout << "\nSet time for train B:"; cin >> time;
          Train* trainB = new Train("B", time);

          cout << "\nSet time for train C:"; cin >> time;
          Train* trainC = new Train("C", time);
     */
    Train* trainA = new Train("A", 4);
    Train* trainB = new Train("B", 5);
    Train* trainC = new Train("C",2);

    cout << "Starting work railways..." << endl
         << "Train " << trainA->getName() << " has been starting moving."
         << " Waiting " << trainA->getTimeToRailway() << " seconds." << endl;

    cout << "Train " << trainB->getName() << " has been starting moving."
         << " Waiting " << trainB->getTimeToRailway() << " seconds." << endl;

    cout << "Train " << trainC->getName() << " has been starting moving."
         << " Waiting " << trainC->getTimeToRailway() << " seconds." << endl;

    thread train_a(trainMoving, trainA->getName(), trainA->getTimeToRailway());
    thread train_b(trainMoving, trainB->getName(), trainB->getTimeToRailway());
    thread train_c(trainMoving, trainC->getName(), trainC->getTimeToRailway());

    train_a.join();
    train_b.join();
    train_c.join();

    delete trainA;
    delete trainB;
    delete trainC;

    return 0;
}
