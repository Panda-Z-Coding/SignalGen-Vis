# Signal Generator

一个C++信号生成器项目，可以生成正弦波、余弦波、白噪音和粉噪音信号，并导出数据用于Python可视化。

## 项目结构

```
SignalGenerator/
├── include/
│   ├── SignalGenerator.h  // 头文件（函数声明）
├── src/
│   ├── SignalGenerator.cpp // 信号生成实现
│   ├── main.cpp            // 主程序（测试+数据导出）
├── python/
│   ├── visualize.py        // Python可视化工具
```

## 功能特性

- 支持四种信号生成：
  - 正弦波
  - 余弦波
  - 白噪音
  - 粉噪音（1/f噪音）
- 可调节参数：振幅、频率、采样率和持续时间
- 数据导出为文本文件
- Python可视化工具

## 使用方法

1. 编译C++程序：
```bash
g++ -std=c++11 -Iinclude -D_USE_MATH_DEFINES src/SignalGenerator.cpp src/main.cpp -o signal_generator
```

2. 运行程序生成信号数据：
```bash
./signal_generator
```

3. 使用Python可视化工具：
```bash
python python/visualize.py
```

## 参数说明

- 振幅：信号的最大幅度（通常0.0-1.0）
- 频率：信号的频率（Hz）
- 采样率：每秒采样点数（Hz）
- 持续时间：信号长度（秒）

## 示例

默认生成：
- 440Hz正弦波（1.0振幅）
- 440Hz余弦波（1.0振幅）
- 白噪音（0.5振幅）
- 粉噪音（0.5振幅）

所有信号持续1秒，采样率44100Hz。