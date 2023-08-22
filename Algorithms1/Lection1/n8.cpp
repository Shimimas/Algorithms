#include <iostream>

std::pair<int, int> min_max(int interval, int amount) {
    std::pair<int, int> result;
    result.first = (amount - 1) * (interval + 1) + 1;
    result.second = result.first + 2 * interval;
    return result;
}

void foo(int a, int b, int n, int m) {
    std::pair<int, int> result1 = min_max(a, n);
    std::pair<int, int> result2 = min_max(b, m);
    int min = std::max(result1.first, result2.first);
    int max = std::min(result1.second, result2.second);
    if (min > max) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << std::max(result1.first, result2.first) << " " << std::min(result1.second, result2.second) << std::endl;
    }
}

int main() {
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;
    foo(a, b, n, m);
    return 0;
}