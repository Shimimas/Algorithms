#include <iostream>

class Sobes {
    private:
        int n_ = 0;
        std::string S1_, S2_;

        bool err = false;

        bool Check1();

    public:
        void Check();
        void Input();
        void Algorithm();
};

void Sobes::Input() {
    std::getline(std::cin, S1_);
    std::getline(std::cin, S2_);
}

void Sobes::Check() {
    if (S1_.size() == 0 || S2_.size() == 0) {
        err = true;
        std::cout << 0 << std::endl;
    }
}

void Sobes::Algorithm() {
    if (err != true) {
        bool res = false;
        for (int i = 0; i < S1_.size(); i++) {
            auto ind = S2_.find(S1_[i]);
            if (ind == std::string::npos) {
                res = true;
                break;
            } else {
                S2_[ind] = '!';
                S1_[i] = '!';
            }
        }
        if (res == true || Check1() == false) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << 1 << std::endl;
        }
    }
}

bool Sobes::Check1() {
    bool result = true;
    for (int i = 0; i < S2_.size(); i++) {
        if (S2_[i] != '!') {
            result = false;
        }
    }
    return result;
}

int main() {
    Sobes sobes;
    sobes.Input();
    sobes.Check();
    sobes.Algorithm();
    return 0;
}