/**
 * https://pintia.cn/problem-sets/15/problems/923
 * @brief 二分查找
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch(List L, ElementType X);

int main() {
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

Position BinarySearch(List L, ElementType X) {
    int left = 1;// 元素从下标1开始存储
    int right = L->Last;
    int center = (left + right) / 2;
    while (left <= right) {
        if (X > L->Data[center]) {
            left = center + 1;
        }else if (X < L->Data[center]) {
            right = center - 1;
        }else {
            return center;
        }
        center = (left + right) / 2;
    }
    return NotFound;
}