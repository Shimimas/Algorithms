#include <iostream>

int binsearch(int L, int array1[], int array2[]) {
    int i = 0, j = 0;
    while (i + j != L - 1) {
        if (array1[i] <= array2[j]) {
            i++;
        } else {
            j++;
        }
    }
    return std::min(array1[i], array2[j]);
}

int main() {
    int N, L;
    std::cin >> N >> L;
    int array[N][L];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            std::cin >> array[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            std::cout << binsearch(L, array[i], array[j]) << std::endl;
        }
    }
}