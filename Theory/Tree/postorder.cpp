// Postorder traversal of a binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};

void printPostorder(Node* node) {
    if (node == nullptr)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}

int main() {
    Node* root = new Node(25);
    root->left = new Node(15);
    root->right = new Node(20);
    root->left->left = new Node(15);
    root->left->right = new Node(22);
    root->right->left = new Node(35);
    root->right->right = new Node(70);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(12);
    root->left->right->left = new Node(18);
    root->left->right->right = new Node(24);
    root->right->left->left = new Node(31);
    root->right->left->right = new Node(44);
    root->right->right->left = new Node(66);
    root->right->right->right = new Node(90);

    cout << "Inorder traversal of binary tree is: \n";
    printPostorder(root);
    cout << endl;

    return 0;
}