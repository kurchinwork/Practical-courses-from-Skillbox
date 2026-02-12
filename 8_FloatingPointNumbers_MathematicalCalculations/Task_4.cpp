#include <iostream>
#include <iomanip>

int main () {
    float fileSize, downloadSpeed, downloadedFile = 0.0f, percent;
    std::cout << "Укажите размер файла для скачивания в МБ:= "; std::cin >> fileSize; std::cout << std::endl;
    std::cout << "Укажите среднюю скорость подключения:= "; std::cin >> downloadSpeed; std::cout << std::endl;

    std::cout << "***Старт расчета***"; std::cout << std::endl;
    
    for (int i = 1; downloadedFile < fileSize ; ++i) {
        downloadedFile += downloadSpeed;
        percent = (downloadedFile / fileSize) * 100;
        std::cout << "Прошло " << i << " секунд, скачано " << downloadedFile << " МБ.  (" << percent << " %)." << std::fixed << std::setprecision(1); std::cout << std::endl;
    }
}