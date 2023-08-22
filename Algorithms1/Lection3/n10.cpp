#include <iostream>
#include <vector>

struct coordinats {
    double negKmin, negKmax, posKmin, posKmax;
};

struct coordinats createSet(int x, int y, int d) {
    struct coordinats result;
    result.negKmin = (x - d) + y;
    result.negKmax = (x + d) + y;
    result.posKmin = x - (y - d);
    result.posKmax = x - (y + d);
    return result;
}

struct coordinats createZone(struct coordinats coords, int d) {
    struct coordinats result;
    result.negKmin = coords.negKmin - d;
    result.negKmax = coords.negKmax + d;
    result.posKmin = coords.posKmin + d;
    result.posKmax = coords.posKmax - d;
    return result;
}

struct coordinats createCross(struct coordinats firsdD, struct coordinats secondD) {
    struct coordinats result;
    result.posKmin = std::min(firsdD.posKmin, secondD.posKmin);
    result.negKmin = std::max(firsdD.negKmin, secondD.negKmin);
    result.posKmax = std::max(firsdD.posKmax, secondD.posKmax);
    result.negKmax = std::min(firsdD.negKmax, secondD.negKmax);
    return result;
}

void printResult(struct coordinats cross) {
    double south_x = (double)(cross.posKmin + cross.negKmin) / 2.0;
    double south_y = (double)cross.negKmin - south_x;
    double north_x = (double)(cross.posKmax + cross.negKmax) / 2.0;
    double north_y = (double)cross.negKmax - north_x;
    double west_x = (double)(cross.negKmin + cross.posKmax) / 2.0;
    double west_y = (double)cross.negKmin - west_x;
    double east_x = (double)(cross.posKmin + cross.negKmax) / 2.0;
    double east_y = (double)cross.negKmax - east_x;
    std::vector<int> result;
    for (double i = west_x; i <= east_x; i += 0.5) {
        for (double j = south_y; j <= north_y; j += 0.5) {
            if ((int)i == i && (int)j == j && i - j >= cross.posKmax && i + j <= cross.negKmax && i + j >= cross.negKmin && i - j <= cross.posKmin) {
                result.push_back(i);
                result.push_back(j);
            }
        }
    }
    std::cout << result.size() / 2 << std::endl;
    for (int i = 0; i < result.size(); i += 2) {
        std::cout << result[i] << " " << result[i + 1] << std::endl;
    }
}

int main() {
    int t, d, n;
    struct coordinats firstD, secondD, cross;
    std::cin >> t >> d >> n;
    firstD = createSet(0, 0, t);
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        secondD = createSet(x, y, d);
        cross = createCross(firstD, secondD);
        firstD = createZone(cross, t);
    }
    printResult(cross);
    return 0;
}