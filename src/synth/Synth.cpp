#include "../include/Synth.h"
#include <memory>
#include <string>
#include <iostream>

Synth::Synth()
    : osc(std::make_unique<Oscillator>()),
      gain(std::make_unique<Gain>()),
      dist(std::make_unique<Distortion>())
{}

float Synth::process(float t) {
  float sample = osc->generateSample();
  sample = gain->process(sample);
  sample = dist->clipSignal(sample);

  return sample;
}


void Synth::changeWaveform(const std::string& newWave) {
  osc->setWaveform(newWave);
}

void Synth::changeFrequency(float fq) {
  osc->setFrequency(fq);
}

void Synth::setGainLevel(float l) {
  gain->setLevel(l);
}

void Synth::toggleDist() {
  dist->toggleDist();
}

