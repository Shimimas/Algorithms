#include <iostream>
#include <set>

int main() {
    char c;
    std::set<std::string> gens;
    std::string result;
    std::string inputString;
    while (std::cin.peek() != '\n' && std::cin >> c) {
        inputString.push_back(c);
    }
    std::cin.get();
    while (std::cin.peek() != '\n' && std::cin >> c) {
        if (result.size() == 0) {
            result.push_back(c);
        } else if (result.size() == 1) {
            result.push_back(c);
            gens.insert(result);
        } else {
            result[0] = result[1];
            result[1] = c;
            gens.insert(result);
        }
    }
    result.clear();
    int counter = 0;
    for (int i = 0; i < inputString.size(); i++) {
        if (result.size() == 0) {
            result.push_back(inputString[i]);
        } else if (result.size() == 1) {
            result.push_back(inputString[i]);
            if (gens.count(result)) {
                counter++;
            }
        } else {
            result[0] = result[1];
            result[1] = inputString[i];
            if (gens.count(result)) {
                counter++;
            }
        }
    }
    std::cout << counter << std::endl;
    return 0;
}