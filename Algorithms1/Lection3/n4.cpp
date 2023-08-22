#include <iostream>
#include <set>
#include <fstream>

int main() {
    std::ifstream file("input.txt");
    std::set<std::string> words;
    int result = 0;
    std::string s;
    for (file >> s; !file.eof(); file >> s) {
        if (!words.count(s)) {
            words.insert(s);
            result++;
        }
    }
    std::cout << result << std::endl;
    return 0;
}