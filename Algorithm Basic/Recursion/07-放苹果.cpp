// http://bailian.openjudge.cn/practice/1664/
#include <iostream>

using namespace std;

int f(int m, int n) {
    if (n > m)
        return f(m, m);
    if (m == 0)
        return 1; // 1种方法：所有盘子不放苹果
    if (n == 0)
        return 0; // 有苹果，无盘子，找不到放苹果的方法
    return f(m, n - 1) + f(m - n, n);
}

int main() {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        cout << f(m, n) << endl;
    }
}