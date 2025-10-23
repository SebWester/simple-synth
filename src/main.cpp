#include <iostream>

// #include "Oscillator.h"
#include "include/Synth.h"

int main() {
    std::cout << "Synth test" << std::endl;

    // Oscillator osc;
    // osc.printInfo();

    Synth synth;

    for (int i = 0; i < 10; ++i) {
        float sample = synth.process(static_cast<float>(i) / 44100.0f);

        std::cout << "Sample: " << sample << std::endl;
    }

    return 0;
}