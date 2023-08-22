#include <map>
#include <iostream>
#include <set>

void descendants(std::map<std::string, std::pair<long, std::set<std::string>>> &m2, std::string people, long len) {
    m2[people].first = len;
    if (m2.contains(people)) {
        for (auto c : m2[people].second) {
            descendants(m2, c, len + 1);
        }
    }
}

int main() {
    std::set<std::string> m;
    std::set<std::string> m_s;
    std::string unicum_s;
    std::map<std::string, std::pair<long, std::set<std::string>>> m2;
    long N;
    std::cin >> N;
    for (int i = 0; i < N - 1; i++) {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        m.insert(s1);
        m_s.insert(s2);
        m2[s2].second.insert(s1);
        m2[s2].first = -1;
    }
    for (auto it = m_s.begin(); it != m_s.end(); it++) {
        if (!m.count(*it)) {
            unicum_s = *it;
            m.insert(*it);
            break;
        }
    }
    descendants(m2, unicum_s, 0);
    for (auto it = m.begin(); it != m.end(); it++) {
        std::cout << *it << " " << m2[*it].first << std::endl;
    }
    return 0;
}