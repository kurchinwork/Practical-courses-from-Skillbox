#include <iostream>

using namespace std;

class Animal {
protected:
    string name;
    int age;
    bool canDance = false,
         canSwin = false;

public:
    Animal (string name, int age, bool canDance = false, bool canSwin = false)
    : name (name), age (age), canDance (canDance), canSwin (canSwin) {};

    virtual void voice() = 0;
    virtual void showTalents() {
        if (canSwin) cout << name << " can swim!" << endl;
        if (canDance) cout << name << " can dance!" << endl;
    }
    // виртуальный деструктор
    virtual ~Animal() {}
};

class Dog : virtual public Animal {
public:
    Dog (string name, int age, bool canDance = false, bool canSwin = false)
    : Animal (name, age, canDance, canSwin) {};
    virtual void voice () {
        cout << name << " says: Bark" << endl;
    }
    virtual void showTalents () {
        if (canSwin == true) {
            cout << name << " can swim!" << endl;
        }
        if (canDance == true) {
            cout << name << " can dance!" << endl;
        }
    }
};
class Cat : virtual public Animal {
    public:

    Cat (string name, int age, bool canDance = false, bool canSwin = false)
    : Animal (name, age, canDance, canSwin) {};

    virtual void voice () {
        cout << name <<" says: Meow" << endl;
    }
    virtual void showTalents () {
        if (canSwin == true) {
            cout << name << " can swim!" << endl;
        }
        if (canDance == true) {
            cout << name << " can dance!" << endl;
        }
    }
};
int main() {
    Animal* OnceArray[3];

    OnceArray[0] = new Dog("Steve", 20, true, false);
    OnceArray[1] = new Cat("Ellie", 2, false, false);
    OnceArray[2] = new Cat("Basic", 3, true, true);

    for (int i = 0; i < 3; i++) {
        OnceArray[i]->voice();
        OnceArray[i]->showTalents();
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete OnceArray[i];
    }

    return 0;
}