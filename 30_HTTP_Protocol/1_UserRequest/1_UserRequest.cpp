#include <iostream>
#include <cpr/cpr.h>

using namespace std;
using namespace cpr;

void getCommand(string& userLink) {
    Response link = Get(
    Url{userLink},
    Header{{"Authorization", "token YOUR_TOKEN_HERE"}});

    if (link.status_code != 200) {
        cout << "~Error" <<link.status_code << endl;
    } else if (link.status_code == 200) {
        cout << "~Connection success, status: " <<link.status_code <<
            "\nUrl: " << link.url << endl;
    }
}

void postCommand (string& userLink) {

    string username = "unknown",
           password = "";

    cout << "\nEnter you're Username: "; cin >> username;
    cout << "Enter password: "; cin >> password;
    Response link = Post(
                        Url{userLink+"/post"},
                        Payload{{"Username", username},
                                {"Password", password}});

    cout << "POST Response:\n" << link.text << std::endl;
}

void putCommand (string& userLink) {

    // Данные, которые мы хотим ОБНОВИТЬ (заменить старые)
    string updated_data = R"({"status": "online", "last_seen": "2026-04-07"})";

    Response link = Put(
                    Url{userLink+"/put"},
                    Body{updated_data},
                    Header{{"Content-Type", "application/json"}} // Обязательно указываем тип данных
    );

    if (link.status_code == 200) {
        cout << "Data has been update\n" << link.text << endl;
    } else {
        cout << "er";
        cout << link.text;
    }
}

void deleteCommand (string& userLink) {
    Response link = Delete(
    Url{userLink+"/delete"},
    Parameters{{"id", "123"}}
);
    if (link.status_code == 200) {
        cout << "~Delete has been succes!" << endl;
        cout << "response:\n" << link.text << endl;
    } else {
        cout << "Delete failed. Status: " << link.status_code << endl;
    }
}

void patchCommand (string& userLink) {
    // Меняем только статус, не трогая имя или другие данные пользователя
    string patch_data = R"({"status": "busy"})";

    Response link = Patch(
        Url{userLink+"/patch"},
        Body{patch_data},
        Header{{"Content-Type", "application/json"}}
    );

    if (link.status_code == 200) {
        cout << "Has been update\n" << link.text << endl;
    } else {
        cout << "Patch failed. Status: " << link.status_code << endl;
    }

}
void listCommand() {
    cout << "List command:"
           "\n~Get - ***"
           "\n~Post - ***"
           "\n~Put - ***"
           "\n~Delete - ***"
           "\n~Patch - ***"
           "\n~~~~~~~~~~~~~~~~~~~~~~~~"
           "\n~List - for list commands"
           "\n~Exit - for exit" << endl;
}

int main () {
    string userLink = "https://httpbin.org";
    string command = "List";

    do {
        if (command == "List") {
            listCommand();
        } else if (command == "Get") {
            getCommand(userLink);
        } else if (command == "Post") {
            postCommand(userLink);
        } else if (command == "Put") {
            putCommand(userLink);
        } else if (command == "Delete") {
            deleteCommand(userLink);
        } else if (command == "Patch") {

        } else if (command != "Exit") {
            cout << "Invalid command" << endl;
        }

        cout << "\nEnter command: "; cin >> command;
    } while (command != "Exit");

    return 0;
}