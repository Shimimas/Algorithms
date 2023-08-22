#include <iostream>
#include <map>
#include <fstream>

int main() {
    std::ifstream file("input.txt");
    std::string command;
    std::map<std::string, long> bank;
    for (file >> command; !file.eof(); file >> command) {
        if (command == "BALANCE") {
            std::string name;
            file >> name;
            !bank.contains(name) ? std::cout << "ERROR" << std::endl : std::cout << bank[name] << std::endl;
        } else if (command == "TRANSFER") {
            std::string name, name1;
            file >> name >> name1;
            long balance;
            file >> balance;
            if (balance >= 0) {
                if (!bank.contains(name)) {
                    bank[name] = 0 - balance;
                } else {
                    bank[name] -= balance;
                }
                if (!bank.contains(name1)) {
                    bank[name1] = balance;
                } else {
                    bank[name1] += balance;
                }
            }
        } else if (command == "INCOME") {
            double p;
            file >> p;
            for (auto it = bank.begin(); it != bank.end(); it++) {
                if (it->second > 0) {
                    it->second += (long)((it->second / 100) * p);
                }
            }
        } else if (command == "DEPOSIT") {
            std::string name;
            long balance;
            file >> name >> balance;
            if (balance >= 0) {
                !bank.contains(name) ? bank[name] = balance : bank[name] += balance;
            }
        } else if (command == "WITHDRAW") {
            std::string name;
            long balance;
            file >> name >> balance;
            if (balance >= 0) {
                !bank.contains(name) ? bank[name] = 0 - balance : bank[name] -= balance;
            }
        }
    }
    return 0;
}