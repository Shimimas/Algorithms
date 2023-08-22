#include <iostream>
#include <fstream>
#include <map>

int main() {
    std::ifstream file("input.txt");
    std::map<std::string, int> words;
    std::string s;
    int max = 0;
    for (file >> s; !file.eof(); file >> s) {
        if (!words.contains(s)) {
            words[s] = 1;
        } else {
            words[s]++;
        }
        if (words[s] > max) {
            max = words[s];
        }
    }
    for (auto it = words.begin(); it != words.end(); it++) {
        if (it->second == max) {
            std::cout << it->first << std::endl;
            break;
        }
    }
}