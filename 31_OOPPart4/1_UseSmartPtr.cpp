//
// Created by Ellies on 12.04.2026.
//

#include <iostream>
#include <memory>

using namespace std;

class Toy {
private:
    string nameToy;
public:

    Toy (const string& nameToy_): nameToy(nameToy_) {};

    string getName() {
        return nameToy;
    }

    ~Toy() {
        cout << "Toy " << getName() << " was dropped " << endl;
    }
};

class Dog {
private:

    string nameDog;
    shared_ptr<Toy> ToyForDog; //умный указатель на игрушку

public:
    Dog (string name): nameDog(name), ToyForDog(nullptr) {};

    void getToy (const shared_ptr<Toy>& newToy) {
        if (ToyForDog == newToy) {
            cout << "This toy was created before" << endl;
            return;
        }

        if (newToy.use_count() > 1) {
            cout << "Whoever played with this toy" << endl;
            return;
        }

        ToyForDog = newToy;
        cout << nameDog << " take up toy " << endl;
    }

    void dropToy () {
        if (ToyForDog == nullptr) {
            cout << nameDog << " dont have a toy" << endl;
        } else {
            ToyForDog = nullptr;
            cout << nameDog << " drop toy" << endl;
        }
    }

};

int main () {
    shared_ptr<Toy> Rabbit = make_shared<Toy> ("Rabbit");

    Dog DogOne("Rex");
    Dog DogTwo("Charlie");

    DogOne.getToy(Rabbit);
    DogTwo.getToy(Rabbit);

    DogOne.dropToy();
    DogTwo.getToy(Rabbit);

    return 0;
}
