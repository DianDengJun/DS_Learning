#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;
#define MAXN 10 // 多项式最大项系数，即多项式阶数+1
#define MAXK 1e7// 被测函数最大重复调用次数
/* 一次测量时间太短，多次测量，计算平均每次运行的时间 */

double f1(int n, double a[], double x) {
    double p = a[0];
    for (int i = 1; i <= n; i++)
        p += (a[i] * pow(x, i));
    return p;
}

double f2(int n, double a[], double x) {
    double p = a[n];
    for (int i = n; i > 0; i--)
        p = a[i - 1] + x * p;
    return p;
}

void test(int n, double a[], double x, double (*f)(int, double[], double), int frequency) {
    // clock_t是clock()函数返回的变量类型
    clock_t start, stop;
    // 用于记录被侧函数运行时间，以秒为单位
    double duration;

    start = clock();
    // 将被测函数重复frequency次
    for (int i = 0; i < frequency; i++)
        (*f)(n, a, x);
    stop = clock();
    duration = ((double) (stop - start)) / CLK_TCK / frequency;
    // 输出时钟滴答次数
    cout << "ticks = " << (double) (stop - start) << endl;
    // 输出运行时间
    cout << "duration = " << duration << endl;
}

int main() {
    double a[MAXN];// 存储多项式系数
    for (int i = 0; i < MAXN; i++)
        a[i] = (double) (i);

    // 测试f1函数运行时间
    cout << "f1:" << endl;
    test(MAXN - 1, a, 1.1, f1, MAXK);

    // 测试f2函数运行时间
    cout << "f2:" << endl;
    test(MAXN - 1, a, 1.1, f2, MAXK);
    return 0;
}