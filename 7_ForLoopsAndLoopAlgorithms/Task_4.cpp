/*Напишите программу, которая рисует с помощью символьной графики прямоугольную рамку. 
Для вертикальных линий используйте символ вертикального штриха «|», 
а для горизонтальных — дефис «-». Пусть пользователь вводит ширину и высоту рамки.*/

#include <iostream>

int main() {
    int width, height;
    std::cout << "Введите ширину и высоту рамки: ";
    std::cin >> width >> height;
    
    for (int i = 0; i < height; i++) {
        if (i == 0 || i == height - 1) {
            std::cout << "|";
            for (int j = 0; j < width - 2; j++) {
                std::cout << "-";
            }
            if (width > 1) {
                std::cout << "|";
            }
        } else {
            std::cout << "|";
            for (int j = 0; j < width - 2; j++) {
                std::cout << " ";
            }
            if (width > 1) {
                std::cout << "|";
            }
        }
        std::cout << "\n";
    }
}