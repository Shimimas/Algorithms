#include <iostream>
#include <map>

int main() {
    int n;
    std::map<long, long> heap;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        long w, h;
        std::cin >> w >> h;
        !heap.contains(w) ? heap[w] = h : heap[w] = std::max(heap[w], h);
    }
    long result = 0;
    for (auto it = heap.begin(); it != heap.end(); it++) {
        result += it->second;
    }
    std::cout << result << std::endl;
    return 0;
}