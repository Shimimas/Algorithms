#include <iostream>
#include <vector>
#include <algorithm>

bool checkfun(long n, long m, long k, const std::vector<long> &array) {
    long summ = 0;
    for (long i = 0; i < n; i++) {
        summ += array[i] / m; 
    }
    return summ >= k ? true : false;
}

long binsearch(long n, long k, const std::vector<long> &array) {
    long l = 0, r = array[n - 1];
    while (l < r) {
        long m = (l + r + 1) / 2;
        if (checkfun(n, m, k, array)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main() {
    long n, k;
    std::cin >> n >> k;
    std::vector<long> array(n);
    for (long i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    std::sort(array.begin(), array.end());
    std::cout << binsearch(n, k, array) << std::endl;
    return 0;
}