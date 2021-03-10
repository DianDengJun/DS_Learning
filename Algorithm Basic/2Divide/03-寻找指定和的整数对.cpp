// 寻找指定和的整数对
// 输入n ( n<= 100,000)个整数，找出其中的两个数，
// 它们之和等于整数m(假定肯定有解)。题中所有整数都能用int表示

// 解法1：对数组中的每个元素a[i],在数组中二分查找m-a[i]，看能否找到。
// 复杂度log(n)，最坏要查找n-2次(思考为什么)，所以查找这部分的复杂度也是O(n×log(n))

// 解法2：查找的时候，设置两个变量i和j,i初值是0,j初值是n-1.看a[i]+a[ j],
// 如果大于m，就让j减1，如果小于m,就让i加1，直至a[i]+a[ j]=m

#include <algorithm>
#include <iostream>
using namespace std;

using Position = int;

int arr[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int i = 0, j = n - 1;
    while (i < j) {
        if (arr[i] + arr[j] > m)
            j -= 1;
        else if (arr[i] + arr[j] < m)
            i += 1;
        else
            break;
    }
    cout << arr[i] << " " << arr[j] << endl;
    return 0;
}