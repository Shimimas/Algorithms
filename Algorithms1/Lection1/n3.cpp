#include <iostream>

void Check(int ** number) {
    bool res = false;
    for (int i = 1; i < 4; i++) {
        bool res = false;
        for (int j = 0; j < 11; j++) {
            if (number[0][j] != number[i][j]) {
                res = true;
                std::cout << "NO" << std::endl;
                break;
            }
        }
        if (res == false) {
            std::cout << "YES" << std::endl;
        }
    }
}

int main() {
    std::string number;
    bool plus;
    int ** numbers = new int * [4];
    for (int i = 0; i < 4; i++) {
        numbers[i] = new int[11];
    }
    for (int i = 0; i < 4; i++) {
        std::getline(std::cin, number);
        int j = 10;
        int counter = 0;
        for (int m = (int)number.size() - 1; m >= 0; m--) {
            if (number[m] >= '0' && number[m] <= '9') {
                numbers[i][j--] = number[m] - '0';
                counter++;
            } else if (number[m] == '+') {
                numbers[i][++j] = 8;
            }
        }
        if (counter == 7) {
            numbers[i][0] = 8;
            numbers[i][1] = 4;
            numbers[i][2] = 9;
            numbers[i][3] = 5;
        }
    }
    Check(numbers);
    return 0;
}