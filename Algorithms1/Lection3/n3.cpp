#include <iostream>
#include <set>

int main() {
    long N, M;
    std::cin >> N >> M;
    std::set<long> A, B;
    long value;
    for (int i = 0; i < N; i++) {
        std::cin >> value;
        A.insert(value);
    }
    for (int i = 0; i < M; i++) {
        std::cin >> value;
        B.insert(value);
    }
    int result = 0;
    std::set<long> res_set;
    for (auto it = A.begin(); it != A.end(); it++) {
        if (B.count(*it)) {
            res_set.insert(*it);
            result++;
        }
    }
    std::cout << result << std::endl;
    for (auto it = res_set.begin(); it != res_set.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    result = 0;
    for (auto it = A.begin(); it != A.end(); it++) {
        if (!res_set.count(*it)) {
            result++;
        }
    }
    std::cout << result << std::endl;
    for (auto it = A.begin(); it != A.end(); it++) {
        if (!res_set.count(*it)) {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
    result = 0;
    for (auto it = B.begin(); it != B.end(); it++) {
        if (!res_set.count(*it)) {
            result++;
        }
    }
    std::cout << result << std::endl;
    for (auto it = B.begin(); it != B.end(); it++) {
        if (!res_set.count(*it)) {
            std::cout << *it << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}