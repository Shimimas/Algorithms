#include <iostream>
#include <set>
#include <map>
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

bool correctSym(char c) {
    if (c == '_' || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return true;
    } else {
        return false;
    }
}

void resultFunction(const std::map<std::string, std::pair<long, long>> &m1, long max, long min) {
    std::string result;
    for (auto it = m1.begin(); it != m1.end(); it++) {
        if (it->second.first < min && it->second.second == max) {
            min = it->second.first;
            result = it->first;
        }
    }
    std::cout << result << std::endl;
}

bool letCheck(const std::string &s) {
    for (const char c : s) {
        if (c < '0' || c > '9') {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    std::string C, D;
    std::ifstream file("input.txt");
    std::map<std::string, std::pair<long, long>> m1;
    std::set<std::string> n1;
    file >> n >> C >> D;
    std::string s;
    for (int i = 0; i < n; i++) {
        file >> s;
        if (C == "no") {
            s = deleteCapture(s);
        }
        n1.insert(s);
    }
    char c;
    std::string ind;
    long max = 0, i = 0;
    for (file >> std::noskipws >> c; !file.eof(); file >> c) {
        if (correctSym(c)) {
            ind.push_back(c);
        } else if (ind.size()) {
            if (C == "no") {
                ind = deleteCapture(ind);
            }
            if (!n1.count(ind) && !(D == "no" && ind[0] >= '0' && ind[0] <= '9') && letCheck(ind)) {
                if (m1.contains(ind)) {
                    m1[ind].second++;
                } else {
                    m1[ind].first = i;
                    m1[ind].second = 1;
                }
                if (m1[ind].second > max) {
                    max = m1[ind].second;
                }
                i++;
            }
            ind.clear();
        }
    }
    if (correctSym(c)) {
        ind.push_back(c);
    } else if (ind.size()) {
        if (C == "no") {
            ind = deleteCapture(ind);
        }
        if (!n1.count(ind) && !(D == "no" && ind[0] >= '0' && ind[0] <= '9')) {
            if (m1.contains(ind)) {
                m1[ind].second++;
            } else {
                m1[ind].first = i;
                m1[ind].second = 1;
            }
            if (m1[ind].second > max) {
                max = m1[ind].second;
            }
            i++;
        }
        ind.clear();
    }
    resultFunction(m1, max, i);
    return 0;
}