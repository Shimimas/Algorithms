#include <iostream>
#include <set>

int main() {
    std::set<int> inputSet;
    int value;
    int result = 0;
    while (std::cin.peek() != '\n' && std::cin >> value) {
        if (!inputSet.count(value)) {
            inputSet.insert(value);
            result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}