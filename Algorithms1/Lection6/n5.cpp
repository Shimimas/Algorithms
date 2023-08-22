#include <iostream>

bool checkfun(long summ, long col, long m) {
    return 2 * (summ + (m * 5)) >= 7 * (col + m) ? true : false;
}

long binsearch(long a, long b, long c) {
    long l = 0, r = a + b + c, col = a + b + c, summ = (a * 2) + (b * 3) + (c * 4);
    while (l < r) {
        long m = (l + r) / 2;
        if (checkfun(summ, col, m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    long a, b, c;
    std::cin >> a >> b >> c;
    std::cout << binsearch(a, b, c) << std::endl;
    return 0;
}