#include "../include/Synth.h"
#include <memory>

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
