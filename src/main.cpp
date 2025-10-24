#include "include/Synth.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>


void writeWav(const std::string& filename, const std::vector<float>& samples, int sampleRate) {
    std::ofstream file(filename, std::ios::binary);

    int numChannels = 1;
    int bitsPerSample = 32;
    int byteRate = sampleRate * numChannels * (bitsPerSample / 8);
    int blockAlign = numChannels * (bitsPerSample / 8);
    int dataChunkSize = samples.size() * numChannels * (bitsPerSample / 8);
    int chunkSize = 36 + dataChunkSize;
    int subchunk1Size = 16;
    int audioFormat = 3;

    // WAV-header
    file.write("RIFF", 4);
    file.write(reinterpret_cast<const char*>(&chunkSize), 4);
    file.write("WAVEfmt ", 8);
    file.write(reinterpret_cast<const char*>(&subchunk1Size), 4);
    file.write(reinterpret_cast<const char*>(&audioFormat), 2);
    file.write(reinterpret_cast<const char*>(&numChannels), 2);
    file.write(reinterpret_cast<const char*>(&sampleRate), 4);
    file.write(reinterpret_cast<const char*>(&byteRate), 4);
    file.write(reinterpret_cast<const char*>(&blockAlign), 2);
    file.write(reinterpret_cast<const char*>(&bitsPerSample), 2);
    file.write("data", 4);
    file.write(reinterpret_cast<const char*>(&dataChunkSize), 4);

    
    file.write(reinterpret_cast<const char*>(samples.data()), dataChunkSize);

}

int main() {
    std::cout << "Synth test" << std::endl;

    /* 
        Default waveform -> Sine
        Default frequency -> 440.0 Hz
        Samplerate -> 44100.0 Hz
    */
    Synth synth;

    // Uncomment to toggle distortion and set threshold
    synth.toggleDist();
    synth.setDistThreshold(0.9);

    const float duration = 2.0f; // duration in s.
    const int sampleRate = 44100;
    const int totalSamples = static_cast<int>(sampleRate * duration);

    std::vector<float> samples;
    samples.reserve(totalSamples);
 

    for (int i = 0; i < totalSamples; ++i) {
        samples.push_back(synth.process(static_cast<float>(i) / sampleRate));        
    }

    writeWav("toneTest.wav", samples, sampleRate);
    std::cout << "toneTest.wav created." << std::endl;

    return 0;
}