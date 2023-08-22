#include <iostream>

int main() {
    int tr, tc;
    std::string set;
    std::cin >> tr >> tc;
    std::cin >> set;

    if (set == "heat") {
        if (tc > tr) {
            std::cout << tc << std::endl;
        } else {
            std::cout << tr << std::endl;
        }
    } else if (set == "freeze") {
        if (tc > tr) {
            std::cout << tr << std::endl;
        } else {
            std::cout << tc << std::endl;
        }
    } else if (set == "auto") {
        std::cout << tc << std::endl;
    } else {
        std::cout << tr << std::endl;
    }
    return 0;
}