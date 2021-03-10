// http://bailian.openjudge.cn/practice/2456/
// 运用了二分答案的思想

#include <algorithm>
#include <iostream>
using namespace std;

constexpr int MAXN = int(1e5) + 5;

int x[MAXN];

int N, C;

bool isOK(int d) {
    int i;
    int temp = x[0];
    int count = 1;
    for (int i = 1; i < N; i++) {
        if (x[i] - temp >= d) {
            temp = x[i];
            count++;
            if (count >= C) return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        scanf("%d", &x[i]);
    }
    sort(x, x + N);
    int left = 1, right = int(1e9);
    int mid, answer;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (isOK(mid)) {
            answer = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << answer;
    return 0;
}