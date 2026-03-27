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
    int taskID = 0;

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
        if (getTaskID() >= 0) {
            int hash = getTaskID();
            countTask = (rand() % hash) + 1;
        } else {
            cout << "No tasks from the Headcomp" << endl;
            countTask = 0;
        }
        return countTask;
    }

    int getCountTask () {
        return countTask;
    }


};
class Workers: public Manager {
private:
    int group_a = 0;
    int group_b = 0;
    int group_c = 0;

    bool status_workers_group_a = false,
         status_workers_group_b = false,
         status_workers_group_c = false;

    int coefficientOneWorker = 2;


public:
    void setWorkrers (int group_a, int group_b, int group_c) {
        if (group_a > 10) {
            group_a = 10;
        }
        if (group_b > 10) {
            group_b = 10;
        }
        if (group_c > 10) {
            group_c = 10;
        }

        this->group_a = group_a;
        this->group_b = group_b;
        this->group_c = group_c;
    }

    bool getStatusWorkers () {
        if (group_a == 0 || group_b == 0 || group_c == 0) {
            return false;
        } else {
            return true;
        }
    }

    //логика распределения задач
    void DistributionOfTasks () {
        if (getStatusWorkers ()) {
            if (getCountTask() != 0) {

                int countTask = getCountTask ();
                int counter = 0;
                string commandUser = "";

                status_workers_group_a = status_workers_group_b = status_workers_group_c = false;

                while (countTask > 0) {

                    counter++;
                    cout << "Approach to completing tasks #"<< counter << endl;
                    if (group_a >= 1 && !status_workers_group_a) {
                        cout << "Group workers A a took on tasks in quantity:" << countTask - group_a << endl;
                        countTask -= group_a;
                        status_workers_group_a = true;
                    } else {
                        cout << "Worker group A already has tasks" << endl;
                    }
                    if (group_b >= 1 && !status_workers_group_b) {
                        cout << "Group workers B a took on tasks in quantity:" << countTask - group_b << endl;
                        countTask -= group_b;
                        status_workers_group_b = true;
                    } else {
                        cout << "Worker group B already has tasks" << endl;
                    }
                    if (group_c >= 1 && !status_workers_group_c) {
                        cout << "Group workers C a took on tasks in quantity:" << countTask - group_c << endl;
                        countTask -= group_c;
                        status_workers_group_c = true;
                    } else {
                        cout << "Worker group C already has tasks" << endl;
                    }

                    if (countTask < 0) {
                        cout << "The workers exceeded the plan" << endl;
                    }

                    cout << "If you want to continue the task, enter ~next~" << endl;

                    cin >>commandUser;
                    if (commandUser == "next") {

                        status_workers_group_a = false;
                        status_workers_group_b = false;
                        status_workers_group_c = false;

                    } else {
                        break;
                    }
                }


            } else {
                cout << "There is not a single task to complete at workers" << endl;
                return;
            }
        } else {
            cout << "No employee has been appointed" << endl;
            return;
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

    Workers CompanyUnit;

    do {
        if (command == Command) {
            listCommands();
        } else if (command == CEO) {
            cout << "Enter the name of the company's CEO:"; cin >> name;
            cout << "Enter the project name:"; cin >> tagProject;
            cout << "Enter the task ID:"; cin >> taskID;
            CompanyUnit.setInfAboutCEO (name,tagProject,taskID);
        }
        else if (command == CEOinf) {
            CompanyUnit.getAboutHead();
        } else if (command == Manage) {
            cout << "Enter the name of the company's Manage:"; cin >> name;
            CompanyUnit.setNameManager(name);
        } else if (command == ManageInf) {
            CompanyUnit.getAboutManager();
        } else if (command == GiveTask) {
            CompanyUnit.getIntParceTasks();
            CompanyUnit.DistributionOfTasks();
        } else if (command == AddWorker) {
            cout << "Set the number of workers for different groups"
                    "\n(The number of workers in each group is no more than 10):" << endl;
            int group_a, group_b, group_c;
            cout << "Count for group A:"; cin >> group_a;
            cout << "Count for group B:"; cin >> group_b;
            cout << "Count for group C:"; cin >> group_c;
            CompanyUnit.setWorkrers(group_a, group_b, group_c);
        }

        cout << "Enter num command:";
        cin >> command;
;
    } while (command != Exit);
    return 0;
}