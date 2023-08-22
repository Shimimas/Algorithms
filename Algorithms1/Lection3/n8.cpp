#include <iostream>
#include <set>

int main() {
    std::set<long> birds;
    int n;
    long x, y;
    int result = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> y;
        if (!birds.count(x) && x != 0) {
            birds.insert(x);
            result++;
        } else if (x == 0) {
            result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}