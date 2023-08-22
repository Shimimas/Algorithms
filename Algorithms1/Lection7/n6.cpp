#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

struct date {
    int d, m, y;
};

bool operator<(const struct date &s1, const struct date &s2) {
    if (s1.y < s2.y) {
        return true;
    } else if (s1.y > s2.y) {
        return false;
    } else if (s1.m < s2.m) {
        return true;
    } else if (s1.m > s2.m) {
        return false;
    } else if (s1.d < s2.d) {
        return true;
    } else if (s1.d > s2.d) {
        return false;
    } else {
        return false;
    }
    return false;
}

bool checkMore18(struct date &s1, struct date &s2) {
    if (s2.y - s1.y > 18) {
        return true;
    } else if (s2.y - s1.y < 18) {
        return false;
    } else if (s2.m > s1.m) {
        return true;
    } else if (s2.m < s1.m) {
        return false;
    } else if (s2.d > s1.d) {
        return true;
    } else if (s2.d < s1.d) {
        return false;
    } else {
        return true;
    }
    return true;
}

bool checkLess80(const struct date &s1, const struct date &s2) {
    if (s2.y - s1.y < 80) {
        return true;
    } else if (s2.y - s1.y > 80) {
        return false;
    } else if (s2.m < s1.m) {
        return true;
    } else if (s2.m > s1.m) {
        return false;
    } else if (s2.d < s1.d) {
        return true;
    } else if (s2.d > s1.d) {
        return false;
    } else {
        return false;
    }
    return false;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<struct date, std::pair<int, int>>> dates;
    for (int i = 0; i < N; i++) {
        int d1, m1, y1, d2, m2, y2;
        std::cin >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;
        struct date s1({d1, m1, y1}), s2({d2, m2, y2});
        if (checkMore18(s1, s2)) {
            if (!checkLess80(s1, s2)) {
                s2.y = s1.y + 80;
                s2.m = s1.m;
                s2.d = s1.d;
            }
            s1.y += 18;
            dates.push_back({s1, {1, i + 1}});
            dates.push_back({s2, {-1, i + 1}});
        }
    }
    if (dates.size() != 0) {
        std::sort(dates.begin(), dates.end());
        std::set<std::set<int>> sovr;
        std::set<int> tmp;
        bool ind = true;
        for (int i = 0; i < dates.size(); i++) {
            if (dates[i].second.first == 1) {
                tmp.insert(dates[i].second.second);
                ind = true;
            } else {
                if (ind != false) {
                    sovr.insert(tmp);
                    ind = false;
                }
                tmp.erase(dates[i].second.second);
            }
        }
        for (auto it : sovr) {
            for (int c : it) {
                std::cout << c << " ";
            }
            std::cout << std::endl;  
        }
    } else {
        std::cout << "0" << std::endl;
    }
    return 0;
}