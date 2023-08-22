#include <iostream>
#include <vector>

void foo(const std::vector<double> &array) {
    int result = 0;
    for (int i = 1; i < array.size() - 1; i++) {
        if (array[i] > array[i - 1] && array[i] > array[i + 1]) {
            result++;
        }
    }
    std::cout << result << std::endl;
}

int main() {
    std::vector<double> array;
    double value;
    while (std::cin.peek() != '\n') {
        std::cin >> value;
        array.push_back(value);
    }
    foo(array);
    return 0;
}