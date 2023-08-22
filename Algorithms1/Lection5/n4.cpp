#include <iostream>

int main() {
    int n, left = 0, right = 0;
    long r;
    std::cin >> n >> r;
    long mem[n];
    for (int i = 0; i < n; i++) {
        std::cin >> mem[i];
    }
    long counter = 0;
    while (right < n && left < n) {
        if (mem[right] - mem[left] <= r) {
            right++;
        } else {
            counter += n - right;
            left++;
        }
    }
    std::cout << counter << std::endl;
    return 0;
}