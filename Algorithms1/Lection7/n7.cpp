#include <iostream>

struct staff {
    int T, Z, Y, col_nad = 0, time_all_nad = 0, all = 0;
    bool r = false;
};

int main() {
    int N, M;
    std::cin >> M >> N;
    struct staff array[N];
    for (int i = 0; i < N; i++) {
        std::cin >> array[i].T >> array[i].Z >> array[i].Y;
    }
    while (M) {
        int min_time = array[0].time_all_nad + array[0].T;
        int min_idx = 0;
        for (int i = 1; i < N; i++) {
            if (array[i].time_all_nad + array[i].T < min_time) {
                min_time = array[i].time_all_nad + array[i].T;
                min_idx = i;
            }
        }
        array[min_idx].time_all_nad += array[min_idx].T;
        array[min_idx].col_nad += 1;
        array[min_idx].all += 1;
        array[min_idx].r = false;
        M--;
        if (array[min_idx].col_nad == array[min_idx].Z) {
            array[min_idx].time_all_nad += array[min_idx].Y;
            array[min_idx].r = true;
            array[min_idx].col_nad = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if (array[i].r == true) {
            array[i].time_all_nad -= array[i].Y;
        }
    }
    int max = array[0].time_all_nad;
    for (int i = 1; i < N; i++) {
        if (max < array[i].time_all_nad) {
            max = array[i].time_all_nad;
        }
    }
    std::cout << max << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << array[i].all << " ";
    }
    return 0;
}