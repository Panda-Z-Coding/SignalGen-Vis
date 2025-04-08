#include "SignalGenerator.h"
#include <cmath>
#include <iostream>
std::vector<float> SignalGenerator::generateSineWave(float amplitude, float frequency, float sampleRate, float duration) {
    std::vector<float> samples;
    int numSamples = static_cast<int>(sampleRate * duration);
    samples.reserve(numSamples);
    for (int i = 0; i < numSamples; ++i) {
        float t = static_cast<float>(i) / sampleRate;
        samples.push_back(amplitude * sin(2.0f * M_PI * frequency * t));
    }
    return samples;
}
std::vector<float> SignalGenerator::generateCosineWave(float amplitude, float frequency, float sampleRate, float duration) {
    std::vector<float> samples;
    int numSamples = static_cast<int>(sampleRate * duration);
    samples.reserve(numSamples);
    for (int i = 0; i < numSamples; ++i) {
        float t = static_cast<float>(i) / sampleRate;
        samples.push_back(amplitude * cos(2.0f * M_PI * frequency * t));
    }
    return samples;
}
std::vector<float> SignalGenerator::generateWhiteNoise(float amplitude, float sampleRate, float duration) {
    std::vector<float> samples;
    int numSamples = static_cast<int>(sampleRate * duration);
    samples.reserve(numSamples);
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < numSamples; ++i) {
        samples.push_back(amplitude * (2.0f * static_cast<float>(rand()) / RAND_MAX - 1.0f));
    }
    return samples;
}
std::vector<float> SignalGenerator::generatePinkNoise(float amplitude, float sampleRate, float duration) {
    std::vector<float> samples;
    int numSamples = static_cast<int>(sampleRate * duration);
    samples.reserve(numSamples);
    srand(static_cast<unsigned>(time(nullptr)));
    float b0 = 0.0f, b1 = 0.0f, b2 = 0.0f, b3 = 0.0f, b4 = 0.0f, b5 = 0.0f, b6 = 0.0f;
    for (int i = 0; i < numSamples; ++i) {
        float white = amplitude * (2.0f * static_cast<float>(rand()) / RAND_MAX - 1.0f);
        b0 = 0.99886f * b0 + white * 0.0555179f;
        b1 = 0.99332f * b1 + white * 0.0750759f;
        b2 = 0.96900f * b2 + white * 0.1538520f;
        b3 = 0.86650f * b3 + white * 0.3104856f;
        b4 = 0.55000f * b4 + white * 0.5329522f;
        b5 = -0.7616f * b5 - white * 0.0168980f;
        float pink = b0 + b1 + b2 + b3 + b4 + b5 + b6 + white * 0.5362f;
        b6 = white * 0.115926f;
        samples.push_back(pink * 0.11f); // 归一化
    }
    return samples;
}
void SignalGenerator::exportToFile(const std::vector<float>& data, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (float sample : data) {
            outFile << sample << "\n";
        }
        outFile.close();
        std::cout << "Data exported to " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not open file " << filename << std::endl;
    }
}