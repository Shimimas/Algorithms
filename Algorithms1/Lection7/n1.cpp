#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int main() {
    long N, M;
    std::fstream file("input.txt");
    file >> N >> M;
    std::vector<std::pair<long, int>> array(2 * M); 
    for (int i = 0; i < 2 * M; i += 2) {
        long start, end;
        file >> start >> end;
        array[i].first = start;
        array[i].second = -1;
        array[i + 1].first = end;
        array[i + 1].second = 1;
    }
    std::sort(array.begin(), array.end());
    long counter = 0, len = 0;
    for (long i = 0; i < 2 * M; i++) {
        if (counter > 0) {
            len += array[i].first - array[i - 1].first;
        }
        if (array[i].second == -1) {
            counter += 1;
        } else {
            counter -= 1;
            if (counter == 0) {
                len += 1;
            }
        }
    }
    std::cout << (N - len) << std::endl;
    return 0;
}