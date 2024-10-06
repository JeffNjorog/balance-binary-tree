#include <iostream>
#include <cmath> 
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(NULL), right(NULL) {}
};

// Function to insert a new node into the binary tree
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to calculate the height of the tree and check if it's balanced
int checkHeight(Node* node) {
    if (node == NULL) return 0; // Base case: height of empty tree is 0

    int leftHeight = checkHeight(node->left);
    int rightHeight = checkHeight(node->right);

    // If subtree is not balanced, propagate -1 upwards
    if (leftHeight == -1 || rightHeight == -1 || std::abs(leftHeight - rightHeight) > 1) {
        return -1; // Not balanced
    }

    // Return height of the current node
    return max(leftHeight, rightHeight) + 1;
}

// Function to check if the binary tree is balanced
bool isBalanced(Node* root) {
    return checkHeight(root) != -1; // If checkHeight returns -1, it's not balanced
}

// Driver code
int main() {
    Node* root = nullptr; // Initialize the root of the tree
    int number;

    cout << "Enter numbers to insert into the binary tree (type -1 to stop):" << endl;

    while (true) {
        cin >> number;
        if (number == -1) break; // Exit condition for input
        root = insert(root, number); // Insert the number into the binary tree
    }

    // Check if the binary tree is balanced
    if (isBalanced(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }

    return 0;
}
