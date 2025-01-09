/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, 
trim the tree so that all its elements lies in [low, high]. 
Trimming the tree should not change the relative structure of
 the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). 
 It can be proven that there is a unique answer.

Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

Steps:
1) Base Case:
    if root is null return null
2) Trim Subtrees:
    Recursively trim the left and right subtrees
*/

#include <iostream>
#include <vector>
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // Base Case - If root is null return null
        if (!root) return nullptr;

        // If current node is less than low, then we need to trim the right subtree
        if (root->val < low) return trimBST(root->right, low, high);

        // If current node is greater than high, then we need to trim the left subtree
        if (root->val > high) return trimBST(root->left, low, high);

        // Recursively trim the left and right subtrees
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        return root;
    }
};