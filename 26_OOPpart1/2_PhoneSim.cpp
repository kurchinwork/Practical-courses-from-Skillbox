//
// Created by kurchin_iu on 20.03.2026.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SIMcard {

    private:
        string nameSubscriber = "Unknown";
        string subscriberNumber = "+79379379379";
    map <string, string> subscriberList;

public:
    void AddInJournal(string& subscriber, string& subscriberNumber) {
        subscriberList[subscriberNumber] = subscriber;
    }
    void AddSubscriber () {
        bool validNum = false;
        do {
            validNum = false;
            cout << "\nEnter subscriber name: ";
            getline(cin, nameSubscriber);

            // проверка имени на пустоту
            if (nameSubscriber.empty()) {
                cout << "\nName cannot be empty! Try again." << endl;
            }
        } while (nameSubscriber.empty());

        do {
            cout << "\nEnter subscriber number: ";
            cin >> subscriberNumber; cin.ignore();

            if (subscriberNumber.length() != 12) {
                cout << "\nThe number length must be 12 characters."
                        "\nFor example:+79379379379"
                        "\nTry again.";
            } else if (subscriberNumber[0] != '+' || subscriberNumber[1] != '7') {
                cout << "\nThe phone code must start with +7";
                validNum = true;
                } else {
                    bool hasInvalidChar = false;
                    for (int i = 2; i < subscriberNumber.length(); i++) {
                        if (subscriberNumber[i] < '0' || subscriberNumber[i] > '9') {
                            cout << "\nThe number must contain only integers."
                                    "\nSimbol '" << subscriberNumber[i] << "' is invalid";
                            hasInvalidChar = true;
                            validNum = true;
                            break;
                        }
                    }
                    // все проверки пройдены
                    if (!hasInvalidChar) {
                        validNum = false;
                    }
                }
        } while(validNum);
        AddInJournal(nameSubscriber, subscriberNumber);
        cout << "\nSubscriber added successfully!" << endl;
    }

    // имя по номеру
    string getNameByNumber(const string& number) {
        if (subscriberList.find(number) != subscriberList.end()) {
            return subscriberList[number];  // или subscriberList.at(number)
        }
        return "";
    }

    //  номер по имени
    string getNumberByName(const string& name) {
        for (const auto& entry : subscriberList) {
            if (entry.second == name) {
                return entry.first;  // возвращаем номер
            }
        }
        return "";
    }
};

class PhoneSimulator {
    private:
    string smsText = "";

    SIMcard* currentSIMcard = nullptr;
public:
    void setSim(SIMcard* simcard) {
        currentSIMcard = simcard;
    }
    void calling () {
        string dataForCall = "";
        cout << "\nEnter the subscriber's number or name."
                "\nEnter:"; getline(cin, dataForCall);

        if (!dataForCall.empty()) {
            if (dataForCall[0] == '+') {
                string name = currentSIMcard->getNameByNumber(dataForCall);
                if (!name.empty()) {
                    cout << "\nCall to " << name << " with num: " << dataForCall << endl;
                } else {
                    cout << "\nThere is no such contact in your address book." << endl;
                }
            } else {
                string number = currentSIMcard->getNumberByName(dataForCall);
                if (!number.empty()) {
                    cout << "\nCall to " << number << " a " << dataForCall << endl;
                } else {
                    cout << "\nThere is no such contact in your address book." << endl;
                }
            }
        }

        }
    void smsing () {
        string dataForCall = "";
        cout << "\nEnter the subscriber's number or name."
                "\nEnter:"; getline(cin, dataForCall);

        if (!dataForCall.empty()) {
            if (dataForCall[0] == '+') {
                string name = currentSIMcard->getNameByNumber(dataForCall);
                if (!name.empty()) {
                    cout << "\nMessage to " << name << " with num: " << dataForCall << endl;
                    cout << "\nEnter message:"; getline(cin, smsText);
                } else {
                    cout << "\nThere is no such contact in your address book." << endl;
                }
            } else {
                string number = currentSIMcard->getNumberByName(dataForCall);
                if (!number.empty()) {
                    cout << "\nMessage to " << number << " a " << dataForCall << endl;
                    cout << "\nEnter message:"; getline(cin, smsText);
                } else {
                    cout << "\nThere is no such contact in your address book." << endl;
                }
            }
        }

    }
};

void listCommands() {
    cout << "\nEnter command: "
        "\n~add - to add a phone number to your address book;"
        "\n~call - to call the number;"
        "\n~sms - for writing SMS;"
        "\n```````````````````````"
        "\n~command - for list all all commands Adio player;"
        "\n~exit - for exit Adio player." << endl;
}



int main() {
    SIMcard SIMcard;
    PhoneSimulator phoneSimulator;
    phoneSimulator.setSim(&SIMcard);

    listCommands();
    string command = "";
    do {
        cout << "\nEnter command: "; cin >> command; cin.ignore();
        if (command == "add") {
            SIMcard.AddSubscriber();
        }
        if (command == "call") {
            phoneSimulator.calling();
        }
        if (command == "sms") {
            phoneSimulator.smsing();
        }
    } while(command != "exit");

    return 0;
}