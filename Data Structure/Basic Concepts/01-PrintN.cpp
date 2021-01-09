#include <iostream>
using namespace std;

// 循环实现
void PrintN1(int N) {
    for (int i = 0; i <= N; i++)
        cout << i << endl;
}

// 递归实现，如果递归过多将造成栈溢出(Stack Overflow)
void PrintN2(int N) {
    if (N) {
        PrintN2(N - 1);
        cout << N << endl;
    }
}

int main() {
    auto n{0};
    cout << "Input n:";
    cin >> n;
    PrintN2(n);
}