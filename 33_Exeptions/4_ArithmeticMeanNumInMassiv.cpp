#include <iostream>

template <typename T>
void input(T array[8]) {
    std::cout << "Enter 8 numbers: ";
    for (int i = 0; i < 8; ++i) {
        std::cin >> array[i];
    }
}

template <typename T>
T calculateAverage(T array[8]) {
    T sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += array[i];
    }
    return sum / static_cast<T>(8);
}

int main() {

    double doubleArray[8];
    input(doubleArray);
    std::cout << "Average (double): " << calculateAverage(doubleArray) << std::endl;

    int intArray[8];
    input(intArray);
    std::cout << "Average (int): " << calculateAverage(intArray) << std::endl;

    return 0;
}