#include<iostream>

int main() {
    char c;
    bool stop = true;
    std::string val;
    long max1, max2, min1, min2;
    std::cin >> max1 >> max2;
    if (max1 < max2) {
        std::swap(max1, max2);
    }
    min1 = max2;
    min2 = max1;
    long value;
    while (std::cin.peek() != '\n' && std::cin >> value) {
        if (value > max1) {
            max2 = max1;
            max1 = value;
        } else if (value > max2) {
            max2 = value;
        } else if (value < min1) {
            min2 = min1;
            min1 = value;
        } else if (value < min2) {
            min2 = value;
        }
        if (std::cin.peek() == ' ') {
            std::cin.get();
        }
    }
    min1 * min2 > max1 * max2 ? std::cout << std::min(min1, min2) << " " << std::max(min1, min2) << std::endl : std::cout << std::min(max1, max2) << " " << std::max(max1, max2) << std::endl;
    return 0;
}