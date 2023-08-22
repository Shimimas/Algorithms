#include <iostream>

void foo(int a, int b, int c, int d) {
    int x1 = a + c, x2 = a + d, x3 = b + c, x4 = b + d, y1, y2, y3, y4;
    if (b >= d) {
        y1 = b;
    } else {
        y1 = d;
    }
    if (b >= c) {
        y2 = b;
    } else {
        y2 = c;
    }
    if (a >= d) {
        y3 = a;
    } else {
        y3 = d;
    }
    if (a >= c) {
        y4 = a;
    } else {
        y4 = c;
    }
    int s[4];
    s[0] = x1 * y1;
    s[1] = x2 * y2;
    s[2] = x3 * y3;
    s[3] = x4 * y4;
    int min = s[0];
    int idx = 0;
    for (int i = 1; i < 4; i++) {
        if (s[i] < min) {
            min = s[i];
            idx = i;
        }
    }
    if (idx == 0) {
        std::cout << x1 << " " << y1 << std::endl;
    } else if (idx == 1) {
        std::cout << x2 << " " << y2 << std::endl;
    } else if (idx == 2) {
        std::cout << x3 << " " << y3 << std::endl;
    } else {
        std::cout << x4 << " " << y4 << std::endl;
    }
}

int main() {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    foo(a, b, c, d);
    return 0;
}