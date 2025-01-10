/*
You are given the root of a binary search tree (BST), 
where the values of exactly two nodes of the tree were swapped by mistake. 
Recover the tree without changing its structure.
*/
#include <algorithm>
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
    void inOrder(TreeNode *node, TreeNode* &first, TreeNode *&second, TreeNode *&prev) {
        // Base case - if the node is null, then return
        if (node == nullptr)
        {
            return;
        }

        // Traverse the left subtree
        inOrder(node->left, first, second, prev);

        // Identify the first misplaced node
        if (prev && node->val < prev->val) {
            if (first == nullptr) {
                first = prev;
            }
            second = node;
        }
        // Update the previous node
        prev = node;

        // Traverse the right subtree
        inOrder(node->right, first, second, prev);
    }
public:
    void recoverTree(TreeNode* root) {
        // First misplaced node
        TreeNode *first = nullptr;
        // Second misplaced node
        TreeNode *second = nullptr;
        // Previous node
        TreeNode *prev = nullptr;

        // In order traversal to identify the misplaced nodes
        inOrder(root, first, second, prev);

        // Swap the values of the misplaced nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};