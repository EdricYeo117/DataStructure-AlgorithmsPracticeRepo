/*
Given two binary search trees root1 and root2, 
return a list containing all the integers from both trees sorted in ascending order.

1) In order traversal for each tree
    - Perform an in-order traversal on both trees (root1 and root2)
    - Store the results in two sorted arrays (sorted1 and sorted2)

2) Merge the two sorted arrays
    - Merge step of the merge sort algorith to 
    merge sorted1 and sorted2 into a single sorted list
*/

#include <iostream>
#include <vector>
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
    // In-order traversal of a binary search tree
     void inOrderTraversal(TreeNode* root, vector<int>& results) {
        // Base case - if the root is null
        if (root == nullptr) {
            return;
        }

        // Recursively perform an in-order traversal on the left subtree
        inOrderTraversal(root->left, results);
        // Add the current node's value to the results
        results.push_back(root->val);
        // Recursively perform an in-order traversal on the right subtree
        inOrderTraversal(root->right, results);
     }

     // Merge two sorted arrays
     vector<int> mergeSortedArrays(const vector<int> &arr1, const vector<int>& arr2) {
        // Initialize 
        vector<int> merged;

     }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
    }
};