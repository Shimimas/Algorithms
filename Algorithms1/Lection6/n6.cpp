#include <iostream>

long fx(long m, long x, long y, long n) {
    return x + std::max(m * x, (n - m) * y);
}

long binsearch(long n, long x, long y) {
    n = n - 1;
    long l = 0, r = n;
    if (x > y) {
        std::swap(x, y);
    }
    while (l < r) {
        long m = (l + r) / 2;
        if (fx(m, x, y, n) <= fx(m + 1, x, y, n)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return fx(l, x, y, n);
}

int main() {
    long n, x, y;
    std::cin >> n >> x >> y;
    std::cout << binsearch(n, x, y) << std::endl;
}