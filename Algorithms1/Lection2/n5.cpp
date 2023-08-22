#include <iostream>
#include <vector>

int max(const std::vector<int> &array) {
    int max = array[0];
    for (int i = 1; i < array.size(); i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int findMaxIndex(const std::vector<int> &array, int max) {
    int index = -1;
    for (int i = 0; i < array.size(); i++) {
        if (max == array[i] && i + 2 < array.size()) {
            index = i;
            break;
        }
    }
    return index;
}

void foo(const std::vector<int> &array) {
    std::vector<int> variants;
    int max_main = max(array);
    int max_idx = findMaxIndex(array, max_main);
    if (max_idx == -1) {
        std::cout << "0" << std::endl;
    } else {
        for (int i = 0; i < array.size() - 1; i++) {
            if ((array[i] % 5 == 0 && array[i] % 10 != 0) && array[i] > array[i + 1] && i > max_idx) {
                variants.push_back(array[i]);
            }
        }
        if (variants.size() == 0) {
            std::cout << "0" << std::endl;
        } else {
            int max_tmp = max(variants);
            int col = 0;
            for (int i = 0; i < array.size(); i++) {
                if (array[i] > max_tmp) {
                    col++;
                }
            }
            col++;
            std::cout << col << std::endl;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> array(n);
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    foo(array);
    return 0;
}