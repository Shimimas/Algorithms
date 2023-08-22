#include <iostream>
#include <cmath>

void foo(int array[], int n, int x) {
    int ell = array[0];
    int min = abs(array[0] - x);
    for (int i = 1; i < n; i++) {
        if (abs(array[i] - x) < min) {
            min = abs(array[i] - x);
            ell = array[i];
        }
    }
    std::cout << ell << std::endl;
}

int main() {
    int n, x;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
    }
    std::cin >> x;
    foo(array, n, x);
    return 0;
}