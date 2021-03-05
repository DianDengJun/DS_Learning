// http://bailian.openjudge.cn/practice/4132/
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

double factor_value();     // 读因子求值
double term_value();       // 读项求值
double expression_value(); // 读表达式求值

int main() {
    cout.setf(ios::fixed);
    cout << setprecision(2) << expression_value() << endl;
    return 0;
}

double factor_value() {
    double result{0.0};
    char c = cin.peek();
    double afterDot{0.0};
    if (c == '(') {
        cin.get();
        result = expression_value();
        cin.get(); // 读右括号
    } else {
        while (isdigit(c) || c == '.') { // 是数字字符或小数点
            if (isdigit(c)) {
                if (afterDot == 0)
                    result = 10 * result + c - '0';
                else {
                    result += (c - '0') * afterDot;
                    afterDot /= 10;
                }
            } else if (c == '.') {
                afterDot = 0.1;
            }
            cin.get();
            c = cin.peek();
        }
    }
    return result;
}
double term_value() {
    double result = factor_value(); // 求第一个因子求值
    while (true) {
        char op = cin.peek(); // 看一个字符，不取走
        if (op == '*' || op == '/') {
            cin.get(); // 从输入中取走一个字符
            double value = factor_value();
            if (op == '*') result *= value;
            else
                result /= value;
        } else
            break;
    }
    return result;
}
double expression_value() {
    double result = term_value(); // 求第一项求值
    bool more = true;
    while (more) {
        char op = cin.peek(); // 看一个字符，不取走(可能剩下右括号)
        if (op == '+' || op == '-') {
            cin.get(); // 从输入流中取走'+'或'-'
            double value = term_value();
            if (op == '+') result += value;
            else
                result -= value;
        } else
            more = false;
    }
    return result;
}