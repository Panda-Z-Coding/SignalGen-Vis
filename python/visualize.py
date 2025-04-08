import matplotlib.pyplot as plt
import numpy as np
import os

# 从文件加载数据
def load_data(filename):
    with open(filename, 'r') as f:
        return [float(line.strip()) for line in f]

# 绘制单个信号
def plot_signal(data, title):
    plt.figure(figsize=(10, 4))
    plt.plot(data, label=title, linewidth=2)
    plt.title(title, fontsize=14)
    plt.xlabel('Sample', fontsize=12)
    plt.ylabel('Amplitude', fontsize=12)
    plt.grid(True)
    plt.legend(fontsize=12)
    plt.tight_layout()
    plt.show()

# 绘制所有信号
def plot_all_signals(signals, titles):
    plt.figure(figsize=(12, 8))
    for i, (data, title) in enumerate(zip(signals, titles), 1):
        plt.subplot(2, 2, i)
        plt.plot(data, label=title, linewidth=2)
        plt.title(title, fontsize=12)
        plt.xlabel('Sample', fontsize=10)
        plt.ylabel('Amplitude', fontsize=10)
        plt.grid(True)
        plt.legend(fontsize=10)
    plt.tight_layout()
    plt.show()

# 主菜单
def main():
    # 检查数据文件是否存在
    files = {
        '1': ('sine_wave', 'sine_wave.txt'),
        '2': ('cosine_wave', 'cosine_wave.txt'),
        '3': ('white_noise', 'white_noise.txt'),
        '4': ('pink_noise', 'pink_noise.txt'),
        '5': ('全部信号', None)
    }
    
    while True:
        print("\n=== 信号可视化工具 ===")
        for key, (name, _) in files.items():
            print(f"{key}. 查看{name}")
        print("0. 退出")
        
        choice = input("请选择要查看的信号(0-5): ")
        
        if choice == '0':
            break
        elif choice == '5':
            # 加载所有信号数据
            signals = []
            titles = []
            for key in ['1', '2', '3', '4']:
                _, filename = files[key]
                if os.path.exists(filename):
                    signals.append(load_data(filename))
                    titles.append(files[key][0])
            plot_all_signals(signals, titles)
        elif choice in files:
            _, filename = files[choice]
            if os.path.exists(filename):
                data = load_data(filename)
                plot_signal(data, files[choice][0])
            else:
                print(f"错误: 文件 {filename} 不存在")
        else:
            print("无效的选择，请重新输入")

if __name__ == "__main__":
    main()