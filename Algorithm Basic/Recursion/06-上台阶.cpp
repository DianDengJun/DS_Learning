// http://bailian.openjudge.cn/practice/4017/
#include <iostream>
using namespace std;
int stairs(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return stairs(n - 1) + stairs(n - 2);
}
int main() {
    int N; // 阶梯数
    while(cin >> N) {
        cout << stairs(N) << endl;
    }
    return 0;
}