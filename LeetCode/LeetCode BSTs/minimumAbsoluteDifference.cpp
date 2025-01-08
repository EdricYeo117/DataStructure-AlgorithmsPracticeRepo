/*
Given the root of a Binary Search Tree (BST), 
return the minimum absolute difference between the values of any two different nodes in the tree.

In order traversal
1) Perform an in-order traversal of the BST
2) Maintain:
    a) Variable prev to store the previous node value
    b) Variable minDiff to store the minimum difference between the values of any two different nodes

3) At each node:
    a) Calculate the diffference between current node's value and prev
    b) Update minDiff if the difference is smaller

4) Update prev to the current node's value

5) Return minDiff
*/

#include <climits> // For INT_MAX
#include <cmath>   // For abs()
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
    int minDiff = INT_MAX;
    int prev = -1; // To store previous node's value during in-order traversal

    void inOrderTraversal (TreeNode* root) {
        // Base case: If root is null, return
        if (root == nullptr) return;

        // Traverse the left subtree
        inOrderTraversal(root->left);

        // Process current node value
        if (prev != -1) {  // Skip comparing the first node
            minDiff = min(minDiff, abs(root->val - prev));
        } 
        prev = root->val; // Update prev to the current node's value

        // Traverse the right subtree
        inOrderTraversal(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        inOrderTraversal(root);
        return minDiff;
    }
};