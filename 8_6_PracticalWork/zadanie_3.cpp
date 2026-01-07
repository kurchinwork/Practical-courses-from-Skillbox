#include <iostream>

int main () {

    int countCube, count_27 = 0, count_4 = 0;
    float x, y, z;
    bool logicIn = true;

    while (logicIn) {
        std::cout << "\nВведите размеры бруска:"; std::cout << std::endl;
        std::cout << "X:= "; std::cin >> x; std::cout << std::endl;
        std::cout << "Y:= "; std::cin >> y; std::cout << std::endl;
        std::cout << "Z:= "; std::cin >> z; std::cout << std::endl;

        if (x > 4 && y > 4 && z > 4) {
            logicIn = false; 
        }
        else {
            std::cout << "\nПроверьте правильность ввода!";
            std::cout << "\n*******Повтор ввода**********\n";
            logicIn = true; 
        }
    }

    std::cout << "\nСтандарт куба малого 5х5х5. V = 125.";
    countCube = (x * y * z) / 125;
    std::cout << "\nИз доски V = " << x * y * z << " изготовлено " << countCube << " малых кубов";

    while(countCube >= 27) {
        countCube -= 27;
        ++count_27;
    }

    while(countCube >= 4) {
        countCube -= 4;
        ++count_4;
    }
    
    std::cout << "\nНаборов по 27 кубиков = " << count_27 << "\nНаборов по 4 кубика = " << count_4 << "\nОстаток вне набора " << countCube << std::endl;

}

    