#include<iostream>

int main() {
    long max1, max2, max3, min1, min2;
    std::cin >> max1 >> max2 >> max3;
    if (max1 > max2) {
        std::swap(max1, max2);
    }
    if (max2 > max3) {
        std::swap(max2, max3);
    }
    if (max1 > max2) {
        std::swap(max1, max2);
    }
    min1 = max1;
    min2 = max2;
    long value;
    while (std::cin.peek() != '\n' && std::cin >> value) {
        if (value > max3) {
            max1 = max2;
            max2 = max3;
            max3 = value;
        } else if (value > max2) {
            max1 = max2;
            max2 = value;
        } else if (value > max1) {
            max1 = value;
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
    long result1 = max1 * max2 * max3, result2 = min1 * min2 * max3;
    result1 > result2 ? std::cout << max1 << " " << max2 << " " << max3 << std::endl : std::cout << min1 << " " << min2 << " " << max3 << std::endl;
    return 0;
}