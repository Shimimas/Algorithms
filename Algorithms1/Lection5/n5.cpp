#include <iostream>
#include <map>

int main() {
    int n, k, l = 0, r = 0, l_fin = 1;
    std::cin >> n >> k;
    int r_fin = n; 
    std::map<double, int> m;
    double gar[n];
    for (int i = 0; i < n; i++) {
        std::cin >> gar[i];
    }
    int min = n;
    while (l < n && r < n) {
        m.contains(gar[r]) ? m[gar[r]]++ : m[gar[r]] = 1;
        if (m.size() == k && l <= r) {
            if (min > r - l + 1) {
                min = r - l + 1;
                l_fin = l + 1;
                r_fin = r + 1;
            }
            if (m[gar[l]] == 1) {
                m.erase(gar[l]);
            } else {
                m[gar[l]]--;
            }
            l++;
            m[gar[r]]--;
        } else {
            r++;
        }
    }
    std::cout << l_fin << " " << r_fin << std::endl;
    return 0;
}