#include <iostream>
#include <set>

int main() {
    int n;
    std::set<int> tort;
    std::cin >> n;
    int a, b;
    int result = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        if (a + b + 1 == n && a >= 0 && b >= 0) {
            if (!tort.count(a + 1)) {
                result++;
                tort.insert(a + 1);
            }
        }
    }
    std::cout << result << std::endl;
}