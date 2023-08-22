#include <iostream>

class Sobes {
    private:
        std::string J_, S_;
        int result_ = 0;

        bool Contains(char symbol);
    public:
        void Input();
        void Output();
        void Algorithm();
};

void Sobes::Input() {
    std::getline(std::cin, J_);
    std::getline(std::cin, S_);
}

bool Sobes::Contains(char symbol) {
    bool result = false;
    for (int i = 0; i < J_.size(); i++) {
        if (J_[i] == symbol) {
            result = true;
        }
    }
    return result;
}

void Sobes::Algorithm() {
    for (int i = 0; i < S_.size(); i++) {
        if (Contains(S_[i]) == true) {
            result_++;
        }
    }
}

void Sobes::Output() {
    std::cout << result_ << std::endl;
}

int main() {
    Sobes sobes;
    sobes.Input();
    sobes.Algorithm();
    sobes.Output();
    return 0;
}