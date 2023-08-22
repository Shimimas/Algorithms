#include <iostream>
#include <fstream>

struct node {
    long data;
    struct node * left = nullptr;
    struct node * right = nullptr;
};

void insert(struct node * &root, long data) {
    if (root == nullptr) {
        root = new struct node;
        root->data = data;
    } else if (data > root->data) {
        insert(root->right, data);
    } else if (data < root->data) {
        insert(root->left, data);
    }
}

void print_tree(struct node * &root) {
    if (root != nullptr) {
        print_tree(root->left);
        if (root->left != nullptr && root->right != nullptr) {
            std::cout << root->data << std::endl;
        }
        print_tree(root->right);
    }
}

int main() {
    std::ifstream file("input.txt");
    struct node * root = nullptr;
    long c;
    for (file >> c; !file.eof() && c != 0; file >> c) {
        insert(root, c);
    }
    print_tree(root);
    return 0;
}