#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

    Node* insert(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        } else if (value > root->data) {
            root->right = insert(root->right, value);
        }

        return root;
    }

    Node* search(Node* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        }

        if (value < root->data) {
            return search(root->left, value);
        } else {
            return search(root->right, value);
        }
    }

    void inOrderTraversal(Node* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            std::cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        return search(root, value) != nullptr;
    }

    void printInOrder() {
        std::cout << "In-order traversal: ";
        inOrderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert some values
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Print in-order traversal
    bst.printInOrder();

    // Search for values
    std::cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not found") << std::endl;
    std::cout << "Search for 90: " << (bst.search(90) ? "Found" : "Not found") << std::endl;

    return 0;
}
