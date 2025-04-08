#pragma once
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
/**
 * @brief 信号生成器类
 */
class SignalGenerator {
public:
    /**
     * @brief 生成正弦波
     * @param amplitude 振幅
     * @param frequency 频率（Hz）
     * @param sampleRate 采样率（Hz）
     * @param duration 持续时间（秒）
     * @return std::vector<float> 信号数据
     */
    static std::vector<float> generateSineWave(float amplitude, float frequency, float sampleRate, float duration);
    /**
     * @brief 生成余弦波
     * @param amplitude 振幅
     * @param frequency 频率（Hz）
     * @param sampleRate 采样率（Hz）
     * @param duration 持续时间（秒）
     * @return std::vector<float> 信号数据
     */
    static std::vector<float> generateCosineWave(float amplitude, float frequency, float sampleRate, float duration);
    /**
     * @brief 生成白噪音
     * @param amplitude 振幅
     * @param sampleRate 采样率（Hz）
     * @param duration 持续时间（秒）
     * @return std::vector<float> 信号数据
     */
    static std::vector<float> generateWhiteNoise(float amplitude, float sampleRate, float duration);
    /**
     * @brief 生成粉噪音（1/f噪音）
     * @param amplitude 振幅
     * @param sampleRate 采样率（Hz）
     * @param duration 持续时间（秒）
     * @return std::vector<float> 信号数据
     */
    static std::vector<float> generatePinkNoise(float amplitude, float sampleRate, float duration);
    /**
     * @brief 导出数据到文件（用于Python可视化）
     * @param data 信号数据
     * @param filename 文件名（如 "sine_wave.txt"）
     */
    static void exportToFile(const std::vector<float>& data, const std::string& filename);
};