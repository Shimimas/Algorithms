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
  
void heapify(int list[], int listLength, int root)
{
	int largest = root;
	int l = 2*root + 1;
	int r = 2*root + 2;
	  
	if (l < listLength && list[l] > list[largest])
		largest = l;
	  
	if (r < listLength && list[r] > list[largest])
		largest = r;

	if (largest != root)
	{
		std::swap(list[root], list[largest]);
		heapify(list, listLength, largest);
	}
}
  
void heapSort(int list[], int listLength)
{
	for(int i = listLength / 2 - 1; i >= 0; i--)
		heapify(list, listLength, i);
	 
	for(int i = listLength - 1; i >= 0; i--)
	{
		std::swap(list[0], list[i]);
		heapify(list, i, 0);
	}
}
  
/*int main()
{
	int list[5] = {3,19,8,0,48};
	cout<<"Input array ..."<<endl;
	for(int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
	
	heapSort(list, 5);
	
	cout << "Sorted array"<<endl;
	for(int i = 0; i < 5; i++)
		cout << list[i] << '\t';
	cout << endl;
}*/

void Contest::Copy() {
    for (int i = 0; i < n_; i++) {
        workArray_[i] = inputArray_[i];
    }
}

void Contest::Algorithm() {
    Copy();
    heapSort(workArray_, n_);
    for (int i = 0; i < n_; i++) {
        
    }
}

int main() {
    Contest contest;
    contest.Input();
    contest.Algorithm();
    return 0;
}