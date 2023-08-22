#include <iostream>
#include <vector>

bool constaintCheck(const std::vector<double> &array) {
    bool result = true;
    double tmp = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (tmp != array[i]) {
            result = false;
        }
    }
    return result;
}

bool ascendingCheck(const std::vector<double> &array) {
    bool result = true;
    double tmp = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (tmp >= array[i]) {
            result = false;
        } else {
            tmp = array[i];
        }
    }
    return result;
}

bool wAssendingCheck(const std::vector<double> &array) {
    bool result = true;
    double tmp = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (tmp > array[i]) {
            result = false;
        } else {
            tmp = array[i];
        }
    }
    return result;
}

bool descendingCheck(const std::vector<double> &array) {
    bool result = true;
    double tmp = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (tmp <= array[i]) {
            result = false;
        } else {
            tmp = array[i];
        }
    }
    return result;
}

bool wDescendingCheck(const std::vector<double> &array) {
    bool result = true;
    double tmp = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (tmp < array[i]) {
            result = false;
        } else {
            tmp = array[i];
        }
    }
    return result;
}

void foo(const std::vector<double> &array) {
    if (constaintCheck(array) == true) {
        std::cout << "CONSTANT" << std::endl;
    } else if (ascendingCheck(array) == true) {
        std::cout << "ASCENDING" << std::endl;
    } else if (wAssendingCheck(array) == true) {
        std::cout << "WEAKLY ASCENDING" << std::endl;
    } else if (descendingCheck(array)) {
        std::cout << "DESCENDING" << std::endl;
    } else if (wDescendingCheck(array)) {
        std::cout << "WEAKLY DESCENDING" << std::endl;
    } else {
        std::cout << "RANDOM" << std::endl;
    }
}

int main() {
    std::vector<double> array;
    double value;
    std::cin >> value;
    while (value != -2000000000) {
        array.push_back(value);
        std::cin >> value;
    }
    foo(array);
    return 0;
}