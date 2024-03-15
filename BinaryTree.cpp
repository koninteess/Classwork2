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



// Function to print binary tree recursively

void printTreeRecursive(Node* root, int level = 0) {

    if (root == NULL)

        return;



    // Print right subtree

    printTreeRecursive(root->right, level + 1);



    // Print current node

    for (int i = 0; i < level; ++i)

        cout << "  ";

    cout << root->data << endl;



    // Print left subtree

    printTreeRecursive(root->left, level + 1);

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



    cout << "Binary Tree:" << endl;

    printTreeRecursive(root);



    return 0;

}