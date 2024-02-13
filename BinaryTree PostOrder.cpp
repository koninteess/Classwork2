#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left, * right;
};

Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to print binary tree recursively in postorder
void printTreePostorder(Node* root) {
    if (root == NULL)
        return;
    printTreePostorder(root->left); // Traverse left subtree
    printTreePostorder(root->right); // Traverse right subtree
    cout << root->data << " "; // Visit the current node
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(9);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(15);

    cout << "Binary Tree (Postorder traversal):" << endl;
    printTreePostorder(root);

    return 0;
}
