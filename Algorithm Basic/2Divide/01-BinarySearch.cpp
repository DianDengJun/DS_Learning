#include <iostream>

using namespace std;

using Position = int;

// 查找元素p的位置，复杂度O(log(n))
Position BinarySearch(int a[], int size, int p) {
    int L = 0;
    int R = size - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2; // 取中点，防止(L+R)溢出
        if (p == a[mid])
            return mid;
        else if (p > a[mid])
            L = mid + 1; // 设为新的左端点
        else
            R = mid - 1; // 设为新的右端点
    }
    return -1; // -1 表示没有找到
}

// 查找比p小的，但是下标最大的元素，返回该下标
Position LowerBound(int a[], int size, int p) {
    int L = 0;
    int R = size - 1;
    int lastPos = -1; // 到目前位置找到的最优解
    while (L <= R) {
        int mid = L + (R - L) / 2; // 取中点，防止(L+R)溢出
        if (a[mid] >= p)
            R = mid - 1;
        else {
            lastPos = mid;
            L = mid + 1;
        }
    }
    return -1; // -1 表示没有找到
}


int main() {
    return 0;
}