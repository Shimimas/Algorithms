#include <iostream>

void foo(int A, int B, int C, int D, int E) {
    if ((D >= A && E >= B) || (D >= B && E >= A) || (D >= B && E >= C) || (D >= C && E >= B) || (D >= A && E >= C) || (D >= C && E >= A)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
}

int main() {
    int A, B, C, D, E;
    std::cin >> A >> B >> C >> D >> E;
    foo(A, B, C, D, E);
    return 0;
}