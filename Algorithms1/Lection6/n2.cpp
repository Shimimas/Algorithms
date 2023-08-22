#include <iostream>

long binsearch(int l, int r, long array[], long x) {
    while (l < r) {
        int m = (l + r) / 2;
        if (array[m] > x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if (l > 0 && abs(array[l - 1] - x) <= abs(array[l] - x)) {
        l = l - 1;
    }
    return array[l];
}

int main() {
    int n, k;
    std::cin >> n >> k;
    long array[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    for (int i = 0; i < k; i++) {
        long x;
        std::cin >> x;
        std::cout << binsearch(0, n - 1, array, x) << std::endl;
    }
    return 0;
}