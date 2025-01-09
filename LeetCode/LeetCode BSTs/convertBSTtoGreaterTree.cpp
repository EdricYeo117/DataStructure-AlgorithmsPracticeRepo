/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree 
such that every key of the original BST is changed to the original key 
plus the sum of all keys greater than the original key in BST.

Approach:
1) Reverse in-order traversal 
    - Start w/ the rightmost node (largest value in BST)
    - Accumuldate the sum of all nodes visited so far
    - Update the value of the current node to the sum

2) Cumulative sum
    - Traverse the tree in reverse in-order fashion
    - Keep track of the sum of all nodes visited so far
    - Update the value of the current node to the sum
    - Update the sum to the sum of the current node and the sum of all nodes greater than the current node

Time complexity: O(n) where n is the number of nodes in the BST
Space complexity: O(h) where h is the height of the BST

-- Edge Cases --
1) Empty tree
2) Single node tree
3) Skewed Tree
*/
#include <bits/stdc++.h>
#include <iostream>
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
    int cumulativeSum = 0;
    // Reverse in-order traversal
    void reverseInOrderTraversal(TreeNode* root) {
        // Base case - if noot is null
        if(root == NULL) {
            return;
        }

        // Traverse right subtree
        reverseInOrderTraversal(root->right);

        // Update the value of the current node
        cumulativeSum += root->val;
        root->val = cumulativeSum;

        // Traverse left subtree
        reverseInOrderTraversal(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        // Reverse in-order traversal
        reverseInOrderTraversal(root);
        return root;    
    }
};