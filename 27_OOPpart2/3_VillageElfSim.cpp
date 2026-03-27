#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

// класс для большой ветки, которая хранит дома
class BigBranch {
public:
    vector<string> houses; // индекс 0  сама большая ветка остальные - средние

    BigBranch() {
        int middleCount = rand() % 2 + 2; // 2-3 средние ветки
        houses.resize(middleCount + 1, "None");
    }
};

class Tree {
public:
    vector<BigBranch*> bigBranches;

    Tree() {
        int bigCount = rand() % 3 + 3; // 3-5 больших веток
        for (int i = 0; i < bigCount; ++i) {
            bigBranches.push_back(new BigBranch());
        }
    }

    ~Tree() {
        for (auto b : bigBranches) delete b;
    }
};

int main() {
    srand(time(0));
    vector<Tree*> forest;
    for (int i = 0; i < 5; ++i) forest.push_back(new Tree());

    // Заселение
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < forest[i]->bigBranches.size(); ++j) {
            for (int k = 0; k < forest[i]->bigBranches[j]->houses.size(); ++k) {
                cout << "Tree " << i + 1 << ", Big Branch " << j + 1
                     << (k == 0 ? " (Main)" : " (Middle " + to_string(k) + ")") << ". Name: ";
                string name;
                cin >> name;
                forest[i]->bigBranches[j]->houses[k] = name;
            }
        }
    }

    // Поиск
    cout << "\nEnter elf name to find neighbors: ";
    string searchName;
    cin >> searchName;

    bool found = false;
    for (int i = 0; i < 5; ++i) {
        for (auto branch : forest[i]->bigBranches) {
            bool inThisBranch = false;
            int neighbors = 0;

            for (const string& inhabitant : branch->houses) {
                if (inhabitant == searchName) inThisBranch = true;
                if (inhabitant != "None") neighbors++;
            }

            if (inThisBranch) {
                cout << "Neighbors count: " << neighbors - 1 << endl;
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) cout << "Elf not found." << endl;

    // очистка памяти
    for (auto t : forest) delete t;
    return 0;
}