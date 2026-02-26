//
// Created by kurch on 18.02.2026.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct vectorStr {
    vector<float> x;
    vector<float> y;
    vector<float> tempVec;
};

void initList (vectorStr& vectorStr) {
    int vecXSize = 0;
    cout << "How many elements you want to add for vector #1?:"; cin >> vecXSize;
    "\nEnter list vector X: ";
    for (int i = 0; i < vecXSize; i++) {
        float x;
        cin >> x;
        vectorStr.x.push_back(x);
    }
    int vecYSize = 0;
    cout << "How many elements you want to add for vector #2?:"; cin >> vecYSize;
    "\nEnter list vector Y: ";
    for (int i = 0; i < vecYSize; i++) {
        float y;
        cin >> y;
        vectorStr.y.push_back(y);
    }
    /*int vecXSize = 0;
    string command = "";
    cout << "\nIf you want add elements in end the vectors, enter command:"
            "\n~push"
            "\nIf you want enter element from begin, enter command:"
            "\n~clear"
            "\nCommand:"; cin >> command;
    if (command == "push") {
        cout << "How many elements you want to add for vector #1?:"; cin >> vecXSize;
        "\nEnter list vector X: ";
        for (int i = 0; i < vecXSize; i++) {
            float x;
            cin >> x;
            vectorStr.x.push_back(x);
        }
        int vecYSize = 0;
        cout << "How many elements you want to add for vector #2?:"; cin >> vecYSize;
        "\nEnter list vector Y: ";
        for (int i = 0; i < vecYSize; i++) {
            float y;
            cin >> y;
            vectorStr.y.push_back(y);
        }
    }
    if (command == "clear") {
        vectorStr.x.clear();
        vectorStr.y.clear();
        cout << "All vector is clear";
        cout << "How many elements you want to add for vector #1?:"; cin >> vecXSize;
        "\nEnter list vector X: ";
        for (int i = 0; i < vecXSize; i++) {
            float x;
            cin >> x;
            vectorStr.x.push_back(x);
        }
        int vecYSize = 0;
        cout << "How many elements you want to add for vector #2?:"; cin >> vecYSize;
        "\nEnter list vector Y: ";
        for (int i = 0; i < vecYSize; i++) {
            float y;
            cin >> y;
            vectorStr.y.push_back(y);
        }
    }*/ //Отказался от этого решения решил не усложнять
}
void outVector (vectorStr& vectorStr) {
    cout << "\nVector X include: " << vectorStr.x.size() << " elements with num: " << endl;
    for (int i = 0; i < vectorStr.x.size(); i++) {
        cout << vectorStr.x[i] << " ";
    }
    cout << "\nVector Y include: " << vectorStr.y.size() << " elements with num: " << endl;
    for (int i = 0; i < vectorStr.y.size(); i++) {
        cout << vectorStr.y[i] << " ";
    }
    cout << "\nTemp vector include: " << vectorStr.tempVec.size() << " elements with num: " << endl;
    for (int i = 0; i < vectorStr.tempVec.size(); i++) {
        cout << vectorStr.tempVec[i] << " ";
    }

}
void add (vectorStr& vectorStr) {
    if (vectorStr.x.size() == vectorStr.y.size()) {
        cout << "\nAdding two vectors is the:";
        for (int i = 0; i < vectorStr.x.size(); i++) {
            vectorStr.tempVec.push_back( vectorStr.x[i] + vectorStr.y[i]);
        }
        cout << "\nCommand is succesfully comleted"
                "\nCheck result in out command;";
    } else {
        cout << "\nAdding is failed, because vector is not equals"
                "\nTry init vectors again;";
    }
}
void substract (vectorStr& vectorStr) {
    if (vectorStr.x.size() == vectorStr.y.size()) {
        cout << "\nSubstracting two vectors is the:";
        for (int i = 0; i < vectorStr.x.size(); i++) {
            vectorStr.tempVec.push_back( vectorStr.x[i] - vectorStr.y[i]);
        }
        cout << "\nCommand is succesfully comleted"
                "\nCheck result in out command;";
    } else {
        cout << "\nAdding is failed, because vector is not equals"
                "\nTry init vectors again;";
    }
}
void multiply (vectorStr& vectorStr) {
    if (vectorStr.x.size() == vectorStr.y.size()) {
        cout << "\nMultiply two vectors is the:";
        float tempEl = 0.0f;
        for (int i = 0; i < vectorStr.x.size(); i++) {
            tempEl += vectorStr.x[i] + vectorStr.y[i];
        }
        vectorStr.tempVec.push_back(tempEl);
        cout << "\nCommand is succesfully comleted"
                "\nCheck result in out command;";
    } else {
        cout << "\nAdding is failed, because vector is not equals"
                "\nTry init vectors again;";
    }
}
void len (vectorStr& vectorStr) {
    cout << "\nSize vector X: " << sizeof(vectorStr.x) << ". "
            "\nLenght: " << size(vectorStr.x);
    cout << "\nSize vector Y: " << sizeof(vectorStr.y) << ". "
            "\nLenght: " << size(vectorStr.y);
    cout << "\nSize vector TempVec: " << sizeof(vectorStr.tempVec) << ". "
            "\nLenght: " << size(vectorStr.tempVec);
}
void normalize (vectorStr& vectorStr) {
    /*Математическое определение
Для вектора v = (x₁, x₂, ..., xₙ) нормализованный вектор û вычисляется как:
û = v / ||v||
где ||v|| — длина (норма) вектора
Длина вектора вычисляется:
||v|| = √(x₁² + x₂² + ... + xₙ²)*/
    float lenghtVecNormalize = 0.0f,
          tempX = 0.0f;
    for (int i = 0; i < vectorStr.x.size(); i++) {
        tempX += pow(vectorStr.x[i], 2);
    }
    lenghtVecNormalize = sqrt(tempX);
    for (int i = 0; i < vectorStr.x.size(); i++) {
        vectorStr.tempVec.push_back(vectorStr.x[i] / lenghtVecNormalize);
    }
    cout << "\nNormalized vector X is completed";
}
void clear (vectorStr& vectorStr) {
    string command = "";
    cout << "\n~Enter command - all, for delete all elements, from all vectors;"
            "\n~Enter command - tempVec for clear only him;"
            "\nEnter:"; cin >> command;
    if (command == "all") {
        vectorStr.tempVec.clear();
        vectorStr.x.clear();
        vectorStr.y.clear();
        cout << "\nCommand is succesfully comleted";
    } else if (command == "tempVec") {
        vectorStr.tempVec.clear();
        cout << "\nCommand is succesfully comleted";
    } else {
        cout << "\nCommand is invalid try again!";
    }
}

