//
// Created by kurch on 27.01.2026.
//
#include <iostream>
#include <sstream>

using namespace std;

enum currentState {
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16};

int main() {
    int dayCountAtWork = 0;
    cout << R"(
            This program controls the house during the selected days.
                    An example of how data is entered:
    Temperature inside, temperature outside, movement, lights: '10 10 yes* on*'
     To start, enter the number of days for which the program is activated:)"; cin >> dayCountAtWork;

    for (int numberOfDay = 0; numberOfDay < dayCountAtWork; numberOfDay++ ) {
        int houseState = 0,
        lightTemperature = 5000;
        cout << "\n//////////////////////////////////////////////////////////////////////////////////////////////"
                "\n//......................................Day #" << numberOfDay + 1 << " .............................................//"
                "\n//////////////////////////////////////////////////////////////////////////////////////////////";

        //Ежечасно будут поступать данные от датчиков (ну или от юзера как по задаче)
        for (int numberOfHours = 0; numberOfHours < 24; numberOfHours++ ) {
            int temperatureInside = 0,
                temperetureOutside = 0;
            string movementOutside = "",
                   lightInside = "";

            string informationFromSensorsHourly = " ";
            cout << "\n\t\t\t\tThe clock shows: " << numberOfHours << ":00."
                    "\nTemperature inside, temperature outside, movement, lights:"; cin >> temperatureInside >> temperetureOutside >> movementOutside >> lightInside;

            if (temperatureInside < 22) {
                cout << "\nHeaters inside is ON!";
                houseState |= HEATERS;
            } else if (temperatureInside >= 25) {
                cout << "\nHeaters inside is OFF!";
                houseState &= ~HEATERS;
            }

            if (temperatureInside >= 30) {
                cout << "\nConditioner is ON!";
                houseState |= CONDITIONER;
            } else if (temperatureInside <= 25) {
                cout << "\nConditioner is OFF!";
                houseState &= ~CONDITIONER;
            }

            if (temperetureOutside < 0) {
                cout << "\nWater pipe heating is ON!";
                houseState |= WATER_PIPE_HEATING;
            } else if (temperetureOutside >= 5) {
                cout << "\nWater pipe heating is OFF!";
                houseState &= ~WATER_PIPE_HEATING;
            }

            if (movementOutside == "yes") {
                cout << "\nMotion detected!"
                        "\nTime in: " << numberOfHours << ":00";
                if (numberOfHours >= 16 || numberOfHours < 5) {
                    cout << "\nLights outside is ON!";
                    houseState |= LIGHTS_OUTSIDE;
                }
            } else {
                houseState &= ~LIGHTS_OUTSIDE;
            }

            if (numberOfHours > 16 && numberOfHours < 20) {
                lightTemperature-= 575; //с 16:00 до 20:00 4 часа понижения температуры света. 5000-2700= 2300/4 = 575 понижать ежечасно
            }
            if (lightInside == "on") {
                cout << "\nLights inside is ON!"
                        "\nLights inside temperature color: " << lightTemperature;

            }
        }
    }
    return 0;
}