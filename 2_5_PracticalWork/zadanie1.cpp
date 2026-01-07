//Задание 1. Улучшаем гонщика

#include <iostream>

int main() {
    int isLap = 4;
    int engine = 254;
    int wheel = 93;
    int rudder = 49;
    int wind = 21;
    int rain = 17;
    int speed = engine + wheel + rudder - wind - rain;
 
    std::cout << "===================";
    std::cout << "\nСупер гонки. Круг " << isLap;
    std::cout << "\n===================";
    std::cout << "\nШумахер " << "(" << speed << ")";
    std::cout << "\n===================";
    std::cout << "\nВодитель: Шумахер";
    std::cout << "\nСкорость: " << speed;
    std::cout << "\n-------------------";
    std::cout << "\nОснащение";
    std::cout << "\nДвигатель: +" << engine;
    std::cout << "\nКолеса: +" << wheel;
    std::cout << "\nРуль: +" << rudder;
    std::cout << "\n-------------------";
    std::cout << "\nДействия плохой погоды";
    std::cout << "\nВетер: -" << wind;
    std::cout << "\nДождь: -" << rain;

}