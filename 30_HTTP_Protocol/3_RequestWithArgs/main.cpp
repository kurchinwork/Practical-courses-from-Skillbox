#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cpr/cpr.h>

using namespace std;

int main() {
    map<string, string> arguments;
    string key, value;

    // Цикл ввода данных
    while (true) {
        cout << "Enter key (or 'get'/'post'): ";
        cin >> key;
        if (key == "get" || key == "post") break;

        cout << "Enter value: ";
        cin >> value;
        arguments[key] = value;
    }

    if (key == "get") {
        // Формируем GET запрос
        cpr::Parameters params;
        for (auto it = arguments.begin(); it != arguments.end(); ++it) {
            params.Add({it->first, it->second});
        }
        auto r = cpr::Get(cpr::Url{"https://httpbin.org"}, params);
        cout << "--- GET RESPONSE ---\n" << r.text << endl;

    } else if (key == "post") {
        // Формируем POST запрос через Payload и итераторы
        vector<cpr::Pair> payload_vec;
        for (auto it = arguments.begin(); it != arguments.end(); ++it) {
            payload_vec.push_back(cpr::Pair((string)it->first, (string)it->second));
        }

        auto r = cpr::Post(cpr::Url{"https://httpbin.org"},
                           cpr::Payload(payload_vec.begin(), payload_vec.end()));
        cout << "--- POST RESPONSE ---\n" << r.text << endl;
    }

    return 0;
}