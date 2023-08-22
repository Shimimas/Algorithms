#include <iostream>
#include <fstream>

struct node {
    long data;
    struct node * left = nullptr;
    struct node * right = nullptr;
};

void insert(struct node * &root, struct node *&data) {
    if (root == nullptr) {
        root = new struct node;
        root->data = data;
    } else if (data > root->data) {
        insert(root->right, data);
    } else if (data < root->data) {
        insert(root->left, data);
    }
}

long checkAVL(struct node * &root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    long left_high = checkAVL(root->left) + 1;
    long right_high = checkAVL(root->right) + 1;
    if (left_high == 0 || right_high == 0) {
        return -1;
    } else {
        return abs(left_high - right_high) > 1 ? -1 : std::max(left_high, right_high);
    }
}

int main() {
    std::ifstream file("input.txt");
    struct node * root = nullptr;
    long c;
    for (file >> c; !file.eof() && c != 0; file >> c) {
        insert(root, c);
    }
    if (root != nullptr) {
        checkAVL(root) == -1 ? std::cout << "NO" << std::endl : std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}