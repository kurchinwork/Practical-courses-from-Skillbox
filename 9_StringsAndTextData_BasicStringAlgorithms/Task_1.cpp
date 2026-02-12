#include <iostream>

int main () {
    std::cout << "Enter the train departure time HH:MM: ";
    std::string departureTime;
    std::cin >> departureTime; std::cout << std::endl;
    
    std::cout << "Enter the train arrival time HH:MM: ";
    std::string arrivalTime;
    std::cin >> arrivalTime; std::cout << std::endl;

    bool logicInput = true;
    
    while (logicInput) {
        if ((departureTime.length () > 5 || departureTime[2] != ':' || departureTime[0] < 0 
            || departureTime[0] > 2  || departureTime[1] < 0 || departureTime[1] > 3 
            || departureTime[3] < 0 || departureTime[3] > 5 || departureTime[4] < 0 || departureTime [4] > 9) 
            && 
            (arrivalTime.length () > 5 || arrivalTime[2] != ':' || arrivalTime[0] < 0 
            || arrivalTime[0] > 2  || arrivalTime[1] < 0 || arrivalTime[1] > 3 || arrivalTime[3] < 0 
            || arrivalTime[3] > 5 || arrivalTime[4] < 0 || arrivalTime [4] > 9)) {
                
            std::cout << "\nGreat! Next step as processing\n***Loading***";
            logicInput = false;
                
            } else {

                 std::cout << "\nError input, please repeat";

            }
        }
    
    if (logicInput == false) {

        int HhMm_FirstInMin = ((10 * (departureTime[0] - '0') + (departureTime[1] - '0')) * 60) + (10 * (departureTime[3] - '0') + (departureTime[4] - '0'));
        int HhMm_SecondInMin = ((10 * (arrivalTime[0] - '0') + (arrivalTime[1] - '0')) * 60) + (10 * (arrivalTime[3] - '0') + (arrivalTime[4] - '0'));

        if (HhMm_FirstInMin < HhMm_SecondInMin) {

            std::cout << "\nTravel time: " << (HhMm_SecondInMin - HhMm_FirstInMin) / 60 << "h "<< (HhMm_SecondInMin - HhMm_FirstInMin) % 60 << "m.";     

        } else {

            std::cout << "\nTravel time: " << ((HhMm_SecondInMin + 1440) - HhMm_FirstInMin) / 60 << "h "<< ((HhMm_SecondInMin + 1440) - HhMm_FirstInMin) % 60 << "m.";     

        }
    }
}