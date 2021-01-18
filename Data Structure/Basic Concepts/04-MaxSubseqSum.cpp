/** https://pintia.cn/problem-sets/16/problems/663
 * @brief Maximum Subsequence Sum 2004年浙江大学计算机专业考研复试真题
 * 
 * 我们发现若要记录最大子列的右边的索引会很简单，
 * 只需要在 if(ThisSum>MaxSum) 判断成功后让当前的i更新为右边的索引即可。
 * 而寻找左边索引是本题的关键
 * 
 * 思路一，在在线处理的基础上原地更改，仅当thisSum >= maxSum时更新first、last，而thisSum < 0时只更新firstID、lastID
 *      这样做，前提是a[]必须要在在线处理这个循环前，完成初始化，因为当a[]全为负数时，永远不会进入thisSum >= maxSum的循环，
 *      那么一开始就要声明 first = a[0]; last = a[n - 1]; ，这会一部分时间，用于专门输入数组。
 * 思路二，逆向思维，从左往右遍历，找到的是最大子列的右边索引，我们从右往左遍历，不就能找到最大子列的左索引了吗？
 * 
*/

/**
 * PTA上此题的测试点：
 * 1. sample换1个数字。有正负，负数开头结尾，有并列最大和
 *    需考虑只找出第一个最大子列和的索引序号
 * 2. 最大和序列中有负数
 * 3. 并列和对应相同i但是不同j，即尾是0
 * 4. 1个正数
 * 5. 全是负数
 *    需特殊处理
 * 6. 负数和0
 *    需特殊处理
 * 7. 最大和前面有一段是0
 *    需特殊处理
 * 8. 最大N
*/

#include <iostream>
using namespace std;

int a[100005];

// 方法一
// https://blog.csdn.net/qq_40644568/article/details/90140420
int main() {
    auto thisSum{0}, maxSum{0},   // 将 当前子序列和 以及 目前最大子序列和 分别初始化为0
            firstID{0}, lastID{0},// 标识左右位置
            first{0}, last{0},
            n{0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    first = a[0];
    last = a[n - 1];
    for (int i = 0; i < n; i++) {
        thisSum += a[i];        // 向右累加
        if (thisSum >= maxSum) {// 因为取指数i和j最小的那串序列，所以在多个子序列相同时，
                                // 取第一次得到的序列。但这里会排除掉遇到0的情况，所以还需要加一个if语句（见↓）
            if (thisSum > maxSum) {
                maxSum = thisSum;
                lastID = i;
                first = a[firstID];
                last = a[lastID];
            }
            else if (thisSum == 0) {//（接上一条注释）在只有0和负数组成的序列中，第一次遇到的0就是所求序列
                maxSum = thisSum;
                lastID = i;
                first = a[firstID];
                last = a[lastID];
            }
        } else if (thisSum < 0) {// 如果当前子列和为负
            thisSum = 0;         // 则不可能使后面的部分和增大，抛弃之
            firstID = i + 1;
            lastID = firstID;
        }
    }
    printf("%d %d %d\n", maxSum, first, last);
    return 0;
}

// 方法二
// https://blog.csdn.net/tiao_god/article/details/105001659
// int main() {
//     auto thisSum{0},              // 将 当前子序列和初始化为0
//             maxSum{-1},           // 将 目前最大子序列和 初始化为-1，
//                                   // 目的是如果全是负数，则maxSum将一直是-1，可以最后检测出
//             firstID{0}, lastID{0},// 标识左右位置
//             n{0};
//     scanf("%d", &n);
//     lastID = n - 1;
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &a[i]);
//         thisSum += a[i];// 向右累加
//         if (thisSum > maxSum) {
//             maxSum = thisSum;
//             lastID = i;
//         } else if (thisSum < 0) {
//             thisSum = 0;
//         }
//     }
//     thisSum = 0;
//     maxSum = -1;
//     for (int i = lastID; i >= 0; i--) {
//         thisSum += a[i];// 向左累加
//         if (thisSum >= maxSum) {
//             maxSum = thisSum;
//             firstID = i;
//         } else if (thisSum < 0) {
//             thisSum = 0;
//         }
//     }
//     if (maxSum < 0) {
//         maxSum = 0;
//         firstID = 0;
//         lastID = n - 1;
//     }
//     printf("%d %d %d\n", maxSum, a[firstID], a[lastID]);
//     return 0;
// }

/**
 * 方法一较耗时，因为有用于专门输入数组的时间，这大概率大于方法二中的向左累加的时间
*/