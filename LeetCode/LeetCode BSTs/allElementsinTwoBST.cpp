/*
Given two binary search trees root1 and root2,
 return a list containing all the integers from both trees sorted in ascending order.

 Approach:
 1) Perform in-order traversal 
    - Perform an in-order travesal on both BSTs to extract their values in sorted order, gives two arrays

 2) Merge the two sorted arrays
    - Merge step of merge sorte to combine the two sorted arrays into a single sorted list
*/

// Time Complexity : O(n1 + n2) where n1 and n2 are the number of nodes in the two BSTs
// Space Complexity : O(n1 + n2) where n1 and n2 are the number of nodes in the two BSTs
#include <bits/stdc++.h>
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
    // Perform in-order traversal to get sorted values of BST
    void inOrderTraversal(TreeNode* root, vector<int> &values) {
        // Base case - if root is null
        if(root == NULL) {
            return;
        }

        // Traverse left subtree
        inOrderTraversal(root->left, values);
        // Add root value to the list
        values.push_back(root->val);
        // Traverse right subtree
        inOrderTraversal(root->right, values);
    }

        // Merge the two sorted arrays
        vector<int> mergeSortedArrays(const vector<int>&arr1, const vector<int>&arr2) {
            // Initialize the array
            vector<int> result;
            // Initialize the pointers
            int i = 0, j = 0;

            // While loop to merge the two arrays
            while (i < arr1.size() && j < arr2.size()) {
                // If element of arr1 is less than element of arr2
                if(arr1[i] < arr2[j]) {
                    // Add element of arr1 to the result
                    result.push_back(arr1[i]);
                    // Increment the pointer
                    i++;
                } else {
                    // Add element of arr2 to the result
                    result.push_back(arr2[j]);
                    // Increment the pointer
                    j++;
                }
            }

            // Add the remaining elements of arr1 to the result
            while(i < arr1.size()) {
                result.push_back(arr1[i]);
                i++;
            }
            // Add the remaining elements of arr2 to the result
            while(j < arr2.size()) {
                result.push_back(arr2[j]);
                j++;
        }
        return result;
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> values1, values2;
        // Perform in-order traversal on both BSTs
        inOrderTraversal(root1, values1);
        inOrderTraversal(root2, values2);
        // Merge the two sorted arrays
        return mergeSortedArrays(values1, values2);
    }
};