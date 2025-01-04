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

// function to find the minimum value node in the tree
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// function to delete a node from the binary tree
TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) return root;

    if (value < root->value) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->value) {
        root->right = deleteNode(root->right, value);
    } else {
        // node with only one child or no child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor (smallest in the right subtree)
        TreeNode* temp = findMin(root->right);

        // copy the inorder successor's content to this node
        root->value = temp->value;

        // delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }

    return root;
}

// function to search for a value in the binary tree
bool searchNode(TreeNode* root, int value) {
    if (root == nullptr) return false;

    if (root->value == value) return true;

    if (value < root->value) {
        return searchNode(root->left, value);
    } else {
        return searchNode(root->right, value);
    }
}

// function to perform in-order traversal of the binary tree
void inOrderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->value << " ";
        inOrderTraversal(root->right);
    }
}

// main function to demonstrate the binary tree operations
int main() {
    TreeNode* root = nullptr;

    // insert nodes into the binary tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);

    // perform in-order traversal
    cout << "In-Order Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // search for a value in the binary tree
    int value = 40;
    if (searchNode(root, value)) {
        cout << "Value " << value << " found in the tree." << endl;
    } else {
        cout << "Value " << value << " not found in the tree." << endl;
    }

    // delete a node from the binary tree
    root = deleteNode(root, 50);

    // perform in-order traversal after deletion
    cout << "In-Order Traversal after deleting 50: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
