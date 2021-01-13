// 最大子列和问题
// 算法一 O(N^3)
// 算法二 O(N^2)
// 算法三 O(NlogN)
// 算法四、五 O(N)
/* 改进本程序的建议
 * 对于list[i]的输入，算法一、二、四、五可将cin或printf置于函数体内，节省输入时间
 * 算法五是算法四的最终版本，对于算法五，list数组实际上每次只用到当前list[i]值，可更改为一个变量
 *    节省空间开销
 */
#include <algorithm>
#include <iostream>

using namespace std;
#define EnableInputInfo 0
#define MAXN 100005
#define INF ((int) 1e9)
int list[MAXN];

// 算法一，暴力法
namespace Algorithm1 {
    int GetMaxSubseqSum(int list[], int n) {
        auto thisSum{0}, maxSum{-INF};
        for (int i = 0; i < n; i++) {    // i是子列左端位置
            for (int j = i; j < n; j++) {// j是子列右端位置
                thisSum = 0;             // thisSum是从A[i]到A[j]的子列和
                for (int k = i; k <= j; k++)
                    thisSum += list[k];
                maxSum = max(maxSum, thisSum);
            }
        }
        return maxSum;
    }
}// namespace Algorithm1

// 算法二，暴力法的改进
namespace Algorithm2 {
    int GetMaxSubseqSum(int list[], int n) {
        auto thisSum{0}, maxSum{-INF};
        for (int i = 0; i < n; i++) {    // i是子列左端位置
            thisSum = 0;                 // thisSum是从A[i]到A[j]的子列和
            for (int j = i; j < n; j++) {// j是子列右端位置
                thisSum += list[j];
                maxSum = max(maxSum, thisSum);
            }
        }
        return maxSum;
    }
}// namespace Algorithm2

// 算法三，分而治之
namespace Algorithm3 {
    // 3个整数中的最大值
    int Max3(int a, int b, int c) {
        return max(a, max(b, c));
    }

    // 分治法求List[left]到List[right]的最大子列和
    int DivideAndConquer(int list[], int left, int right) {
        // 存放左右字问题的解
        auto maxLeftSum{-INF}, maxRightSum{-INF};
        // 存放跨分界线的结果
        auto maxLeftBorderSum{-INF}, maxRightBorderSum{-INF};

        auto leftBorderSum{0}, rightBorderSum{0};
        auto center{0};

        // 递归终止条件，子列只有一个数字
        if (left == right) {
            return list[left];
            // else
            //     return 0;
        }

        // 下面是分的过程
        center = (left + right) / 2;// 找到中分点
        // 递归求得两边子列得最大和
        maxLeftSum = DivideAndConquer(list, left, center);
        maxRightSum = DivideAndConquer(list, center + 1, right);

        // 下面求跨分界线得最大子列和
        maxLeftBorderSum = -INF;
        leftBorderSum = 0;
        // 从中线向左边扫描
        for (int i = center; i >= left; i--) {
            leftBorderSum += list[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }
        maxRightBorderSum = -INF;
        rightBorderSum = 0;
        // 从中线向右边扫描
        for (int i = center + 1; i <= right; i++) {
            rightBorderSum += list[i];
            maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
        }

        // 返回"治"结果
        return Max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    }

    int GetMaxSubseqSum(int list[], int n) {
        // 保持与前2种算法相同的函数接口
        return DivideAndConquer(list, 0, n - 1);
    }
}// namespace Algorithm3

// 算法四，在线处理（动态规划）
namespace Algorithm4 {
    int GetMaxSubseqSum(int list[], int n) {
        auto thisSum{0}, maxSum{0};
        for (int i = 0; i < n; i++) {
            thisSum += list[i];// 向右累加
            if (thisSum > maxSum)
                maxSum = thisSum;// 发现更大和则跟新当前结果
            else if (thisSum < 0)// 如果当前子列和为负
                thisSum = 0;     // 则不可能使后面的部分和增大，抛弃之
        }
        return maxSum;
    }
}// namespace Algorithm4
// 算法四的理想状态是最大子列和总大于0
// 算法五是对算法四的改进，使得其对任意情况成立，如{-1,-2,-3,-4,-5,-6}的最大子列和应是-1

// 算法五，改进的在线处理（动态规划）
namespace Algorithm5 {
    int GetMaxSubseqSum(int list[], int n) {
        auto thisSum{0}, maxSum{-INF};
        for (int i = 0; i < n; i++) {
            if (i < 1) {
                thisSum = list[0];
            } else {
                // thisSum取"当前的数list[i]"和"上一次子列和加上当前的数list[i]"中的最大值
                // 也就是说，如果"当前数list[i]"自身就比上一次子列和大，
                //     就没有将"上一次子列和加上当前的数list[i]"作为新字段和的必要
                thisSum = max(list[i], thisSum + list[i]);
            }
            // 发现更大的子列和，更新之
            maxSum = max(maxSum, thisSum);
        }
        return maxSum;
    }
}// namespace Algorithm5

using namespace Algorithm5;

int main() {
    auto n{0};
#if EnableInputInfo
    cout << "Input n:";
#endif
    cin >> n;
#if EnableInputInfo
    cout << "Input list[" << n << "]:" << endl;
#endif
    for (int i = 0; i < n; i++) {
        cin >> list[i];
    }
    auto ans{GetMaxSubseqSum(list, n)};
    cout << ans;
    return 0;
}