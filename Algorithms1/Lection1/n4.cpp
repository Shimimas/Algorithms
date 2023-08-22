#include <iostream>
#include <cmath>

void Root(int a, int b, int c) {
    if (a == 0 && b == c * c && c >= 0) {
        std::cout << "MANY SOLUTIONS" << std::endl;
    } else if (a == 0 || c < 0) {
        std::cout << "NO SOLUTION" << std::endl;
    } else {
        double x = ((double)(c * c - b) / (double)a);
        if (a * x + b >= 0 && fabs(x - (int)x) == 0) {
            std::cout << x << std::endl;
        } else {
            std::cout << "NO SOLUTION" << std::endl;
        }
    }
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    Root(a, b, c);
    return 0;
}