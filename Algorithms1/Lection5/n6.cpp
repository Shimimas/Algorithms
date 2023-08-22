#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> fans(n);
    for (int i = 0; i < n; i++) {
        std::cin >> fans[i];
    }
    std::sort(fans.begin(), fans.end());
    std::cin >> m;
    std::map<int, int> m1;
    for (int i = 0; i < m; i++) {
        int vatt, price;
        std::cin >> vatt >> price;
        if (!m1.contains(vatt)) {
            m1[vatt] = price;
        } else if (m1[vatt] > price) {
            m1[vatt] = price;
        }
    }
    auto it = m1.crbegin();
    int p1 = n - 1, p2 = m - 1, min = it->second, result = 0;
    while (p1 >= 0) {
        if (it != m1.crend() && it->first >= fans[p1]) {
            if (min > it->second) {
                min = it->second;
            }
            it++;
        } else {
            result += min;
            it = m1.crbegin();
            min = it->second;
            p1--;
        }
    }
    std::cout << result << std::endl;
    return 0;
}