#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int N, W, L;
    std::cin >> N >> W >> L;
    std::vector<std::pair<int, std::pair<int, std::pair<long, int>>>> array(N * 2);
    for (int i = 0; i < 2 * N; i += 2) {
        long x1, y1, z1, x2, y2, z2;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        array[i].first = z1;
        array[i].second.first = 1;
        array[i].second.second.first = (x2 - x1) * (y2 - y1);
        array[i].second.second.second = i / 2 + 1;
        array[i + 1].first = z2;
        array[i + 1].second.first = -1;
        array[i + 1].second.second.first = (x2 - x1) * (y2 - y1);
        array[i + 1].second.second.second = i / 2 + 1;
    }
    std::sort(array.begin(), array.end());
    long sqrt = W * L, sqrt_tmp = 0, min_block = N + 1, col_block = 0;
    std::set<int> numbers, finset;
    for (int i = 0; i < 2 * N; i++) {
        if (array[i].second.first == 1) {
            sqrt_tmp += array[i].second.second.first;
            col_block += 1;
            numbers.insert(array[i].second.second.second);
        } else {
            sqrt_tmp -= array[i].second.second.first;
            col_block -= 1;
            numbers.erase(array[i].second.second.second);
        }
        if (sqrt_tmp == sqrt) {
            if (min_block > col_block) {
                min_block = col_block;
                finset = numbers;
            }
        }
    }
    if (min_block == N + 1) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        std::cout << min_block << std::endl;
        for (int c : finset) {
            std::cout << c << std::endl;
        }
    }
    return 0;
}