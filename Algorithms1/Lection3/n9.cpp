#include <iostream>
#include <set>
#include <map>

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, int> counters;
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;
        std::set<std::string> check;
        for (int j = 0; j < m; j++) {
            std::string lan;
            std::cin >> lan;
            if (!check.count(lan)) {
                check.insert(lan);
                counters[lan]++;
            }
        }
    }
    std::set<std::string> allKnow;
    std::set<std::string> allDK;
    for (auto it = counters.begin(); it != counters.end(); it++) {
        if (it->second == n) {
            allKnow.insert(it->first);
        }
        allDK.insert(it->first);
    }
    std::cout << allKnow.size() << std::endl;
    for (const std::string s : allKnow) {
        std::cout << s << std::endl;
    }
    std::cout << allDK.size() << std::endl;
    for (const std::string s : allDK) {
        std::cout << s << std::endl;
    }
    return 0;
}