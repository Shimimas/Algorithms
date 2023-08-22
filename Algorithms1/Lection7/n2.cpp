#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int main() {
    long N, M;
    std::fstream file("input.txt");
    file >> N >> M;
    std::vector<std::pair<long, std::pair<int, int>>> array(2 * N + M);
    std::vector<std::pair<int, long>> res_vector(M);
    for (int i = 0; i < 2 * N; i += 2) {
        long x1, x2;
        file >> x1 >> x2;
        array[i].first = std::min(x1, x2);
        array[i + 1].first = std::max(x1, x2);
        array[i].second.first = -1;
        array[i + 1].second.first = 1;
    }
    for (int i = 2 * N; i < 2 * N + M; i++) {
        file >> array[i].first;
        array[i].second.first = 0;
        array[i].second.second = i;
    }
    std::sort(array.begin(), array.end());
    long counter = 0;
    int rvi = 0;
    for (auto ell : array) {
        if (ell.second.first == -1) {
            counter += 1;
        } else if (ell.second.first == 1) {
            counter -= 1;
        } else {
            res_vector[rvi].first = ell.second.second;
            res_vector[rvi].second = counter;
            rvi++;
        }
    }
    std::sort(res_vector.begin(), res_vector.end());
    for (auto c : res_vector) {
        std::cout << c.second << " ";
    }
    return 0;
}