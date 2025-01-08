/*
Given the root of a binary search tree, 
rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree,
 and every node has no left child and only one right child.

Approach:
1) Perform an in-order traversal of the BST
2) Link each node:
    a) Set node->left = nullptr (remove left child)
    b) Link node to the right child of previous node (prev->right = node)

3) Return the new root of the tree (leftmost node)
*/

#include <stack>
#include <iostream>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private: 
    TreeNode* dummyNode; // Dummy node to link the nodes
    TreeNode* current;  // Pointer to track the current node in rearranged tree

    void inOrder(TreeNode* node) {
        // Base case: if node is null, return
        if (node == nullptr) {
            return;
        }

        // Recursive call on left child, to traverse the left subtree
        inOrder(node->left);

        // Process the current node 
        // Set the left child of the current node to null
        node->left = nullptr;
        // Link the current node to the right child of the previous node
        current->right = node;
        // Move the current pointer to the current node
        current = node;

        // Traverse the right subtree
        inOrder(node->right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        dummyNode = new TreeNode(-1); // Create a dummy node with value -1
        current = dummyNode; // Initialize current pointer to dummy node
        // Perform in-order traversal of the BST
        inOrder(root);
        // Return the leftmost node of the rearranged tree
        return dummyNode->right;
    }
};

// Iterative approach
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* dummyNode = new TreeNode(-1); // Dummy node as a placeholder
        TreeNode* current = dummyNode; // Pointer to form the new tree

        TreeNode* node = root;
        while (!st.empty() || node != nullptr) {
            while (node != nullptr) {
                st.push(node);
                node = node->left; // Go as far left as possible
            }

            node = st.top();
            st.pop();

            // Process the current node
            node->left = nullptr; // Remove left child
            current->right = node; // Link to the right child of the current node
            current = node; // Move current to the newly added node

            node = node->right; // Move to the right subtree
        }

        return dummyNode->right; // Return the right child of the dummy node
    }
};