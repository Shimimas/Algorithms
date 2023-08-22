#include <iostream>
#include <map>

class Contest {
    private:
        unsigned int n_ = 0;
        unsigned int k_ = 0;
        std::map<unsigned int, unsigned int> map_;
        unsigned int * nArray1_ = nullptr;
        unsigned int * nArray2_ = nullptr;
        unsigned int * kArray_ = nullptr;
        unsigned int FindRow(unsigned int symbol);
        void AddMap();

    public:
        Contest() {};
        void Input();
        void Algorithm();
};

void Contest::Input() {
    std::cin >> n_;
    nArray1_ = new unsigned int[n_];
    for (int i = 0; i < n_; i++) {
        std::cin >> nArray1_[i];
    }
    nArray2_ = new unsigned int[n_];
    for (int i = 0; i < n_; i++) {
        std::cin >> nArray2_[i];
    }
    std::cin >> k_;
    kArray_ = new unsigned int[k_];
    for (int i = 0; i < k_; i++) {
        std::cin >> kArray_[i];
    }
}

void Contest::AddMap() {
    for (int i = 0; i < n_; i++) {
        map_[nArray1_[i]] = nArray2_[i];
    }
}

int Search_Binary(unsigned int arr[], int left, int right, int key) {
    int midd = 0;
    while (1) {
        midd = (left + right) / 2;

        if (key < arr[midd])      
        right = midd - 1;     
        else if (key > arr[midd])  
        left = midd + 1;  
        else                
        return midd;         
    }
}

unsigned int Contest::FindRow(unsigned int symbol) {
    return Search_Binary(nArray1_, 0, n_, symbol);
}

void Contest::Algorithm() {
    AddMap();
    std::map <unsigned int, unsigned int>::iterator it;
    
    unsigned int result = 0;

    it = map_.find(kArray_[0]);
    unsigned int lastRow = it->second;
    for (int i = 0; i < k_; i++) {
        it = map_.find(kArray_[i]);
        unsigned int tempRow = it->second;
        if (lastRow != tempRow) {
            result++;
            lastRow = tempRow;
        }
    }
    std::cout << result << std::endl;
}

int main() {
    Contest contest;
    contest.Input();
    contest.Algorithm();
    return 0;
}