#include <iostream>
#include <vector>
#include <algorithm>

bool checkfun(long N, long C, long R, long m, const std::vector<long> &array) {
    long col = 0;
    for (long i = 0, j = C - 1; j < N;) {
        if (array[j] - array[i] <= m) {
            col += 1;
            i = j + 1;
            j += C;
        } else {
            i++;
            j++;
        }
    }
    return col >= R ? true : false;
}

long binsearch(long N, long R, long C, const std::vector<long> &array) {
    long l = 0, r = array[N - 1];
    while (l < r) {
        long m = (l + r) / 2;
        if (checkfun(N, C, R, m, array)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    long N, R, C;
    std::cin >> N >> R >> C;
    std::vector<long> array(N);
    for (long i = 0; i < N; i++) {
        std::cin >> array[i];
    }
    std::sort(array.begin(), array.end());
    std::cout << binsearch(N, R, C, array) << std::endl;
    return 0;
}