#include <iostream>
#include <map>

int main() {
    int n, m;
    std::cin >> n;
    std::map<int, int> m1;
    for (int i = 0; i < n; i++) {
        int number, snumber;
        std::cin >> number >> snumber;
        m1[number] = snumber;
    }

    auto it = m1.begin();
    int prefics1[n], prefics2[n], first = it->second, idx = 1;
    prefics1[0] = 0;
    prefics2[0] = 0;
    it++;
    for (; it != m1.end(); it++) {
        int lam = it->second - first;
        if (lam > 0) {
            prefics1[idx] = prefics1[idx - 1] + lam;
            prefics2[idx] = prefics2[idx - 1];
        } else if (lam < 0) {
            prefics2[idx] = prefics2[idx - 1] + abs(lam);
            prefics1[idx] = prefics1[idx - 1];
        } else {
            prefics2[idx] = prefics2[idx - 1];
            prefics1[idx] = prefics1[idx - 1];
        }
        first = it->second;
        idx++;
    }

    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int start, end;
        std::cin >> start >> end;
        if (start <= end) {
            std::cout << (prefics1[end - 1] - prefics1[start - 1]) << std::endl; 
        } else {
            std::cout << (prefics2[start - 1] - prefics2[end - 1]) << std::endl;
        }
    }

    return 0;
}