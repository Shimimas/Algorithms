#include <iostream>

void preficsSumm(int array[], int * prefics, int n) {
    bool cross = false;
    for (int i = 0, j = n - 1, i_tmp = 0; i < n;) {
        if (array[i_tmp] == array[j]) {
            prefics[i]++;
            i_tmp++;
            j--;
            if (i_tmp >= j) {
                cross = true;
            }
        } else {
            j = n - 1;
            if (cross == false) {
                prefics[i] = 0;
            } else {
                cross = false;
            }
            i++;
            i_tmp = i;
        }
    }
}

int findMaxIdx(int * prefics, int n) {
    int max = prefics[0];
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (max < prefics[i]) {
            max = prefics[i];
            max_idx = i;
        }
    }
    if (max == 0) {
        max_idx = -1;
    }
    return max_idx;
}

void printAnswer(int array[], int max_idx) {
    std::cout << max_idx << std::endl;
    for (int i = max_idx - 1; i > -1; i--) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void foo(int array[], int n) {
    int * prefics = new int[n];
    preficsSumm(array, prefics, n);
    int max_idx = findMaxIdx(prefics, n);
    if (max_idx == -1) {
        max_idx = n - 1;
    }
    printAnswer(array, max_idx);
}

int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    foo(array, n);
    return 0;
}
