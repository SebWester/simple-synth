#include "../include/Distortion.h"
#include <iostream>


void Distortion::toggleDist() {
    distActive = !distActive;
    std::cout << "Distortion active: " << (distActive ? "ON" : "OFF") << std::endl;
}

void Distortion::setThreshold(float t) {
    if (t < 0.0f) {
        threshold = 0.0f;
    } else if (t > 1.0f) {
        threshold = 1.0f;
    } else {
        threshold = t;
    }
}

float Distortion::clipSignal(float input) {
    if (distActive) {
        if (input > threshold) {
            input = threshold;
        } else if (input < -threshold) {
            input = -threshold;
        }
    }

    return input;
}