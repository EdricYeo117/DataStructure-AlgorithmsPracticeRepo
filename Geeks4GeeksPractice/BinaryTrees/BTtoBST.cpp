/*
Given a Binary Tree, 
the task is to convert it to a Binary Search Tree. 
The conversion must be done in such a way that keeps the original structure of the Binary Tree. 
*/
// C++ Program to convert binary 
// tree to binary search tree.
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Inorder traversal to store the nodes in a vector
void inorder(Node* root, vector<int>& nodes) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left, nodes);
    nodes.push_back(root->data);
    inorder(root->right, nodes);
}

// Inorder traversal to convert tree
// to BST.
void constructBST(Node* root, vector<int> nodes, int& index) {
    if (root == nullptr) return;
    
    constructBST(root->left, nodes, index);
    
    // Update root value
    root->data = nodes[index++];
    
    constructBST(root->right, nodes, index);
}

// Function to convert a binary tree to a binary search tree
Node* binaryTreeToBST(Node* root) {
    vector<int> nodes;
    inorder(root, nodes);
    
    // sort the nodes
    sort(nodes.begin(), nodes.end());
    
    int index = 0;
    constructBST(root, nodes, index);
    return root;
}

// Function to print the inorder traversal of a binary tree
void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    
    // Creating the tree
    //         10
    //        /  \
    //       2    7
    //      / \
    //     8   4
    Node* root = new Node(10);   
    root->left = new Node(2);    
    root->right = new Node(7);   
    root->left->left = new Node(8);  
    root->left->right = new Node(4);
    
    Node* ans = binaryTreeToBST(root);
    printInorder(ans);

    return 0;
}