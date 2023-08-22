#include <iostream>

struct ticket {
    int num = 0;
    bool LOrR = false;
    bool WOrA = false;
};

class Plane {
    private:
        int n_ = 0;
        int m_ = 0;
        std::string * seats_ = nullptr;
        std::string * passengers_ = nullptr;
        int result_ = 0;
        struct ticket * tickets_ = nullptr;
        bool ColCheck(int row, int posision, int col);
        bool SeatCheck(int number, int col);
        void Clean();
        void Parther();
    public:
        Plane() {};
        void InputSeats();
        void InputPassengers();
        void Algorithm();
        void Output();
        void Check();
};

void Plane::Algorithm() {
    Parther();
    Check();
}

bool Plane::ColCheck(int row, int posision, int col) {
    bool result = false;
    if (col == 1) {
        result = true;
        seats_[row][posision] = 'X';
        if (posision == 2) {
            std::cout << "Passengers can take seats: " << (row + 1) << "C" << std::endl;
        } else if (posision == 0) {
            std::cout << "Passengers can take seats: " << (row + 1) << "A" << std::endl;
        } else if (posision == 4) {
            std::cout << "Passengers can take seats: " << (row + 1) << "D" << std::endl;
        } else if (posision == 6) {
            std::cout << "Passengers can take seats: " << (row + 1) << "F" << std::endl;
        }
    } else if (col == 2) {
        if ((posision == 2 || posision == 0) && seats_[row][1] == '.') {
            result = true;
            seats_[row][posision] = 'X';
            seats_[row][1] = 'X';
            if (posision == 2) {
                std::cout << "Passengers can take seats: " << (row + 1) << "B " << (row + 1) << "C" << std::endl;
            } else {
                std::cout << "Passengers can take seats: " << (row + 1) << "A " << (row + 1) << "B" << std::endl;
            }
        } else if ((posision == 4 || posision == 6) && seats_[row][5] == '.') {
            result = true;
            seats_[row][posision] = 'X';
            seats_[row][5] = 'X';
            if (posision == 4) {
                std::cout << "Passengers can take seats: " << (row + 1) << "D " << (row + 1) << "E" << std::endl;
            } else {
                std::cout << "Passengers can take seats: " << (row + 1) << "E " << (row + 1) << "F" << std::endl;
            }
        }
    } else if (col == 3) {
        if ((posision == 2 || posision == 0) && seats_[row][1] == '.' && seats_[row][0] == '.' && seats_[row][2] == '.') {
            result = true;
            seats_[row][0] = 'X';
            seats_[row][1] = 'X';
            seats_[row][2] = 'X';
            std::cout << "Passengers can take seats: " << (row + 1) << "A " << (row + 1) << "B " << (row + 1) << "C" << std::endl;
        } else if ((posision == 4 || posision == 6) && seats_[row][4] == '.' && seats_[row][5] == '.' && seats_[row][6] == '.') {
            result = true;
            seats_[row][4] = 'X';
            seats_[row][5] = 'X';
            seats_[row][6] = 'X';
            std::cout << "Passengers can take seats: " << (row + 1) << "D " << (row + 1) << "E " << (row + 1) << "F" << std::endl;
        }
    }
    return result;
}

bool Plane::SeatCheck(int number, int col) {
    bool result = false;
    for (int m = 0; m < n_; m++) {
        if (seats_[m][number] == '.') {
            if (ColCheck(m, number, col)) {
                result = true;
                break;
            }
        }
    }
    return result;
}

void Plane::Check() {
    for (int i = 0; i < m_; i++) {
        if (tickets_[i].LOrR == false && tickets_[i].WOrA == false && SeatCheck(2, tickets_[i].num)) {
            //std::cout << "Passengers can take seats: 1B 1C\n";
            Output();
            Clean();
        } else if (tickets_[i].LOrR == false && tickets_[i].WOrA == true && SeatCheck(0, tickets_[i].num)) {
            //std::cout << "HAVE PLASE FOR " << (i + 1) << "TICKET\n";
            Output();
            Clean();
        } else if (tickets_[i].LOrR == true && tickets_[i].WOrA == false && SeatCheck(4, tickets_[i].num)) {
            //std::cout << "HAVE PLASE FOR " << (i + 1) << "TICKET\n";
            Output();
            Clean();
        } else if (tickets_[i].LOrR == true && tickets_[i].WOrA == true && SeatCheck(6, tickets_[i].num)) {
            //std::cout << "HAVE PLASE FOR " << (i + 1) << "TICKET\n";
            Output();
            Clean();
        } else {
            std::cout << "Cannot fulfill passengers requirements" << std::endl;
        }
    }
}

void Plane::Clean() {
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < seats_[i].size(); j++) {
            if (seats_[i][j] == 'X') {
                seats_[i][j] = '#';
            }
        }
    }
}

void Plane::Parther() {
    tickets_ = new ticket[m_];
    bool ind = false;
    for (int i = 0; i < m_; i++) {
        for (int j = 0; j < (int)passengers_[i].size(); j++) {
            if (passengers_[i][j] >= '0' && passengers_[i][j] <= '9') {
                tickets_[i].num = passengers_[i][j] - '0';
            } else if (ind == false && passengers_[i][j] == 'l') {
                tickets_[i].LOrR = false;
                ind = true;
            } else if (ind == false && passengers_[i][j] == 'r') {
                tickets_[i].LOrR = true;
                ind = true;
            } else if (ind == false && passengers_[i][j] == 'a') {
                tickets_[i].WOrA = false;
                ind = true;
            } else if (ind == false && passengers_[i][j] == 'w') {
                tickets_[i].WOrA = true;
                ind = true;
            } else if (passengers_[i][j] == ' ') {
                ind = false;
            }
        }
    }
}

void Plane::InputSeats() {
    std::cin >> n_;
    seats_ = new std::string [n_];
    getline(std::cin, seats_[0]);
    for (int i = 0; i < n_; i++) {
        getline(std::cin, seats_[i]);
    }
}

void Plane::InputPassengers() {
    std::cin >> m_;
    passengers_ = new std::string [m_];
    getline(std::cin, passengers_[0]);
    for (int i = 0; i < m_; i++) {
        getline(std::cin, passengers_[i]);
    }
}

void Plane::Output() {
    for (int i = 0; i < n_; i++) {
        std::cout << seats_[i] << std::endl;
    }
}

int main() {
    Plane plane;
    plane.InputSeats();
    plane.InputPassengers();
    plane.Algorithm();
    return 0;
}