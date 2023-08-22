#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    int N, M;
    std::cin >> N >> M;
    std::vector<std::pair<int, std::pair<int, std::pair<int, int>>>> array(M * 2);
    for (int i = 0; i < M * 2; i += 2) {
        std::string t1, t2;
        int num1, num2;
        std::cin >> num1 >> t1 >> num2 >> t2;
    	num1 -= 1;
    	num2 -= 1;
        int time1, time2;
        time1 = ((t1[0] - '0') * 10 + (t1[1] - '0')) * 60 + ((t1[3] - '0') * 10 + (t1[4] - '0'));
        time2 = ((t2[0] - '0') * 10 + (t2[1] - '0')) * 60 + ((t2[3] - '0') * 10 + (t2[4] - '0'));
        array[i].first = time1;
        array[i].second.first = 1;
        array[i].second.second.first = num1;
        array[i].second.second.second = i;
        array[i + 1].first = time2;
        array[i + 1].second.first = -1;
        array[i + 1].second.second.first = num2;
        array[i + 1].second.second.second = i;
    }
    std::sort(array.begin(), array.end());
    std::set<int> numbers;
    int first_res, second_res;
    int result = 0;
    int * check = new int[N]();
    for (int k = 0; k < 3; k++) {
        for (int i = 0; i < M * 2; i++) {
            if (array[i].second.first == 1) {
                if (check[array[i].second.second.first] != 0) {
                    check[array[i].second.second.first] -= 1;
                } else {
                    result += 1;
                }
                numbers.insert(array[i].second.second.second);
            } else {
                if (numbers.count(array[i].second.second.second)) {
                    numbers.erase(array[i].second.second.second);
                    check[array[i].second.second.first] += 1;
                }
            }
        }
        if (k == 1) {
            first_res = result;
        } else if (k == 2) {
            second_res = result;
        }
    }
    if (first_res == second_res) {
        std::cout << result << std::endl;
    } else {
        std::cout << "-1" << std::endl;
    }
    return 0;
}