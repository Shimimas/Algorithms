#include <iostream>

class Factory {
    private:
        int n_ = 0;
        int * inputArray_ = nullptr;
        int maximum_ = 0;
        int result_ = 0;
    public:
        Factory() {};
        void Input();
        void Check();
};

void Factory::Input() {
    std::cin >> n_;
    if (n_ < 1 || n_ > 100000) {
        throw;
    }
    inputArray_ = new int[n_];
    for (int i = 0; i < n_; i++) {
        std::cin >> inputArray_[i];
        if (n_ < 1 || n_ > 1000000000) {
            throw;
        }
    }
}

void Factory::Check() {
    maximum_ = inputArray_[0];
    for (int i = 1; i < n_; i++) {
        if (inputArray_[i] < maximum_) {
            result_ = -1;
            break;
        }
        if (inputArray_[i] != maximum_) {
            maximum_ = inputArray_[i];
        }
    }
    if (result_ != -1) {
        result_ = inputArray_[n_ - 1] - inputArray_[0];
    }
    std::cout << result_ << std::endl;
}

int main() {
    Factory factory;
    factory.Input();
    factory.Check();
    return 0;
}