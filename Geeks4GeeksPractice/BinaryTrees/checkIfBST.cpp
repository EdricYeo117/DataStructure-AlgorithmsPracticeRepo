/*
Uses morris traversal to check if a binary tree is a BST
Start with the root node and traverse the tree while maintaining a pointer to the current node.
For each node, find its inorder predecessor (the rightmost node in its left subtree). Use this node to temporarily link back to the current node.
If the left child exists, create a temporary thread from the inorder predecessor to the current node.
If the left child does not exist, process the current node’s data and move to its right child.
Once you visit the current node, restore the tree by removing the temporary thread. Check the inorder property and proceed to the right child.
Compare the current node’s value with the previously visited node’s value.
Continue this process until all nodes are visited. If all nodes satisfy the BST property, then the tree is a BST.
*/

// C++ program to check if a tree is 
// BST using Morris Traversal

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to check if the binary tree is a BST using Morris Traversal
bool isBST(Node* root) {
    Node* curr = root;
    Node* pre = nullptr;
    int prevValue = INT_MIN; 

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            
            // Process curr node
            if (curr->data <= prevValue) {
                
                // Not in ascending order
                return false; 
            }
            prevValue = curr->data;
            curr = curr->right;
        } else {
            
            // Find the inorder predecessor of curr
            pre = curr->left;
            while (pre->right != nullptr && pre->right != curr) {
                pre = pre->right;
            }

            if (pre->right == nullptr) {
                
                // Create a temporary thread to the curr node
                pre->right = curr;
                curr = curr->left;
            } else {
                
                // Remove the temporary thread
                pre->right = nullptr;

                // Process the curr node
                if (curr->data <= prevValue) {
                    
                    // Not in ascending order
                    return false; 
                }
                prevValue = curr->data;
                curr = curr->right;
            }
        }
    }

    return true; 
}

int main() {
  
    // Create a sample binary tree
    //      4
    //    /   \
    //   2     5
    //  / \
    // 1   3

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    if (isBST(root)) {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;
    }

    return 0;
}