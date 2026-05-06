//
// Created by kurchin_iu on 06.05.2026.
//
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    auto recursiveGetFileNamesByExtension = [](fs::path path, const std::string extension) {

        std::vector<std::string> fileNames;

        // 1. Проверяем, существует ли вообще такой путь, чтобы программа не упала
        if (fs::exists(path) && fs::is_directory(path)) {

            // 2. Запускаем рекурсивный итератор по указанному пути
            for (const auto& entry : fs::recursive_directory_iterator(path)) {

                // 3. Проверяем: это файл (не папка) И его расширение совпадает с искомым
                // Метод extension() возвращает расширение вместе с точкой, например ".txt"
                if (entry.is_regular_file() && entry.path().extension().compare(extension) == 0) {

                    // 4. Если всё совпало, берем только имя файла (filename)
                    // и превращаем его в обычную строку (string)
                    fileNames.push_back(entry.path().filename().string());
                }
            }
        }

        return fileNames;
    };

    std::string myPath = "C:\\MyFolder";
    std::string myExt = ".cpp";

    auto files = recursiveGetFileNamesByExtension(myPath, myExt);

    std::cout << "Found files:" << std::endl;
    for (const auto& name : files) {
        std::cout << name << std::endl;
    }

    return 0;
}