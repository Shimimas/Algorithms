#include <iostream>

long binsearch(long n, long a, long b, long w, long h) {
    long l = 0, r = (std::max(w, h) - std::min(a, b)) / 2;
    while (l < r) {
        long m = (l + r + 1) / 2;
        if ((w / (a + (2 * m))) * (h / (b + (2 * m))) >= n || (w / (b + (2 * m))) * (h / (a + (2 * m))) >= n) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main() {
    long n, a, b, w, h;
    std::cin >> n >> a >> b >> w >> h;
    std::cout << binsearch(n, a, b, w, h) << std::endl;
    return 0;
}