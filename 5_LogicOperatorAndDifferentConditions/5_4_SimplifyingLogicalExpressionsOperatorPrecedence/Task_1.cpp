#include <iostream>

int main () {
    int height, weight, hours, paramsBodyHand, paramsBodyLeg, sum = 0;
    std::string  eyeColor, name;

    std::cout << "\nВведите имя кандидата: "; std::cin >> name;
    std::cout << "\nРост: "; std::cin >> height;
    std::cout << "\nВес: "; std::cin >> weight;
    std::cout << "\nВведите количество рук: "; std::cin >> paramsBodyHand;
    std::cout << "\nВведите количество ног: "; std::cin >> paramsBodyLeg;
    std::cout << "\nКакой цвет глаз у кандидата?: "; std::cin >> eyeColor;
    std::cout << "\nСколько часов человек налетал?: "; std::cin >> hours;
    
    if (height >= 145 && height <= 165 || weight >= 45 && weight <= 65) 
    {
        sum += 2;
    } if (paramsBodyHand == 2 && paramsBodyLeg == 2) {
        sum += 1;
    } if (eyeColor != "Зеленый") {
        sum += 1;
    }
    if (sum == 4 || hours >= 100) {
       std::cout << "\nКандидат с именем " << name << " подходит к службе."; 
    } else {
        std::cout << "\nКандидат с именем " << name << " не годен к службе.";
    }    
}
    
    
    