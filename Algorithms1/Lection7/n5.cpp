#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main() {
    int N;
    std::cin >> N;
    int counter = 0;
    std::vector<std::pair<int, std::pair<int, int>>> array;
    for (int i = 0; i < N; i++) {
        int h1, h2, m1, m2;
        std::cin >> h1 >> m1 >> h2 >> m2;
        if (h1 * 60 + m1 != h2 * 60 + m2) {
            array.push_back({h1 * 60 + m1, {1, i}});
            array.push_back({h2 * 60 + m2, {-1, i}});
        } else {
            counter += 1;
        }
    }
    int time = 0;
    if (counter != N && N != 0) {
        int time_start = -1;
        std::sort(array.begin(), array.end());
        std::set<std::pair<int, int>> first_set;
        std::set<int> open_cas;
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < array.size(); i++) {
                if (array[i].second.first == -1) {
                    if (open_cas.count(array[i].second.second)) {
                        counter -= 1;
                        open_cas.erase(array[i].second.second);
                    }
                } else {
                    counter += 1;
                    open_cas.insert(array[i].second.second);
                }
                if (counter == N && time_start == -1) {
                    time_start = array[i].first;
                } else if (counter != N && time_start != -1) {
                    if (!first_set.count({std::min(time_start, array[i].first), std::max(time_start, array[i].first)})) {
                        first_set.insert({std::min(time_start, array[i].first), std::max(time_start, array[i].first)});
                        if (time_start > array[i].first) {
                            time += ((24 * 60) - time_start) + array[i].first;
                        } else {
                            time += array[i].first - time_start;
                        }
                    }
                    time_start = -1;
                }
            }
        }
    } else {
        time = 24 * 60;
    }
    std::cout << time << std::endl;
    return 0;
}