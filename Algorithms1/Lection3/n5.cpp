#include <iostream>
#include <set>

int main() {
    std::set<char> buttons;
    char c;
    for (int i = 0; i < 3; i++) {
        std::cin >> c;
        buttons.insert(c);
    }
    std::cin.get();
    int result = 0;
    while (std::cin.peek() != '\n' && std::cin >> c) {
        if (!buttons.count(c)) {
            result++;
            buttons.insert(c);
        }
    }
    std::cout << result << std::endl;
    return 0;
}