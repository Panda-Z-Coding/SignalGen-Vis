#include "SignalGenerator.h"
#include <iostream>

int main() {
    // 初始化随机种子
    srand(static_cast<unsigned>(time(nullptr)));

    // 生成信号
    auto sineWave = SignalGenerator::generateSineWave(1.0f, 50.0f, 1024.0f, 1.0f);
    auto cosineWave = SignalGenerator::generateCosineWave(1.0f, 50.0f, 1024.0f, 1.0f);
    auto whiteNoise = SignalGenerator::generateWhiteNoise(0.5f, 1024.0f, 1.0f);
    auto pinkNoise = SignalGenerator::generatePinkNoise(0.5f, 1024.0f, 1.0f);

    // 导出数据（用于Python可视化）
    SignalGenerator::exportToFile(sineWave, "sine_wave.txt");
    SignalGenerator::exportToFile(cosineWave, "cosine_wave.txt");
    SignalGenerator::exportToFile(whiteNoise, "white_noise.txt");
    SignalGenerator::exportToFile(pinkNoise, "pink_noise.txt");

    std::cout << "Signal generation complete. Data exported to text files." << std::endl;
    return 0;
}
