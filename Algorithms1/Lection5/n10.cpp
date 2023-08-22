#include <iostream>
#include <map>
#include <set>

int main() {
    int n;
    std::cin >> n;
    long m[n][2];
    for (int i = 0; i < n; i++) {
        std::cin >> m[i][0] >> m[i][1];
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
        std::set<std::pair<long, long>> s_set;
        std::map<long, long> m_map;
        for (int j = 0; j < n; j++) {
            long vec_x = m[j][0] - m[i][0];
            long vec_y = m[j][1] - m[i][1];
            long vec_len = vec_x * vec_x + vec_y * vec_y;
            if (s_set.count({vec_x, vec_y})) {
                ans -= 1;
            }
            s_set.insert({-vec_x, -vec_y});
            !m_map.contains(vec_len) ? m_map[vec_len] = 1 : m_map[vec_len]++;
        }
        for (auto it = m_map.begin(); it != m_map.end(); it++) {
            if (it->first != 0) {
                ans += ((it->second - 1) * (it->second)) / 2;
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}