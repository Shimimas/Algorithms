#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main() {
    int K;
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        int N;
        std::cin >> N;
        long counter = 0;
        std::vector<std::pair<int, std::pair<int, int>>> array(N * 2);
        for (int j = 0; j < 2 * N; j += 2) {
            std::cin >> array[j].first >> array[j + 1].first;
            if (array[j].first == 0 && array[j + 1].first == 10000) {
                counter += 1;
            }
            array[j].first %= 10000;
            array[j + 1].first %= 10000;
            array[j].second.first = -1;
            array[j + 1].second.first = 1;
            array[j].second.second = j;
            array[j + 1].second.second = j;
        }
        std::sort(array.begin(), array.end());
        std::set<int> safer;
        std::set<int> fin_set;
        bool voidPlace = true;
        for (int j = 0; j < 2 * N; j++) {
            if (array[j].second.first == -1) {
                safer.insert(array[j].second.second);
                counter += 1;
            } else {
                if (safer.count(array[j].second.second)) {
                    counter -= 1;
                    safer.erase(array[j].second.second);
                }
            }
        }
        for (int j = 0; j < 2 * N; j++) {
            if (array[j].second.first == -1) {
                safer.insert(array[j].second.second);
                counter += 1;
            } else {
                if (safer.count(array[j].second.second)) {
                    counter -= 1;
                    safer.erase(array[j].second.second);
                }
            }
            if (counter == 1) {
                fin_set.insert(*safer.begin());
            }
            if (counter == 0) {
                voidPlace = false;
            }
        }
        if (voidPlace == false || fin_set.size() != N) {
            std::cout << "Wrong Answer" << std::endl;
        } else {
            std::cout << "Accepted" << std::endl;
        }
    }
    return 0;
}