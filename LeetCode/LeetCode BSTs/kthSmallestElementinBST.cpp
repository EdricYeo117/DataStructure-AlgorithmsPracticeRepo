/*
Given the root of a binary search tree, and an integer k, 
return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Time complexity: O(n)
Space complexity: O(n)
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
    void inOrder(TreeNode* node, int k, int& count, int& result) {
        // Base case - if node is null
        if (node == nullptr) {
            return;
        }

        // Recur for left subtree
        inOrder(node->left, k, count, result);

        // Increment count
        count++;
        // If count is equal to k, then we have found the kth smallest element
        if (count == k) {
            result = node->val;
            return;
        }

        // Recur for right subtree
        inOrder(node->right, k, count, result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;
        inOrder(root, k, count, result);
        return result;
    }
};