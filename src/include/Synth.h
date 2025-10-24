#ifndef SYNTH_H
#define SYNTH_H

#include "Oscillator.h"
#include "Gain.h"
#include "Distortion.h"
#include <memory>

class Synth {
    public:
        Synth();
        float process(float t);

        // Oscillator
        void changeWaveform(const std::string& newWave);
        void changeFrequency(float fq);
        // Gain
        void setGainLevel(float l);
        // Distortion
        void toggleDist();
        
    private:
        std::unique_ptr<Oscillator> osc;
        std::unique_ptr<Gain> gain;
        std::unique_ptr<Distortion> dist;
};

#endif