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