#include <iostream>
#include <map>

int main() {
    int n, k;
    std::map<int, int> buttons;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int c;
        std::cin >> c;
        buttons[i + 1] = c;
    }
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        int c;
        std::cin >> c;
        buttons[c]--;
    }
    for (int i = 1; i <= n; i++) {
        buttons[i] >= 0 ? std::cout << "NO" << std::endl : std::cout << "YES" << std::endl;
    }
    return 0;
}