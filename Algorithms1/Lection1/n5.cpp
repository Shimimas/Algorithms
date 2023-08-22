#include <iostream>
#include <vector>

struct adress {
    int f = 0;
    int p = 0;
};

std::vector<int> floor(int k2, int n) {
    std::vector<int> floor;
    int j = 1;
    for (int i = k2; k2 >= j; j++, k2--) {
        if (k2 % n == 0 && k2 / n >= j) {
            floor.push_back(k2 / n);\
        }
    }
    return floor;
}

struct adress calkAdress(int floor, int k1, int m) {
    struct adress adres;
    int floor_number = ((k1 - 1) / floor);
    if (floor_number >= m) {
        adres.f = (floor_number % m) + 1;
        adres.p = (floor_number / m) + 1;
    } else {
        adres.f = floor_number + 1;
    }
    adres.p = (floor_number / m) + 1;
    return adres;
}

void result(std::vector<int> floor, int k1, int m) {
    if (floor.size() == 1) {
        struct adress adres = calkAdress(floor[0], k1, m);
        std::cout << adres.p << " " << adres.f << std::endl;
    } else {
        struct adress adres = calkAdress(floor[0], k1, m);
        for (int i = 1; i < floor.size(); i++) {
            struct adress adres_tmp = calkAdress(floor[i], k1, m);
            if (adres_tmp.f != adres.f) {
                adres.f = 0;
            }
            if (adres_tmp.p != adres.p) {
                adres.p = 0;
            }
        }
        std::cout << adres.p << " " << adres.f << std::endl;
    }
}

void foo(int k1, int m, int k2, int p2, int n2) {
    if (m < n2) {
        std::cout << "-1 -1" << std::endl;
    } else if (n2 == 1 && p2 == 1) {
        if (k1 <= k2) {
            std::cout << p2 << " " << n2 << std::endl;
        } else {
            if (k1 <= m) {
                std::cout << 1 << " ";
            } else {
                std::cout << 0 << " ";
            }
            if (m == 1) {
                std::cout << 1 << std::endl;
            } else {
                std::cout << 0 << std::endl;
            }
        }
    } else {
        int j = 1;
        int n = ((p2 - 1) * m) + (n2 - 1);
        std::vector<int> flor = floor(k2 - 1, n);
        if (flor.size() == 0) {
            std::cout << "-1 -1" << std::endl;
        } else {
            result(flor, k1, m);
        }
    }
}

int main() {
    int k1, m, k2, p2, n2;
    std::cin >> k1 >> m >> k2 >> p2 >> n2;
    foo(k1, m, k2, p2, n2); 
    return 0;
}