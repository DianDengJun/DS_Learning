// http://bailian.openjudge.cn/practice/2787

#include <cmath>
#include <iostream>
#define EPS 1e-6

using namespace std;
double a[5];

// 浮点数是否为0
inline bool isZero(double x) {
    return fabs(x) <= EPS;
}

// 用数组a里的n个数，计算24
bool count24(double a[], int n) {
    if (n == 1) {
        return isZero(a[0] - 24);
    }
    double b[5];

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) { // 枚举选出两个数计算
            // 还剩下m个数,m=n-2
            int m = 0;

            for (int k = 0; k < n; k++)
                if (k != i && k != j)
                    b[m++] = a[k]; // 把其余数放入b

            // 测试加法
            b[m] = a[i] + a[j];
            if (count24(b, m + 1))
                return true;

            // 测试减法1
            b[m] = a[i] - a[j];
            if (count24(b, m + 1))
                return true;

            // 测试减法2
            b[m] = a[j] - a[i];
            if (count24(b, m + 1))
                return true;

            // 测试乘法
            b[m] = a[i] * a[j];
            if (count24(b, m + 1))
                return true;

            // 测试除法1
            if (!isZero(a[j])) {
                b[m] = a[i] / a[j];
                if (count24(b, m + 1))
                    return true;
            }

            // 测试除法2
            if (!isZero(a[i])) {
                b[m] = a[j] / a[i];
                if (count24(b, m + 1))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    while (true) {
        for (int i = 0; i < 4; ++i)
            cin >> a[i];
        if (isZero(a[0]))
            break;
        if (count24(a, 4))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}