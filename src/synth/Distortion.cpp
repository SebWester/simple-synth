#include "../include/Distortion.h"
#include <iostream>

void Distortion::toggleDist() {
    distActive = !distActive;
    std::cout << "Distortion active: " << (distActive ? "ON" : "OFF") << std::endl;
}

float Distortion::clipSignal(float input) {
    if (distActive) {
        if (input > 0.3f) {
            input = 0.3f;
        } else if (input < -0.3f) {
            input = -0.3f;
        }
    }

    return input;
}