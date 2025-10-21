#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include <string>

class Oscillator {
    public:
        enum class Waveform {
            Sine,
            Saw,
            Square
        };

    Oscillator(Waveform wf = Waveform::Sine, float f = 440.0f, float sr = 44100.0f);    

    std::string waveformToString() const;
    void printInfo();
    void setWaveform(const std::string& wf);
    void setFrequency(float fq);
    float generateSample();

    private: 
        Waveform waveform;
        float frequency;
        float sampleRate;
        float phase;    // 0.0 - 1.0
};

#endif