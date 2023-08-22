#include <iostream>
#include <map>
#include <algorithm>

int main() {
    long n, m;
    std::map<char, long> m1, m2;
    std::string check;
    int counter = 0;
    std::cin >> n >> m;
    char c;
    for (int i = 0; i < n; i++) {
        std::cin >> c;
        m1.contains(c) ? m1[c]++ : m1[c] = 1;
    }
    std::cin >> check;
    for (int i = 0, j = 0; i < m; i++) {
        m2.contains(check[i]) ? m2[check[i]]++ : m2[check[i]] = 1;
        if (i >= n - 1) {
            if (m1 == m2) {
                counter++;
            }
            m2[check[j]]--;
            if (m2[check[j]] == 0) {
                m2.erase(check[j]);
            }
            j++;
        }
    }
    std::cout << counter << std::endl;
    return 0;
}