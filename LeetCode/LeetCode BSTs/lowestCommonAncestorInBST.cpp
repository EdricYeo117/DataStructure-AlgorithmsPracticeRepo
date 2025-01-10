/*
Given a binary search tree (BST), 
find the lowest common ancestor (LCA) node of two given nodes in the BST.
*/

#include <iostream>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case - if root is null
        if (root == nullptr) {
            return nullptr;
        }

        // If both p and q are less than root, then LCA lies in left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If both p and q are greater than root, then LCA lies in right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If one of p or q is equal to root, then root is the LCA
        return root;
    }
};