#include <iostream>

void foo(int N, int M, int K, int bomb[][2]) {
    int matrix[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < K; i++) {
        int x = bomb[i][0] - 1, y = bomb[i][1] - 1;
        matrix[x][y] = -1;
        for (int x_p = x - 1; x_p <= x + 1 && x_p < N; x_p++) {
            for (int y_p = y - 1; y_p <= y + 1 && y_p < M; y_p++) {
                if (x_p >= 0 && y_p >= 0) {
                    if (matrix[x_p][y_p] != -1) {
                        matrix[x_p][y_p]++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matrix[i][j] == -1) {
                std::cout << "*";
            } else {
                std::cout << matrix[i][j];
            }
            if (j == M - 1) {
                std::cout << std::endl;
            } else {
                std::cout << " ";
            }
        }
    }
}

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    int bomb[K][2];
    for (int i = 0; i < K; i++) {
        std::cin >> bomb[i][0] >> bomb[i][1];
    }
    foo(N, M, K, bomb);
}
