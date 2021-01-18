本章主要论述了数据结构的基本概念。

1. 写程序实现一个函数`PrintN`，使得传入一个正整数为N的参数后，能顺序打印从1到N的全部正整数。

   循环实现：

   ```cpp
   void PrintN1(int N) {
       for (int i = 0; i <= N; i++)
        cout << i << endl;
   }
   ```
   
   递归实现：
   
   ```cpp
   void PrintN2(int N) {
       if (N) {
           PrintN2(N - 1);
           cout << N << endl;
       }
   }
   ```
   
   本例要说明的是，即使是最简单的程序，都有多种数据结构/算法实现之。
   
   有时候我们很喜欢递归，因为其简单易懂，但是对于程序来说，如果递归过多，将占用非常多的空间，导致栈区溢出(`Stack Overflow`)。
   
   **解决问题方法的效率，根空间的利用效率有关。**
   
2. 写程序计算给定多项式在给定点x处的值
   $$
   f(x) = a_{0} + a_{1}x + \cdots + a_{n-1}x^{n-1} + a_{n}x^{n}
   $$
   低级写法：

   ```cpp
   double f1(int n, double a[], double x) {
       double p = a[0];
       for (int i = 1; i <= n; i++)
           p += (a[i] * pow(x, i));
       return p;
   }
   ```

   公因式提取：
   $$
   f(x) = a_{0} + x(a_{1} + x(\cdots(a_{n-1} + x(a_{n}))\cdots))
   $$
   对应程序：

   ```cpp
   double f2(int n, double a[], double x) {
       double p = a[n];
       for (int i = n; i > 0; i--)
           p = a[i - 1] + x * p;
       return p;
   }
   ```

   明显`f1`慢。可在[程序](./02-Polynomial.cpp)中验证。

   **解决问题方法的效率，跟算法的巧妙程度有关。**
   
3. 给定N个整数的序列$\{A_{1},A_{2},\cdots,A_{N}\}$，求函数$f(i,j)=max\{0,\sum_{k=i}^{j}{A_{k}}\}$的最大值。

   + 算法一：暴力（时间复杂度$O(N^3)$）
   
   ```cpp
   int MaxSubseqSum1(int A[], int N) {
       int ThisSum, MaxSum = 0;
       int i, j, k;
       for (i = 0; i < N; i++) {     /* i是子列左端位置 */
           for (j = i; j < N; j++) { /* j是子列右端位置 */
               ThisSum = 0;          /* ThisSum是从A[i]到A[j]的子列和 */
               for (k = i; k <= j; k++)
                   ThisSum += A[k];
               if (ThisSum > MaxSum) /* 如果刚得到的这个子列和更大 */
                   MaxSum = ThisSum; /* 则更新结果 */
           }                         /* j循环结束 */
       }                             /* i循环结束 */
       return MaxSum;
   }
   ```
   
   + 算法二：改进的暴力（时间复杂度$O(N^2)$）
   
   ```cpp
   int MaxSubseqSum2(int A[], int N) {
       int ThisSum, MaxSum = 0;
       int i, j;
       for (i = 0; i < N; i++) {     /* i是子列左端位置 */
           ThisSum = 0;              /* ThisSum是从A[i]到A[j]的子列和 */
           for (j = i; j < N; j++) { /* j是子列右端位置 */
               ThisSum += A[j];
               /*对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可*/
               if (ThisSum > MaxSum) /* 如果刚得到的这个子列和更大 */
                   MaxSum = ThisSum; /* 则更新结果 */
           }                         /* j循环结束 */
       }                             /* i循环结束 */
       return MaxSum;
   }
   ```
   
   + 算法三：分而治之（时间复杂度$O(N\log{N})$）
   
   思路是：从中线一分为二，计算左边的最大子列和，计算右边的最大子列和，计算跨越中线的最大子列和，比较三者，取最大值。
   
   递归的终止条件是，子列只有一个数。
   
   具体代码见仓库。
   
   + 算法四：在线计算（时间复杂度$O(N)$）
   
   “在线”的意思是指每输入一个数据就进行即时处理，在任 何一个地方中止输入，算法都能正确给出当前的解。
   
   ```cpp
   int MaxSubseqSum4(int A[], int N) {
       int ThisSum, MaxSum;
       int i;
       ThisSum = MaxSum = 0;
       for (i = 0; i < N; i++) {
           ThisSum += A[i]; /* 向右累加 */
           if (ThisSum > MaxSum)
               MaxSum = ThisSum; /* 发现更大和则更新当前结果 */
           else if (ThisSum < 0) /* 如果当前子列和为负 */
               ThisSum = 0;      /* 则不可能使后面的部分和增大，抛弃之 */
       }
       return MaxSum;
   }
   ```
   

---

编程作业：

1. 最大子列和问题，https://pintia.cn/problem-sets/15/problems/709 ，与课件相同

   代码见[./03-MaxSubseqSum.cpp](./03-MaxSubseqSum.cpp)

2. Maximum Subsequence Sum，https://pintia.cn/problem-sets/16/problems/663 ，问题1的改编

   代码见[./04-MaxSubseqSum.cpp](./04-MaxSubseqSum.cpp)

3. 二分查找，https://pintia.cn/problem-sets/15/problems/923

   代码见[./05-BinarySearch.cpp](./05-BinarySearch.cpp)

