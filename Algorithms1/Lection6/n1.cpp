#include <iostream>
#include <algorithm>
#include <vector>

int binsearch(int l, int r, const std::vector<long> &array, long x) {
    while (l < r) {
        int m = (l + r) / 2;
        if (array[m] >= x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<long> array1(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array1[i];
    }
    std::sort(array1.begin(), array1.end());
    for (int i = 0; i < k; i++) {
        long x;
        std::cin >> x;
        int idx = binsearch(0, n - 1, array1, x);
        array1[idx] == x ? std::cout << "YES" << std::endl : std::cout << "NO" << std::endl;
    }
    return 0;
}