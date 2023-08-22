#include <iostream>
#include <map>

int main() {
    int n, k;
    std::cin >> n >> k;
    char word[n];
    std::map<char, int> m;
    for (int i = 0; i < n; i++) {
        std::cin >> word[i];
    }
    int r = 0, max = 1, l_idx = 0;
    !m.contains(word[0]) ? m[word[0]] = 1 : m[word[0]]++;
    for (int l = 0; l < n; l++) {
        while (r < n && m[word[r]] <= k) {
            r++;
            !m.contains(word[r]) ? m[word[r]] = 1 : m[word[r]]++;
        }
        int range = r - l;
        if (max < range) {
            max = range;
            l_idx = l;
        }
        m[word[l]] == 1 ? m.erase(word[l]) : m[word[l]]--;
    }
    std::cout << max << " " << (l_idx + 1) << std::endl;
    return 0;
}