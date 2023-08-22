#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>

struct event {
    long x, type, i;
};

bool operator<(const struct event &s1, const struct event &s2) {
    if (s1.x < s2.x) {
        return true;
    } else if (s1.x > s2.x) {
        return false;
    } else {
        if (s1.type < s2.type) {
            return true;
        } else if (s1.type > s2.type) {
            return false;
        } else {
            if (s1.i < s2.i) {
                return true;
            } else if (s1.i > s2.i) {
                return false;
            } else {
                return true;
            }
        }
    }
    return true;
}

int main() {
    long N;
    std::ifstream file("input.txt");
    file >> N;
    std::vector<struct event> array;
    for (long i = 0; i < N; i++) {
        long x1, x2;
        file >> x1 >> x2;
        if (x2 - x1 >= 5) {
            array.push_back({x1, -1, i});
            array.push_back({x2 - 5, 1, i});
        }
    }
    std::sort(array.begin(), array.end());
    if (array.size() == 0) {
        std::cout << "0 10 20" << std::endl; 
    } else if (array.size() == 2) {
        std::cout << "1 " << array[0].x << " " << array[0].x + 10 << std::endl;
    } else {
        long bestans = 0;
        long first = 0, second = 0;
        std::set<long> first_set;
        for (long i = 0; i < (long)array.size(); i++) {
            struct event ev1 = array[i];
            if (ev1.type == -1) {
                if (!first_set.count(ev1.i)) {
                    first_set.insert(ev1.i);
                }
                if ((long)first_set.size() > bestans) {
                    bestans = (long)first_set.size();
                    first = ev1.x;
                    second = ev1.x + 5;
                }
            }
            long secondcount = 0;
            for (long j = i + 1; j < (long)array.size(); j++) {
                struct event ev2 = array[j];
                if (ev2.type == -1 && !first_set.count(ev2.i)) {
                    secondcount += 1;
                }
                if (ev2.x - 5 >= ev1.x && (long)first_set.size() + secondcount > bestans) {
                    bestans = (long)first_set.size() + secondcount;
                    first = ev1.x;
                    second = ev2.x;
                }
                if (ev2.type == 1 && !first_set.count(ev2.i)) {
                    secondcount -= 1;
                }
            }
            if (ev1.type == 1) {
                if (first_set.count(ev1.i)) {
                    first_set.erase(ev1.i);
                }
            }
        }
        std::cout << bestans << " " << first << " " << second << std::endl;
    }
    return 0;
}