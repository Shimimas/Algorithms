#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<long, std::pair<long, long>>> pallets(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a;
        std::cin >> b;
        pallets[i] = std::make_pair(a + b, std::make_pair(a, b));
    }
    std::sort(pallets.begin(), pallets.end());
    long res = 0;
    for (int i = 0; i < n; i++) {
        bool can = false;
        for (int j = i + 1; j < n; j++) {
            long f_i = pallets[i].second.first;
            long s_i = pallets[i].second.second;
            long f_j = pallets[j].second.first;
            long s_j = pallets[j].second.second;
            if ((f_i < f_j && s_i < s_j) || (f_i < s_j && s_i < f_j)) {
                can = true;
                break;
            }
        }
        if (!can) {
            res += 1;
        }
    }
    std::cout << res << std::endl;
    return 0;
}