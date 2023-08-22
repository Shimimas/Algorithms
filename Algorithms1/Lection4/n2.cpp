#include <iostream>
#include <map>
#include <fstream>

int main() {
    std::ifstream file("input.txt");
    std::string s;
    std::map<std::string, int> words;
    for (file >> s; !file.eof(); file >> s) {
        if (!words.contains(s)) {
            words[s] = 0;
        } else {
            words[s]++;
        }
        std::cout << words[s] << " ";
    }
    std::cout << std::endl;
    return 0;
}