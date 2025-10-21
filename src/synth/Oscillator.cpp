#include "../include/Oscillator.h"
#include <iostream>

Oscillator::Oscillator(Waveform wf, float f, float sr) : waveform(wf), frequency(f), sampleRate(sr), phase(0.0f) {
    std::cout << "Oscillator created." << std::endl;
};

std::string Oscillator::waveformToString() const {
    switch (waveform) {
        case Waveform::Sine: return "Sine";
        case Waveform::Saw: return "Saw";
        case Waveform::Square: return "Square";
    }
    return "Unknown";
}

void Oscillator::printInfo() {
    std::cout << "Waveform: " << waveformToString() << std::endl;
    std::cout << "Frequency: " << frequency << " Hz" << std::endl;
    
    std::cout << "Available methods:" << std::endl;
    std::cout << "setWaveform(const std::string& wf)" << std::endl;
    std::cout << "setFrequency()" << std::endl;    
    std::cout << "generateSample()" << std::endl;    
}

void Oscillator::setWaveform(const std::string& wf) {    
    std::string lower = wf;
    std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

    if (lower == "sine") waveform = Waveform::Sine;
    else if (lower == "saw") waveform = Waveform::Saw;
    else if (lower == "square") waveform = Waveform::Square;
    else std::cout << "Not a valid waveform!" << std::endl;
}

void Oscillator::setFrequency(float fq) {
    frequency = fq;
}

float Oscillator::generateSample() {
    float value = 0.0f;

    switch (waveform)
    {
    case Waveform::Sine:
        value = std::sin(2.0f * M_PI * phase);
        break;

    case Waveform::Saw:
        value = 2.0f * phase - 1.0f;
        break;

    case Waveform::Square:
        value = (phase < 0.5f) ? 1.0f : -1.0f;
        break;
    }

    phase += frequency / sampleRate;
    if (phase >= 1.0f) phase -= 1.0f;

    return value;
}