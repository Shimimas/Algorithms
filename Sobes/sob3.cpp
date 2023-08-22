#include <iostream>

class Sobes {
    private:
        int n_ = 0;
        int * array_ = nullptr;
    public:
        void Input();
};

void Sobes::Input() {
    std::cin >> n_;
    bool start = false;
    int number = 0;
    int number_tmp = 0;
    for (int i = 0; i < n_; i++) {
        std::cin >> number;
        if (start == false) {
            std::cout << number << std::endl;
            number_tmp = number;
            start = true;
        } else if (number_tmp != number) {
            std::cout << number << std::endl;
            number_tmp = number;
        }
    }
}

int main() {
    Sobes sobes;
    sobes.Input();
    return 0;
}