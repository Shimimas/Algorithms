#include <iostream>
#include <map>
#include <fstream>

int main () {
    std::ifstream file("input.txt");
    std::string name, item;
    long amount;
    std::map<std::string, std::map<std::string, long>> check;
    for (file >> name >> item >> amount; !file.eof(); file >> name >> item >> amount) {
        check[name].contains(item) ? check[name][item] += amount : check[name][item] = amount;
    }
    for (auto it = check.begin(); it != check.end(); it++) {
        std::cout << it->first << ":" << std::endl;
        for (auto it1 = it->second.begin(); it1 != it->second.end(); it1++) {
            std::cout << it1->first << " " << it1->second << std::endl;
        }
    }
    return 0;
}