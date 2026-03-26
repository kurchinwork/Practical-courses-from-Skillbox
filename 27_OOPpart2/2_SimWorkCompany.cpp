//
// Created by kurchin_iu on 25.03.2026.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

enum Commands {
    CEO = 0,
    CEOinf = 1,
    Manage = 2,
    ManageInf = 3,
    GiveTask = 4,
    AddWorker = 5,
    Command = 99,
    Exit = 100
};

using namespace std;

class HeadCompany {
private:
    string name = "Whoever",
           tagProject = "Unknown";
    int taskID = 1;

public:
    void setInfAboutCEO (string& name, string& tagProject, int& taskID) {
        this->name = name;
        this->tagProject = tagProject;
        this->taskID = taskID;
    }

    void getAboutHead () {
        cout<< "Here's who issued the project: " << name << endl <<
               "Project name: " << tagProject << endl <<
               "Project ID: " << taskID << endl;
    }

    int getTaskID () {
        return taskID;
    }
};

class Manager: public HeadCompany {
private:
    string nameManager = "Whoever";
    int countTask = 0;

public:
    void setNameManager (string& nameManager) {
        this->nameManager = nameManager;
    }
    void getAboutManager () {
        cout << "Name manager:" << nameManager << endl;
    }

    int getIntParceTasks () {
        int hash = getTaskID();
        return (rand() % hash) + 1;
    }


};

class Workers: public Manager {
private:
    int group_a = 0;
    int group_b = 0;
    int group_c = 0;

public:
    void setWorkrers (int group_a, int group_b, int group_c) {
        this->group_a = group_a;
        this->group_b = group_b;
        this->group_c = group_c;

        if (group_a > 10) {
            group_a = 10;
        }
        if (group_b > 10) {
            group_b = 10;
        }
        if (group_c > 10) {
            group_c = 10;
        }
    }

    bool getStatusWorkers () {
        if (group_a == 0 || group_b == 0 || group_c == 0) {
            return false;
        } else {
            return true;
        }
    }

    void DistributionOfTasks () {
        if (getStatusWorkers ()) {

        } else {
            cout << "No employee has been appointed" << endl;
        }
    }



};

void listCommands () {
    cout << "\nList of commands:"
            "\n~0 - CEO - for init inf about head company"
            "\n~1 - CEOinf - for out inf about head company"
            "\n~2 - Manage - for init inf about manager"
            "\n~3 - ManageInf - for out inf about manager"
            "\n~4 - GiveTask - for init task to workers"
            "\n~5 - AddWorker - set count workers"
            "\n`````````````````````````````````````````````"
            "\n~99 - out list commands"
            "\n~100 - exit - for exit" << endl;
}

int main() {
    string name, tagProject;
    int taskID;
    int command = 99;
    srand(time(0));

    HeadCompany FirstHead;
    Manager FisrtManage;
    Workers ForFisrtManage;

    do {
        if (command == Command) {
            listCommands();
        } else if (command == CEO) {
            cout << "Enter the name of the company's CEO:"; cin >> name;
            cout << "Enter the project name:"; cin >> tagProject;
            cout << "Enter the task ID:"; cin >> taskID;
            FirstHead.setInfAboutCEO (name,tagProject,taskID);
        }
        else if (command == CEOinf) {
            FirstHead.getAboutHead();
        } else if (command == Manage) {
            cout << "Enter the name of the company's Manage:"; cin >> name;
            FisrtManage.setNameManager(name);
        } else if (command == ManageInf) {
            FisrtManage.getAboutManager();
        } else if (command == GiveTask) {

        } else if (command == AddWorker) {
            cout << "Set the number of workers for different groups"
                    "\n(The number of workers in each group is no more than 10):" << endl;
            int group_a, group_b, group_c;
            cout << "Count for group A:"; cin >> group_a;
            cout << "Count for group B:"; cin >> group_b;
            cout << "Count for group C:"; cin >> group_c;
            ForFisrtManage.setWorkrers(group_a, group_b, group_c);
        }

        cout << "Enter num command:";
        cin >> command;
;
    } while (command != Exit);
    return 0;
}