#include <iostream>

int main() {
    long k;
    std::cin >> k;
    std::string s;
    std::cin >> s;
    long result = 0;
    for (long l = 0, r = k; r < s.size();) {
        if (s[l] == s[r]) {
            long l_tmp = l;
            while (r < s.size() && s[l] == s[r]) {
                r++;
                l++;
            }
            long range = r - l_tmp - k;
            result += ((range + 1) * range) / 2;
        } else {
            r++;
            l++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}