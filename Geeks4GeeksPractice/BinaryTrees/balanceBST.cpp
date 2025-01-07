/*
Convert it into a balanced BST that has the minimum possible height.

Store elemnts of the tree in an array using in order traversal
Recursively construct a balanced BST by picking middle element of array as root for each subtree

Time Complexity: O(n)
Space Complexity: O(n)
*/

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

// Inorder traversal to store elements of the
// tree in sorted order
void storeInorder(Node* root, vector<int>& nodes) {
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    storeInorder(root->left, nodes);

    // Store the node data
    nodes.push_back(root->data);

    // Traverse the right subtree
    storeInorder(root->right, nodes);
}

// Function to build a balanced BST from a sorted array
Node* buildBalancedTree(vector<int>& nodes, int start, int end) {
    
    // Base case
    if (start > end) {
        return nullptr;
    }

    // Get the middle element and make it the root
    int mid = (start + end) / 2;
    Node* root = new Node(nodes[mid]);

    // Recursively build the left and right subtrees
    root->left = buildBalancedTree(nodes, start, mid - 1);
    root->right = buildBalancedTree(nodes, mid + 1, end);

    return root;
}

// Function to balance a BST
Node* balanceBST(Node* root) {
    vector<int> nodes;

    // Store the nodes in sorted order
    storeInorder(root, nodes);

    // Build the balanced tree from the sorted nodes
    return buildBalancedTree(nodes, 0, nodes.size() - 1);
}

// Function to print the tree (Inorder Traversal)
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    
    // Constructing an unbalanced BST
    //        10
    //       /  \
    //      5    15
    //     /       \
    //    2         20
    //   /
    //  1

    Node* root = new Node(10);
    root->left = new Node(5);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(15);
    root->right->right = new Node(20);

    Node* balancedRoot = balanceBST(root);
    inorder(balancedRoot);
    cout << endl;

    return 0;
}