#include <iostream>

void Triengle(int a, int b, int c) {
    if ((a + b) > c && (a + c) > b && (c + b) > a && a > 0 && b > 0 && c > 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    Triengle(a, b, c);
    return 0;
}