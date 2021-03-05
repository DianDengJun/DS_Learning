// http://bailian.openjudge.cn/practice/2694/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

double exp() {
    // 读入一个逆波兰表达式，并计算其值
    char s[20];
    cin >> s;
    switch (s[0])
    {
    case '+':
        return exp() + exp();
        break;
    case '-':
        return exp() - exp();
        break;
    case '*':
        return exp() * exp();
        break;
    case '/':
        return exp() / exp();
        break;
    default:
        return atof(s); // 将一个字符串转换为浮点数
        break;
    }
}

int main() {
    printf("%lf", exp());
    return 0;
}