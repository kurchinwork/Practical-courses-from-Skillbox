// Задача 4. Обмен местами

#include <iostream>
//#include <windows.h>

int main()
{
    //SetConsoleOutputCP(1251); 
    //SetConsoleCP(1251); 
    /*Добавил эти две строки чтобы в консоли Visual studio
    корректно отображался русский язык*/

    int a = 42;
    int b = 153;
 
    std::cout << "a: " << a << "\n"; /* На экран будет выведено 42 */
    std::cout << "b: " << b << "\n"; /* На экран будет выведено 153 */

    a += b;
    b -= a;
    b *= -1;
    a -= b;

    std::cout << "a: " << a << "\n"; /* На экран будет выведено 153 */
    std::cout << "b: " << b << "\n"; /* На экран будет выведено 42 */
}