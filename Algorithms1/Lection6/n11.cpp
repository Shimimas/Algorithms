#include <iostream>

long element(long array[], int i, long &last_r, long &last_d) {
    if (i != 0) {
        if (i != 1) {
            last_d = (array[2] * last_d + array[3]) % array[4];
        }
        last_r += last_d;
    } 
    return last_r;
}

int binsearch3(long array[], long x, int L) {
    int l = 0, r = L - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (array[m] > x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return array[l] > x ? l : L;
}

int binsearch2(long array[], long x, int L) {
    int l = 0, r = L - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (array[m] >= x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return array[l] >= x ? l : L;
}

long binsearch(int L, long array1[], long array2[]) {
    long l = std::min(array1[0], array2[0]), r = std::max(array1[L - 1], array2[L - 1]);
    while (l < r) {
        long m = (l + r) / 2;
        int less = binsearch2(array1, m, L) + binsearch2(array2, m, L);
        int greate = 2 * L - binsearch3(array1, m, L) - binsearch3(array2, m, L);
        if (less <= L - 1 && greate <= L) {
            return m;
        } else if (less > L - 1) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    long N, L;
    std::cin >> N >> L;
    long array[N][5], array1[N][L];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> array[i][j];
        }
        long last_r_1 = array[i][0], last_d_1 = array[i][1];
        for (int j = 0; j < L; j++) {
            array1[i][j] = element(array[i], j, last_r_1, last_d_1);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            std::cout << binsearch(L, array1[i], array1[j]) << std::endl;
        }
    }
}