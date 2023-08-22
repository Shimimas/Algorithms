#include <iostream>

class Sobes {
    private:
        int n_ = 0;
        std::string result_;

        void Algorithm(std::string string, int l, int r, int col);
    public:
        void Input();
};

void Sobes::Input() {
    std::cin >> n_;
    Algorithm(result_, 0, 0, n_);
}

void Sobes::Algorithm(std::string string, int l, int r, int col) {
    if (l == col && r == col) {
        std::cout << string << std::endl;
    } else {
        if (l < col) {
            Algorithm(string + '(', l + 1, r, col);
        }
        if (r < l) {
            Algorithm(string + ')', l, r + 1, col);
        }
    }
}

int main() {
    Sobes sobes;
    sobes.Input();
    return 0;
}