#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>

struct studient {
    int place;
    long x;
    int type;
};

struct variant {
    int place;
    int variant;
};

bool operator<(const struct studient &s1, const struct studient &s2) {
    if (s1.x < s2.x) {
        return true;
    } else if (s1.x > s2.x) {
        return false;
    } else {
        if (s1.type < s2.type) {
            return true;
        } else if (s1.type > s2.type) {
            return false;
        }
    }
    return true;
}

bool operator<(const struct variant &s1, const struct variant &s2) {
    if (s1.place < s2.place) {
        return true;
    } else if (s1.place > s2.place) {
        return false;
    }
    return true;
}

int main() {
    std::ifstream file("input.txt");
    int N;
    long D;
    file >> N >> D;
    std::vector<struct studient> array(N * 2);
    std::vector<struct variant> array2(N);
    for (int i = 0; i < 2 * N; i += 2) {
        file >> array[i].x;
        array[i].place = i;
        array[i].type = -1;
        array[i + 1].x = array[i].x + D;
        array[i + 1].place = i + 1;
        array[i + 1].type = 1;
    }
    std::sort(array.begin(), array.end());
    long counter = 0, max = 1;
    std::set<long> var;
    for (int i = 0; i < N * 2; i++) {
        if (array[i].type == -1) {
            counter += 1;
            if (counter > max) {
                max = counter;
            }
        } else {
            counter -= 1;
        }
    }
    int variants = 1;
    for (int i = 0, j = 0; i < 2 * N; i++) {
        if (array[i].type == -1) {
            array2[j].place = array[i].place;
            array2[j].variant = variants;
            variants == max ? variants = 1 : variants += 1;
            j++;
        }
    }
    std::sort(array2.begin(), array2.end());
    std::cout << max << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout <<  array2[i].variant << " ";
    }
    return 0;
}