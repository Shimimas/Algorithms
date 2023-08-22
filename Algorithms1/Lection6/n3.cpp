#include <iostream>

long binsearch(long w, long h, long n) {
    long l = 1, r = std::max(w, h) * n;
    while (l < r) {
        long m = (l + r) / 2;
        if ((m / w) * (m / h) >= n) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    long w, h, n;
    std::cin >> w >> h >> n;
    std::cout << binsearch(w, h, n) << std::endl;
    return 0;
}