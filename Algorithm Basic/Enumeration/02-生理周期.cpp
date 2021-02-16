// http://bailian.openjudge.cn/practice/4148/

#include <iostream>
using namespace std;

inline bool check(int p, int e, int i, int d, int k) {
    return (k - p) % 23 == 0 && (k - e) % 28 == 0 && (k - i) % 33 == 0;
}

int main() {
    int p, e, i, d;
    int caseNo{0};
    while (true) {
        cin >> p >> e >> i >> d;
        if (p != -1) {
            // for (int k = d + 1; k <= 21252 + d; k++) { // 注意是k - d <= 21252
            //     if (check(p, e, i, d, k)) {
            //         cout << "Case " << ++caseNo
            //              << ": the next triple peak occurs in "
            //              << k - d << " days." << endl;
            //         break;
            //     }
            // }
            int k;
            for (k = d + 1; (k - p) % 23; k++)
                ;
            for (; (k - e) % 28; k += 23)
                ;
            for (; (k - i) % 33; k += 23 * 28)
                ;
            cout << "Case " << ++caseNo
                 << ": the next triple peak occurs in "
                 << k - d << " days." << endl;
        } else {
            break;
        }
    }
    return 0;
}