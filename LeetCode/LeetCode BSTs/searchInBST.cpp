/*
You are given the root of a binary search tree (BST) and an integer val.

Find the node in the BST that the node's value equals val and return the subtree rooted with that node. 
If such a node does not exist, return null.
*/

  struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    // Recursive approach
    // Time Complexity = O(H), where H is the height of the tree
    // Space Complexity = O(H), where H is the height of the tree
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if root is null, return null
        if (root == nullptr || root->val == val) return root;

        // Recursive case: If the value is smaller, search the left subtree
        if (val < root->val) {
            return searchBST(root->left, val);
        }
        // Recursive case: If the value is larger, search the right subtree
        return searchBST(root->right, val);
    }
};

// Iterative approach
// Time Complexity = O(H), where H is the height of the tree
// Space Complexity = O(1)
TreeNode* searchBST(TreeNode* root, int val) {
    // While loop to iterate through the tree
    while (root != nullptr && root->val != val) {
        // If statement to check if the value is smaller
        if (val < root->val) {
            root = root->left; // Move to the left subtree
        } else {
            root = root->right; // Move to the right subtree
        }
    }
    return root; // Return the node
}