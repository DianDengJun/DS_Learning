// http://bailian.openjudge.cn/practice/2698/
// 题目要求输出转置矩阵

#include <cmath>
#include <iostream>
using namespace std;
int N = 8;
int queenPOS[100];
int cnt;
// 用来存放算好的皇后位置。最左上角是(0,0)
void NQueen(int k);

int main() {
    // cin >> N;
    NQueen(0); // 从第0行开始摆皇后
    return 0;
}

void NQueen(int k) { // 在0~k-1行皇后已经摆好的情况下，摆第k行及其后面的皇后
    if (k == N) {
        // N个皇后已经摆好
        cout << "No. " << ++cnt << endl;
        // 题目要求输出转置矩阵
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                cout << (j == queenPOS[i]) << " ";
            }
            cout << endl;
        }
        // cout << endl;
        return;
    }
    // 逐个尝试第k个皇后的位置
    for (int i = 0; i < N; i++) {
        // 和0~k-1号皇后比较
        int j;
        for (j = 0; j < k; j++) {
            if (queenPOS[j] == i || abs(queenPOS[j] - i) == abs(k - j)) {
                break; // 冲突，进行下一个测试
            }
        }
        // 当前选的位置i不冲突
        if (j == k) {
            queenPOS[k] = i; // 将第k个皇后摆放在位置i
            NQueen(k + 1);
        }
    }
}