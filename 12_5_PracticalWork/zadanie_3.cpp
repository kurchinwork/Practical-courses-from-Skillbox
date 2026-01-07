//
// Created by kurchin ilya on 18.12.2025.
//

#include <assert.h>
#include <iostream>

float travelTime(float distance, float speed) {
    return distance / speed;
}

int main () {
    float distance, speed;
    std::cout << "Enter distance: "; std::cin >> distance;
    std::cout << "Enter speed: "; std::cin >> speed;
    assert(speed > 0);
    std::cout << travelTime(distance, speed) << std::endl;
}