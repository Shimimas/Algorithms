#include <iostream>


#include <vector>

struct adress {
    int f = 0;
    int p = 0;
};

std::vector<int> floor(int k2, int n) {
    std::vector<int> floor;
    int j = 1;
    for (int i = k2; k2 >= j;j++, k2--) {
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

std::pair<int, int> result_fin(std::vector<int> floor, int k1, int m) {
    std::pair<int, int> result;
    if (floor.size() == 1) {
        struct adress adres = calkAdress(floor[0], k1, m);
        result.first = adres.p;
        result.second = adres.f;
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
        result.first = adres.p;
        result.second = adres.f;
    }
    return result;
}

std::pair<int, int> foo1(int k1, int m, int k2, int p2, int n2) {
    std::pair<int, int> result;
    if (m < n2) {
        result.first = -1;
        result.second = -1;
    } else if (n2 == 1 && p2 == 1) {
        if (k1 <= k2) {
            result.first = p2;
            result.second = n2;
        } else {
            if (k1 <= m) {
                result.first = 1;
            } else {
                result.first = 0;
            }
            if (m == 1) {
                result.second = 1;
            } else {
                result.second = 0;
            }
        }
    } else {
        int j = 1;
        int n = ((p2 - 1) * m) + (n2 - 1);
        std::vector<int> flor = floor(k2 - 1, n);
        if (flor.size() == 0) {
            result.first = -1;
            result.second = -1;
        } else {
            result = result_fin(flor, k1, m);
        }
    }
    return result;
}




std::pair<int, int> get_p_n(int k, int m, int apparts_floor) {
    int p = (k - 1) / (apparts_floor * m) + 1;
    int n = (k - (p - 1) * apparts_floor * m - 1) / apparts_floor + 1;
    return {p, n};
}

std::pair<int, int> foo(int k1, int m, int k2, int p2, int n2) {
    std::pair<int, int> result;
    int offset = (p2 - 1) * m + (n2 - 1);
    int apparts_floor_max = (k2 - 1) / offset;
    if (apparts_floor_max == 0 || (k2 - 1) / apparts_floor_max != offset) {
        result.first = -1;
        result.second = -1;
    } else {
        int apparts_floor_min = (k2 - 1) / (offset + 1) + 1;
        if ((k2 - 1) / apparts_floor_min != offset) {
            apparts_floor_max = apparts_floor_min;
        }
        std::pair<int, int> result_1 = get_p_n(k1, m, apparts_floor_min);
        std::pair<int, int> result_2 = get_p_n(k1, m, apparts_floor_max);
        if (result_1.first != result_2.first) {
            result.first = 0;
        } else {
            result.first = result_1.first;
        }
        if (m == 1) {
            result.second = 1;
        } else {
            if (result_1.second != result_2.second) {
                result.second = 0;
            } else {
                result.second = result_1.second;
            }
        }
    }
    return result;
}

int main() {
    int result_1_p, result_2_p, result_1_n, result_2_n;
    for (int k1 = 1; k1 < 100; k1++) {
        for (int m = 1; m < 100; m++) {
            for (int k2 = 1; k2 < 100; k2++) {
                for (int p2 = 1; p2 < 100; p2++) {
                    for (int n2 = 1; n2 < 100; n2++) {
                        if (n2 > m) {
                            result_1_p = -1;
                            result_1_n = -1;
                        } else if (n2 == 1 && p2 == 1) {
                            if (k1 > k2) {
                                if (k1 <= m) {
                                    result_1_p = 1;
                                } else {
                                    result_1_p = 0;
                                }
                                if (m == 1) {
                                    result_1_n = 1;
                                } else {
                                    result_1_n = 0;
                                }
                            } else {
                                result_1_p = p2;
                                result_1_n = n2;
                            }
                        } else {
                            std::pair<int, int> result = foo(k1, m, k2, p2, n2);
                            result_1_p = result.first;
                            result_1_n = result.second;
                        }

                        std::pair<int, int> result2 = foo1(k1, m, k2, p2, n2);
                        result_2_p = result2.first;
                        result_2_n = result2.second;
                        if (result_1_p == result_2_p && result_1_n == result_2_n) {
                            ;
                        } else {
                            std::cout << "k1 = " << k1 << " m = " << m << " k2 = " << k2 << " p2 = " << p2 << " n2 = " << n2 << std::endl;
                            std::cout << "1) (right) " << result_1_p << " " << result_1_n << std::endl;
                            std::cout << "2) (false) " << result_2_p << " " << result_2_n << std::endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}