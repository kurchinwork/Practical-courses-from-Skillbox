//
// Created by kurch on 04.02.2026.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void mainTask (ifstream &inputFile) {
    string lineFromFile,
            name = " ",
            surName = " ",
            datePayMent = " ",
            nameWithMaxSalary = " ",
            surNameWithMaxSalary = " ",
            maxdatePayMent = " ";
    int salary = 0,
        totalSalaryBudget = 0,
        maxSalary = 0;

    while (std::getline(inputFile, lineFromFile)) {
        std::istringstream parcingLine(lineFromFile);

        while (parcingLine >> name >> surName  >> salary >> datePayMent) { // обработка каждого слова
            totalSalaryBudget += salary;
            if (maxSalary < salary) { // услов я максимального
                maxSalary = salary;
                nameWithMaxSalary = name;
                surNameWithMaxSalary = surName;
                maxdatePayMent = datePayMent;
            }
        }
    }

    cout << "\nAmount spent on paying salaries: " << totalSalaryBudget
         << "\nThe biggest payment was received " << surNameWithMaxSalary
         << " " << nameWithMaxSalary << " " << maxSalary << " at " << maxdatePayMent;
    inputFile.close();
}

int main() {
    ifstream fileForRead("FilesForTask_3\\statement.txt");

    if (fileForRead.is_open()) {
        cout << "\n***The file has been successfully connected***";
        mainTask(fileForRead);
    } else {
        cout << "\nThe file has been failed.";
        return 1;
    }

    return 0;
}