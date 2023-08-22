#include <iostream>
#include <cmath>

int main() {
    int n;
    double f_a;
    double l = 30, r = 4000; 
    std::cin >> n >> f_a;
    for (int i = 0; i < n - 1; i++) {
        double f;
        std::string word;
        std::cin >> f >> word;
        if (word[0] == 'c') {
            if (f > f_a) {
                l = std::max(l, (f_a + f) / 2.0);
            } else {
                r = std::min(r, (f_a + f) / 2.0);
            }
        } else {
            if (f > f_a) {
                r = std::min(r, (f_a + f) / 2.0);
            } else {
                l = std::max(l, (f_a + f) / 2.0);
            }
        }
        f_a = f;
    }
    std::cout.setf(std::ios::fixed);
    std::cout.precision(6);
    std::cout << l << " " << r << std::endl;
}