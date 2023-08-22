#include <iostream>

int main() {
    int f1 = 0, f2 = 0, n, m;
    std::cin >> n;
    long n1[n];
    for (int i = 0; i < n; i++) {
        std::cin >> n1[i];
    }
    std::cin >> m;
    long n2[m];
    for (int i = 0; i < m; i++) {
        std::cin >> n2[i];
    }
    long min = abs(n1[f1] - n2[f2]), first = n1[f1], second = n2[f2];
    while (f1 < n && f2 < m) {
        if (min > abs(n1[f1] - n2[f2])) {
            min = abs(n1[f1] - n2[f2]);
            first = n1[f1];
            second = n2[f2];
        }
        if (n1[f1] > n2[f2]) {
            f2++;
        } else if (n1[f1] < n2[f2]) {
            f1++;
        } else {
            break;
        }
    }
    std::cout << first << " " << second << std::endl;
    return 0;
}