int main () {
    vectorStr vectorStr;
    string command = "";
    while (true) {
        cout << "\n\a*******************************************"
                "\nChoise what you want to do:"
                "\n~Init vector elements is the - init command;"
                "\n~Out all vectors and elements - out command;"
                "\n~Clear elements - clear command;"
                "\n~"
                "\n~Adding two vectors is the - add command;"
                "\n~Subtracting two vectors is the - subtract command;"
                "\n~Multiplying a vector by a scalar is the - multiply command;"
                "\n~Finding the length of a vector is the - length command;"
                "\n~Normalizing a vector is the - normalize command."
                "\n~"
                "\n~For exit is the - exit command;"
                "\nCommand:"; cin >> command;

        if (command == "init") {
            initList(vectorStr);
        }
        if (command == "out") {
            outVector(vectorStr);
        }
        if (command == "clear") {
            clear(vectorStr);
        }
        if (command == "add") {
            add(vectorStr);
        }
        if (command == "subtract") {
            substract(vectorStr);
        }
        if (command == "multiply") {
            multiply (vectorStr);
        }
        if (command == "length") {
            len(vectorStr);
        }
        if (command == "normalize") {
            normalize(vectorStr);
        }
        if (command == "exit") {
            cout << "\nCommand is succesfully comleted"
                    "\nProgramm is terminate";
            return 0;
        }
    }
}