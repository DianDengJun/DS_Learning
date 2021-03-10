#include <cmath>
#include <iostream>

using namespace std;
constexpr double EPS = 1e-6;

inline double f(double x) {
    return pow(x, 5) - 15 * pow(x, 4) + 85 * pow(x, 3) - 225 * x * x + 274 * x - 121;
}

int main() {
    double root, x1 = 1.5, x2 = 2.4, y;
    root = x1 + (x2 - x1) / 2;
    y = f(root);
    while (fabs(y) > EPS) {
        if (y > 0)
            x1 = root;
        else
            x2 = root;
        root = x1 + (x2 - x1) / 2;
        y = f(root);
    }
    printf("%.6f\n", root);

    return 0;
}
