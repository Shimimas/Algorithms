#include <iostream>
#include <fstream>

struct node {
    long data;
    struct node * left = nullptr;
    struct node * right = nullptr;
};

long insert(struct node * &root, long data) {
    if (root == nullptr) {
        root = new struct node;
        root->data = data;
        return 1;
    } else if (data > root->data) {
        long res = insert(root->right, data);
        return res != -1 ? res + 1 : -1;
    } else if (data < root->data) {
        long res = insert(root->left, data);
        return res != -1 ? res + 1 : -1;
    }
    return -1;
}

int main() {
    std::ifstream file("input.txt");
    struct node * root = nullptr;
    long c;
    for (file >> c; !file.eof() && c != 0; file >> c) {
        long len = insert(root, c);
        if (len != -1) {
            std::cout << len << " ";
        }
    }
    return 0;
}