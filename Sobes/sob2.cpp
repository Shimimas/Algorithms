#include <iostream>

class Sobes {
    private:
        int n_ = 0;
        bool * array_ = nullptr;
    public:
        void Input();
        void Algorithm();
        void Output();
};

void Sobes::Input() {
    std::cin >> n_;
    array_ = new bool[n_];
    for (int i = 0; i < n_; i++) {
        std::cin >> array_[i];
    }
}

void Sobes::Algorithm() {
    int tmp_max = 0;
    int max = 0;
    for (int i = 0; i < n_; i++) {
        if (array_[i] == true) {
            tmp_max++;
        } else {
            if (tmp_max > max) {
                max = tmp_max;
            }
            tmp_max = 0;
        }
    }
    if (tmp_max > max) {
        max = tmp_max;
    }
    std::cout << max << std::endl;
}

int main() {
    Sobes sobes;
    sobes.Input();
    sobes.Algorithm();
    return 0;
}