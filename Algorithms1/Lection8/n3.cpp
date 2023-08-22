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

long find_second_max(struct node * &root) {
    struct node * last_el = nullptr;
    while (root->right != nullptr) {
        last_el = root;
        root = root->right;
    }
    if (root->left != nullptr) {
        root = root->left;
        while (root->right != nullptr) {
            root = root->right;
        }
        return root->data;
    } else {
        return last_el->data;
    }
}

int main() {
    std::ifstream file("input.txt");
    struct node * root = nullptr;
    long c;
    for (file >> c; !file.eof() && c != 0; file >> c) {
        insert(root, c);
    }
    std::cout << find_second_max(root) << std::endl;
    return 0;
}