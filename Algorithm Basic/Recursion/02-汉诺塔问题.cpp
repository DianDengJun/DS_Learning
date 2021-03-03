// http://bailian.openjudge.cn/practice/4147/

#include <iostream>
using namespace std;

// 将src座上的n个盘子，以mid座为中转，移动到dest座
// src座上最上方盘子编号是src_n
void Hanoi(int n, char src, char mid, char dest, int src_n) {
    if (n == 1) {
        // 只需移动一个盘子
        cout << src_n << ":" << src << "->" << dest << endl;
        return;
    }
    Hanoi(n - 1, src, dest, mid, src_n); // 先将n-1个盘子从src移动到mid
    cout << src_n + n - 1 << ":" << src << "->" << dest << endl;
    // 再将一个盘子从src移动到dest
    Hanoi(n - 1, mid, src, dest, src_n);
    return;
}

int main() {
    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    Hanoi(n, a, b, c, 1);
    return 0;
}