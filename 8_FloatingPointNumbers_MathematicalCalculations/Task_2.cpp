#include <iostream>

int main () {

    float heatPoint, resist, damage = 0, score;
    bool logicIn = false, logicDamage = true, logicGame = true;
    int i;

    while (!logicIn) {
        std::cout << "\nВведите количество здоровья:= "; std::cin >> heatPoint;
        std::cout << "\nВведите уровень сопротивляемости магии в %:= "; std::cin >> resist; 

        if (heatPoint > 0 && resist >= 0 && resist <= 100) {
            logicIn = true; 
        }
        else {
            std::cout << "\nКоличество HP не может быть 1 ИЛИ Сопротивляемость не может быть меньше 0!!!";
            std::cout << "\n*******Повтор ввода**********\n";
            logicIn = false; 
        }

        heatPoint /= 100;
        resist /= 100;
    }

    while (logicGame) {
        std::cout << "\nВведите урон от огенного шара:= "; std::cin >> damage;
        damage /= 100;
        while (!logicDamage) {

            if (damage > 0.0f && damage <= 0.1f) {
                logicDamage = false; 
            }
            else {
                std::cout << "\nКоличество урона не должно быть меньше 0 и больше 100% !!!";
                std::cout << "\n*******Повтор ввода**********\n";
                logicDamage = true; 
            }
        }
        
        score = heatPoint - (resist * damage);
        heatPoint = score;
        ++i;

        std::cout << "Магический удар " << i << " урон " << damage << ", сопротивляемость " << resist << ", по орку будет нанесено " << damage * resist << ", осталось здоровья " << score * 100 << ".\n";

        if (score < 0) {
            std::cout << "\nОрк был убит за " << i << " ударов.";
            logicGame = false;
        }
    }
}