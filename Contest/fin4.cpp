#include <iostream>

class Contest {
    private:
        int n_ = 0;
        int k_ = 0;
        int * inputArray_ = nullptr;
        int * workArray_ = nullptr;

        void Copy();
    public:
        Contest() {};
        void Input();
        void Algorithm();
};

void Contest::Input() {
    std::cin >> n_;
    std::cin >> k_;
    inputArray_ = new int[n_];
    for (int i = 0; i < n_; i++) {
        std::cin >> inputArray_[i];
    }   
}

int main() {
    Contest contest;
    contest.Input();
    contest.Algorithm();
    return 0;
}