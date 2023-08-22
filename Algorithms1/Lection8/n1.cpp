#include <iostream>
#include <fstream>

struct node {
    int data;
    struct node * left = nullptr;
    struct node * right = nullptr;
};

int insert(struct node * &root, int data) {
    if (root == nullptr) {
        root = new struct node;
        root->data = data;
        return 1;
    } else if (data > root->data) {
        return insert(root->right, data) + 1;
    } else if (data < root->data) {
        return insert(root->left, data) + 1;
    }
    return -1;
}

int main() {
    std::ifstream file("input.txt");
    struct node * root = nullptr;
    int c, max;
    file >> c;
    max = insert(root, c);
    for (file >> c; !file.eof() && c != 0; file >> c) {
        int max_tmp = insert(root, c);
        if (max_tmp > max) {
            max = max_tmp;
        }
    }
    std::cout << max << std::endl;
    return 0;
}