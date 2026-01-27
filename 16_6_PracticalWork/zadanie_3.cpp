//
// Created by kurch on 26.01.2026.
//
#include <iostream>
#include <sstream>

using namespace std;

enum symbolArith {
    plus = '+', minus = '-', multiply = '*', divide = '/'
};

int main () {
    string stringForArithmetic = "";
    double a = 0, b = 0;
    char arithmeticOperation;
    bool logicCalc = true;

    cout << "The string is written in the form <number-1><action><number-2> (without spaces).\n";

    while (logicCalc) {
        int countOperation = 0;
        cout << "\nEnter an arithmetic expression: ";
        cin >> stringForArithmetic;
        for (int i = 0; i < stringForArithmetic.length(); i++) {
            if (stringForArithmetic[i] == '*' ||
                stringForArithmetic[i] == '/' ||
                stringForArithmetic[i] == '+' ||
                stringForArithmetic[i] == '-')
                countOperation++;
        }
        if (countOperation > 1) {
            cout << "\nNo more than two arithmetic operations!"
                    "\nTry again!";
        } else {
            logicCalc = false;
        }
    }

    stringstream buffer_stream (stringForArithmetic);
    buffer_stream >> a >> arithmeticOperation >> b;

    /* Чтобы разделить полученную строку на отдельные элементы — числа и оператор, воспользуйтесь строковым потоком.
     * Для этого создайте пустую строку std::string buffer и дайте пользователю возможность при помощи std::cin ввести в неё команду.
     * Затем оберните полученную строку так: std::stringstream buffer_stream(buffer);
     * Это позволит вам получить каждый из трёх компонентов команды: buffer_stream >> a >> operation >> b;*/

    if (arithmeticOperation == symbolArith::plus)
        cout << "\nResult: " << a << " " << arithmeticOperation << " " << b << " = " << a + b <<endl;

    if (arithmeticOperation == symbolArith::minus)
        cout << "\nResult: " << a << " " << arithmeticOperation << " " << b << " = " << a - b <<endl;

    if (arithmeticOperation == symbolArith::multiply)
        cout << "\nResult: " << a << " " << arithmeticOperation << " " << b << " = " << a * b <<endl;

    if (arithmeticOperation == symbolArith::divide) {
        if (b == 0 || a == 0) {
            cout << "\nYou can't divide by zero!"
                    "\nResult: " << a << " " << arithmeticOperation << " " << b << " = " << 0 <<endl;
        } else {
            cout << "\nResult: " << a << " " << arithmeticOperation << " " << b << " = " << a / b <<endl;
        }
    }

    return 0;
}