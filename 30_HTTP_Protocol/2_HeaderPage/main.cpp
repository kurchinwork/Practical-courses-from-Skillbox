//
// Created by Ellies on 06.04.2026.
//
#include <iostream>
#include <cpr/cpr.h>

using namespace std;
using namespace cpr;

int main () {
    Response link = Get(Url{"https://httpbin.org/html"});

    if (link.status_code != 200) {
        cout << "Error connection" << endl;
        return 1;
    }

    size_t pos = link.text.find("<h1>");
    if (pos != string::npos) {
        size_t start = pos + 4;
        size_t end = link.text.find("</h1>", start);

        if (end != string::npos) {
            string h1_content = link.text.substr(start, end - start);
            cout << "Found: " << h1_content << endl;
        }
    } else {
        cout << "Tag <h1> not found" << endl;
    }

    return 0;
}
