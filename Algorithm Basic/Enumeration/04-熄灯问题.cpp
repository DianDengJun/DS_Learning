// http://bailian.openjudge.cn/practice/1222/

#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

// 取字符c的第i位
inline int getBit(char c, int i) {
    return (c >> i) & 1;
}

// 设置字符c的第i位为v
inline void setBit(char &c, int i, int v) {
    if (v)
        c |= (1 << i);
    else
        c &= ~(1 << i);
}

// 翻转字符c的第i位
inline void flipBit(char &c, int i) {
    c ^= (1 << i);
}

// 输出结果
void OutputResult(int t, char result[]) {
    cout << "PUZZLE #" << t << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            cout << getBit(result[i], j);
            if (j < 5)
                cout << " ";
        }
        cout << endl;
    }
}

int main() {
    // 5个二进制，对应5行
    char oriLights[5]; // 原状态
    char lights[5];
    char result[5]; // 最终结果
    char switchs;   // 某一行的状态
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(oriLights, 0, sizeof(oriLights));
        // 输入原状态
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 6; j++) {
                int s;
                cin >> s;
                setBit(oriLights[i], j, s);
            }
        }
        // 遍历第一行，使用二进制bit位
        for (int n = 0; n < 64; n++) {
            memcpy(lights, oriLights, sizeof(oriLights));
            switchs = n; // 当前行的开关状态
            // 处理第i行
            for (int i = 0; i < 5; i++) {
                result[i] = switchs;
                // 第i行的第j个状态
                for (int j = 0; j < 6; j++) {
                    if (getBit(switchs, j)) {
                        if (j > 0)
                            flipBit(lights[i], j - 1); // 改左灯
                        flipBit(lights[i], j);         // 改开关位置的灯
                        if (j < 5)
                            flipBit(lights[i], j + 1); // 改右灯
                    }
                }
                if (i < 4)
                    lights[i + 1] ^= switchs; // 改下一行的灯
                switchs = lights[i];          // 第i+1行开关方案和第i行情况相同
            }
            if (lights[4] == 0) {
                OutputResult(t, result);
                break;
            }
        }
    }
    return 0;
}