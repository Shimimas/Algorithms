#include <iostream>

long long binsearch(long long n, long long m, long long t) {
    if (m < n) {
        std::swap(m, n);
    }
    long long l = 0, r = n / 2;
    while (l < r) {
        long long mid = (l + r + 1) / 2;
        if (2 * mid * (m + n - 2 * mid) <= t) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
    long long n, m, t;
    std::cin >> n >> m >> t;
    std::cout << binsearch(n, m, t) << std::endl;
}