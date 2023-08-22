#include <iostream>
#include <map>

int main() {
    int n;
    long k;
    std::cin >> n >> k;
    std::map<long, int> m;
    for (int i = 0; i < n; i++) {
        long k;
        std::cin >> k;
        !m.contains(k) ? m[k] = 1 : m[k]++;
    }
    int l_idx = 0, r_idx = 0;
    long duplicates = 0, result = 0;
    auto r = m.begin();
    for (auto l = m.begin(); l != m.end(); l++, l_idx++) {
        while (r != m.end() && k * l->first >= r->first) {
            if (r->second >= 2) {
                duplicates++;
            }
            r_idx++;
            r++;
        }
        long range = r_idx - l_idx;
        if (l->second >= 3) {
            result += 1;
        }
        if (l->second >= 2) {
            result += (range - 1) * 3; 
        }
        result += (range - 2) * (range - 1) * 3;
        if (l->second >= 2) {
            duplicates--;
        }
        result += duplicates * 3;
    }
    std::cout << result << std::endl;
    return 0;
}