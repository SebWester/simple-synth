#include "../include/Gain.h"

Gain::Gain(float l) : level(l) {}

float Gain::process(float input) {
    return level * input;
}

void Gain::setLevel(float newLevel) {
    level = newLevel;
}