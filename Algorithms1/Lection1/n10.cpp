#include <iostream>

void foo(double a, double b, double c, double d, double e, double f) {
    if (b == 0 && d == 0 && a == 0 && c == 0 && e == 0 && f == 0) {
        std::cout << "5" << std::endl;
    } else if (b != 0 && d != 0) {
        double k1 = -a/b, b1 = e/b, k2 = -c/d, b2 = f/d;
        if (k1 == 0 && k2 == 0) {
            if (b1 == b2) {
                std::cout << "4 " << b1 << std::endl;
            } else {
                std::cout << "0" << std::endl;
            }
        } else if (k1 == k2 && b1 == b2) {
            std::cout << "1 " << k1 << " " << b1 << std::endl;
        } else if (k1 == k2) {
            std::cout << "0" << std::endl;
        } else {
            if (k1 == 0 && k2 == 0) {
                if (b1 == b2) {
                    std::cout << "5" << std::endl;
                } else {
                    std::cout << "0" << std::endl;
                }
            } else {
                double y = ((-k2 * b1) / k1 + b2) / (1 - k2 / k1);
                double x = (y - b1) / k1;
                std::cout << "2 " << x << " " << y << std::endl;
            }
        }
    } else {
        if (b == 0 && d == 0) { // done 
            if (a != 0 && c != 0) {
                double x1 = e / a;
                double x2 = f / c;
                x1 == x2 ? std::cout << "3 " << x1 << std::endl : std::cout << "0" << std::endl;
            } else if (a == 0 && c == 0) {
                std::cout << "0" << std::endl;
            } else if (a == 0) {
                if (e == 0) {
                    std::cout << "3 " << f / c << std::endl;
                } else {
                    std::cout << "0" << std::endl;
                }
            } else {
                if (f == 0) {
                    std::cout << "3 " << e / a << std::endl;
                } else {
                    std::cout << "0" << std::endl;
                }
            }
        } else if (b == 0) {
            if (a != 0 && c != 0) {
                double x = e / a;
                double y = (f - c * x)/ d;
                std::cout << "2 " << x << " " << y << std::endl;
            } else if (a == 0 && c == 0) {
                if (e == 0) {
                    std::cout << "4 " << f / d << std::endl;
                } else {
                    std::cout << "0" << std::endl;
                }
            } else if (a == 0) {
                if (e == 0) {
                    std::cout << "1 " << - c / d << " " << f / d << std::endl;
                } else {
                    std::cout << "0" << std::endl;
                }
            } else {
                std::cout << "2 " << e / a << " " << f / d << std::endl;
            }
        } else {
            if (a != 0 && c != 0) {
                double x = f / c;
                double y = (e - a * x)/ b;
                std::cout << "1 " << x << " " << y << std::endl;
            } else if (a == 0 && c == 0) {
                if (f == 0) {
                    std::cout << "4 " << e / b << std::endl;
                } else {
                    std::cout << "0" << std::endl;
                }
            } else if (a == 0) {
                double x = f / c;
                double y = e / b;
                std::cout << "2 " << x << " " << y << std::endl;
            } else {
                if (f == 0) {
                    double x = -a / b;
                    double y = e / b;
                    std::cout << "1 " << x << " " << y << std::endl;
                } else {
                    std::cout << "0" << std::endl;
                }
            }
        }
    }
}

int main() {
    double a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    foo(a, b, c, d, e, f);
    return 0;
}