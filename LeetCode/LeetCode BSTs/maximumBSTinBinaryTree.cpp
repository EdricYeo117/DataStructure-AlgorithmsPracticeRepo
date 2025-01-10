/*
Given a binary tree root, 
return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Approach: 

1) Post-order traversal
- Traverse the tree from bottom up to evaluate each subtree

2) Tracking information 
 - For each subtree, determine:
    - Whether it is a BST
    - The sum of all keys in the subtree
    - The maximum sum of all keys in a BST subtree
-  If subtree is not a BST, exclude from calculation

3) Update maximum sum
 - Keep track of maximum sum of all valid BST subtrees encountered during traversal
*/

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
    struct SubTreeInfo {
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
    };

    SubTreeInfo postOrder(TreeNode* node, int& maxSum) {
        // Base case - Empty tree is a BST
        if (node == nullptr) {
            return {true, INT_MAX, INT_MIN, 0};
        }

        // Recursively evaluate left and right subtrees
        SubTreeInfo left = postOrder(node->left, maxSum);
        SubTreeInfo right = postOrder(node->right, maxSum);

        // Check if the current subtree is a BST
        if (left.isBST && right.isBST && node->val > left.maxVal && node->val < right.minVal) {
            // Update maximum sum
            int sum = left.sum + right.sum + node->val;
            maxSum = max(maxSum, sum);

            // Return information about the current subtree
            return { true,
                    min(node->val, left.minVal),
                    max(node->val, right.maxVal),
                    sum };
            } else {
                // Return information about the current subtree
                return { false, 0, 0, 0 };                
            }
        }

public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        postOrder(root, maxSum);
        return maxSum;
    }
};