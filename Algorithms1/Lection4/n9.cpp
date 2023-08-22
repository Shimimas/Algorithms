#include <iostream>
#include <map>
#include <set>
#include <fstream>

std::string deleteCapture(const std::string &s) {
    std::string s1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s1.push_back(s[i] + 32);
        } else {
            s1.push_back(s[i]);
        }
    }
    return s1;
}

int amountCapture(const std::string &s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            result++;
        }
    }
    return result;
}

int main() {
    std::map<std::string, std::set<std::string>> m;
    int n, errors = 0;
    std::ifstream file("input.txt");
    file >> n;
    std::string s;
    for (int i = 0; i < n; i++) {
        file >> s;
        std::string woCap = deleteCapture(s);
        m[woCap].insert(s);
    }
    for (file >> s; !file.eof(); file >> s) {
        std::string check = deleteCapture(s);
        if (m.contains(check)) {
            if (!m[check].count(s)) {
                errors++;
            }
        } else {
            int col = amountCapture(s);
            if (col != 1) {
                errors++;
            }
        }
    }
    std::cout << errors << std::endl;
    return 0;
}