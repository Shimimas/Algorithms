#include <iostream>
#include <vector>
#include <algorithm>

struct con {
    long int number = 0;
    int idx = 0;
};

bool operator < (const con& dot1, const con& dot2)
{
    return dot1.number < dot2.number;
}

class Contest {
    private:
        unsigned int n_ = 0;
        unsigned int x_ = 0;
        long long int t_ = 0;
        long int * nArray_ = nullptr;
        unsigned int FindRow(unsigned int symbol);

        int right_ = -1;
        int left_ = -1;

        std::vector<struct con> res_vector_;
        std::vector<int> num_vector;

        std::vector<struct con> vector_;
        std::vector<struct con> dop_vector_;

        int FindNumber(unsigned int number);
        int Resulter();
        void FindVariants();
        void LeftRightFind();
    public:
        Contest() {};
        void Input();
        void Algorithm();
};

void Contest::Input() {
    std::cin >> n_ >> x_ >> t_;
    nArray_ = new long int[n_];
    for (int i = 0; i < n_; i++) {
        std::cin >> nArray_[i];
        vector_.push_back({nArray_[i], i});
        if (nArray_[i] == x_) {
            dop_vector_.push_back({nArray_[i], i});
        }
    }
}

void Contest::LeftRightFind() {
    for (int i = 0; i < n_; i++) {
        if (vector_[i].number < x_) {
            left_ = i;
        } else if (vector_[i].number > x_) {
            right_ = i;
            break;
        }
    }
}

void Contest::FindVariants() {
    while (t_ > 0 && res_vector_.size() < n_) {
        //std::cout << "left = " << left_ << " right = " << right_ << std::endl;
        if (right_ < n_ && left_ >= 0) {
            //std::cout << "1\n";
            if (abs(vector_[left_].number - x_) < abs(vector_[right_].number - x_)) {
                t_ -= abs(vector_[left_].number - x_);
                res_vector_.push_back(vector_[left_]);
                left_--;
            } else {
                t_ -= abs(vector_[right_].number - x_);
                res_vector_.push_back(vector_[right_]);
                right_++;
            }
        } else if (right_ < n_) {
            //std::cout << "2\n";
            t_ -= abs(vector_[right_].number - x_);
            res_vector_.push_back(vector_[right_]);
            right_++;
        } else if (left_ >= 0) {
            //std::cout << "3\n";
            t_ -= abs(vector_[left_].number - x_);
            res_vector_.push_back(vector_[left_]);
            left_--;
        } else {
            //std::cout << "4\n";
            t_ = 0;
        }
    }
    if (t_ < 0) {
        res_vector_.pop_back();
    }
    //std::cout << "size = " << res_vector_.size() << std::endl;
}

void Contest::Algorithm() {
    std::sort(vector_.begin(), vector_.end());
    LeftRightFind();
    FindVariants();
    Resulter();
    std::cout << res_vector_.size() << std::endl;
    for (int i = 0; i < res_vector_.size(); i++) {
        num_vector.push_back(res_vector_[i].idx);
    }
    std::sort(num_vector.begin(), num_vector.end());
    for (int i = 0; i < num_vector.size(); i++) {
        std::cout << (num_vector[i] + 1) << " ";
    }
    std::cout << std::endl;
}

int Contest::Resulter() {
    int result = 0;
    for (int i = 0; i < dop_vector_.size(); i++) {
            res_vector_.push_back(dop_vector_[i]);
    }
    //std::cout << "size = " << res_vector_.size() << std::endl;
    return res_vector_.size();
}

int Contest::FindNumber(unsigned int number) {
    int result = 0;
    for (int i = 0; i < n_; i++) {
        if (nArray_[i] == number) {
            result = (i + 1);
            nArray_[i] = -1;
            break;
        }
    }
    //std::cout << "result = " << result << std::endl;
    return result;
}

int main() {
    Contest contest;
    contest.Input();
    contest.Algorithm();
    return 0;
}