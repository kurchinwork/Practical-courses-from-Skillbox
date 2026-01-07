#include <iostream>

int main () {
    float startAmpl, endAmpl;
    bool logic = true;
    while (logic) {
            std::cout << "Введите амплитуду начального отклонения в см:= "; std::cin >> startAmpl; std::cout << std::endl;
            std::cout << "Введите амплитуду конечного отклонения в см:= "; std::cin >> endAmpl; std::cout << std::endl;

            if (startAmpl > endAmpl && startAmpl > 0 && endAmpl > 0) {
                logic = false; 
            } else {
                std::cout << "Что-то не так в вводе, стартовая апмлитуда не может быть меньше конечной. Так же значения не могут быть отрицательными!\n";
            }
    }
    
    for (int i = 0; startAmpl > endAmpl; i++) {
        startAmpl *= 1.0f - 0.084f;
        if (startAmpl < endAmpl) {
            std::cout << "Маятник совершит " << i << " колебаний."; std::cout << std::endl;
        }
    }
}
