#include <iostream>
#include <vector>

void foo(std::vector<double> inputString) {
    bool flag = true;
    double tmp = inputString[0];
    for (int i = 1; i < inputString.size(); i++) {
        if (inputString[i] <= tmp) {
            flag = false;
        } else {
            tmp = inputString[i];
        }
    }
    if (flag == true) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    std::vector<double> inputVector;
    double value;
    while (std::cin.peek() != '\n') {
        std::cin >> value;
        inputVector.push_back(value);
    }
    foo(inputVector);
    return 0;
}