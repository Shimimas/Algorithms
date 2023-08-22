#include <iostream>
#include <map>

int main() { // g++ -std=c++2a n1.cpp
    int n;
    std::map<std::string, std::string> words;
    std::map<std::string, std::string> words2;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::string word1, word2;
        std::cin >> word1 >> word2;
        words[word2] = word1;
        words2[word1] = word2;
    }
    std::string findWord;
    std::cin >> findWord;
    words.contains(findWord) ? std::cout << words[findWord] << std::endl : std::cout << words2[findWord] << std::endl;
    return 0;
}