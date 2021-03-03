// http://bailian.openjudge.cn/practice/2730/
// 注意参数类型选用 long long

#include <iostream>
using namespace std;

long long factorial(long long n) {
    if (!n)
        return 1;
    else
        return factorial(n - 1) * n;
}

int main() {
    long long n{0};
    cin >> n;
    cout << factorial(n);
    return 0;
}