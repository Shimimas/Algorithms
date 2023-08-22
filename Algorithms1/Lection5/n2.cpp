#include <iostream>

int main() {
    int n;
    long k;
    std::cin >> n >> k;
    long prefics[n + 1];
    long number;
    prefics[0] = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> number;
        prefics[i + 1] = prefics[i] + number;
    }
    int l = 0, r = 0;
    long result = 0;
    while (l <= n && r <= n && l <= r) {
        if (prefics[r] - prefics[l] < k) {
            r++;
        } else if (prefics[r] - prefics[l] > k) {
            l++;
        } else {
            result++;
            r++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}