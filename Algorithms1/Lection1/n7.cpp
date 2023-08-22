#include <iostream>

void foo(int N, int K, int M) {
    int result = 0;
    int res_k = K / M;
    int delta = K % M;
    int col;
    if (K >= M) {
        while (N >= K) {
            col = N / K;
            N = N - (col * K) + (col * delta);
            result += col * res_k;
        }
    }
    std::cout << result << std::endl;
}

int main() {
    int N, K, M;
    std::cin >> N >> K >> M;
    foo(N, K, M);
    return 0;
}