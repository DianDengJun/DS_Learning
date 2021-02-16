// http://bailian.openjudge.cn/practice/2810/

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for (int a = 2; a <= N; a++)
        for (int b = 2; b <= N; b++)
            for (int c = b; c <= N; c++)
                for (int d = c; d <= N; d++)
                    if (a * a * a == b * b * b + c * c * c + d * d * d)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
    return 0;
}