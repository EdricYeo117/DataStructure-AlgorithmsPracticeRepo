/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree 
such that every key of the original BST is changed to the original key plus 
the sum of all keys greater than the original key in BST.

Time Complexity: O(n)
Space Complexity: O(n)
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
private:
    void transformTree(TreeNode* node, int&cumulativeSum) {
        // Base case - if node is null, return
        if (node == nullptr) {
            return;
        }

        // Recursively call the right subtree
        transformTree(node->right, cumulativeSum);

        // Update the node value with the cumulative sum
        cumulativeSum += node->val;
        node->val = cumulativeSum;

        // Recursively call the left subtree
        transformTree(node->left, cumulativeSum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int cumulativeSum = 0;
        transformTree(root, cumulativeSum);
        return root;
    }
};