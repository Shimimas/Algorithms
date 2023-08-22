#include <iostream>
#include <set>

int main() {
    std::set<int> list1, list2;
    int value;
    while (std::cin.peek() != '\n' && std::cin >> value) {
        list1.insert(value);
    }
    std::cin.get();
    while (std::cin.peek() != '\n' && std::cin >> value) {
        list2.insert(value);
    }
    for (auto it = list1.begin(); it != list1.end(); it++) {
        if (list2.count(*it)) {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}