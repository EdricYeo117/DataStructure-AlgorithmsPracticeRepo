/*
modify it so that all greater
 and equal values in the given BST are added to every node.

This method doesn’t require the tree to be a BST. Following are the steps:

Traverse node by node (in-order, pre-order, etc.).
For each node, find all the nodes greater than equal to the current node and sum their values. Store all these sums.
Replace each node’s value with its corresponding sum by traversing in the same order as in Step 1.
*/

// C++ program to transform a BST to
// sum tree

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to find nodes having greater value than
// current node.
void findGreaterNodes(Node* root, Node* curr, 
                      unordered_map<Node*,int> &mp) {
    if (root == nullptr) return;
    
    // if value is greater than equal to node,  
    // then increment it in the map
    if (root->data >= curr->data) 
        mp[curr] += root->data;
        
    findGreaterNodes(root->left, curr, mp);
    findGreaterNodes(root->right, curr, mp);
}

void transformToGreaterSumTree(Node* curr, Node* root, 
                               unordered_map<Node*,int>&mp) {
    if (curr == nullptr) {
        return;
    }

    // Find all nodes greater than current node
    findGreaterNodes(root, curr, mp);
    
    // Recursively check for left and right subtree.
    transformToGreaterSumTree(curr->left, root, mp);
    transformToGreaterSumTree(curr->right, root, mp);
}

// Function to update value of each node.
void preOrderTrav(Node* root, unordered_map<Node*, int> &mp) {
    if (root == nullptr) return;
    
    root->data = mp[root];
    
    preOrderTrav(root->left, mp);
    preOrderTrav(root->right, mp);
}

void transformTree(Node* root) {
  
      // map to store greater sum for each node.
    unordered_map<Node*, int> mp;
    transformToGreaterSumTree(root, root, mp);
    
    // update the value of nodes
    preOrderTrav(root, mp);
}

void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
  
// Representation of input binary tree:
//           50
//         /    \
//        30    70
//      /  \    / \  
//     20  40  60  80
Node* root = new Node(50);
root->left = new Node(30);
root->right = new Node(70);
root->left->left = new Node(20);
root->left->right = new Node(40);
root->right->left = new Node(60);
root->right->right = new Node(80);

transformTree(root);
inorder(root);
    
    return 0;
}