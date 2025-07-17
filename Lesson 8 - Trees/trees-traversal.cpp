#include <iostream>
using namespace std;

// define the structure of a node in the binary tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    // constructor to initialize a new node
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// function to insert a new node into the binary tree
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return new TreeNode(value);
    }

    if (value < root->value) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// function to perform in-order traversal of the binary tree
void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

// function to perform pre-order traversal of the binary tree
void preOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        cout << root->value << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// function to perform post-order traversal of the binary tree
void postOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->value << " ";
    }
}

// main function to demonstrate the binary tree operations
int main() {
    TreeNode* root = nullptr;

    // insert nodes into the binary tree
    root = insertNode(root, 27);
    insertNode(root, 14);
    insertNode(root, 35);
    insertNode(root, 10);
    insertNode(root, 19);
    insertNode(root, 31);
    insertNode(root, 42);

    // perform in-order traversal
    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // perform pre-order traversal
    cout << "Pre-Order Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // perform post-order traversal
    cout << "Post-Order Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
