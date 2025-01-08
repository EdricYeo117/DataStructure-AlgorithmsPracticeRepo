/*
Given the root of a binary search tree and an integer k, return true 
if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
 */

/*
1) Perform inorder traversal to get a sorted array of node values
2) Use two pointers to find the sum
    - Start with two pointers, one at beginning and one at end
    - Adjust the pointers based on the sum

*/
#include <bits/stdc++.h>
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
public:
    // Helper function to perform inorder traversal and store values
    void inOrderTraversal(TreeNode* root, vector<int> &nums) {
        // Base case: if root is null, return
        if (!root) return;
        // Recursive case: in order traversal to the left
        inOrderTraversal(root->left, nums);
        // Append the value of the node to the vector
        nums.push_back(root->val);
        // Recursive case: in order traversal to the right
        inOrderTraversal(root->right, nums);
    }

    // Main function to find if two elements sum to k using two-pointer technique
    bool findTarget(TreeNode* root, int k) {
        // Vector to store the values of the nodes
        vector<int> nums;
        // Perform inorder traversal to get a sorted array of node values
        inOrderTraversal(root, nums); // Step 1: Get sorted array

        // Step 2: Use two pointers to find the sum
        int left = 0, right = nums.size() - 1;
        // While loop to find the sum
        while (left < right) {
            // Calculate the sum of the two pointers
            int sum = nums[left] + nums[right];
            /// If the sum is equal to k, return true
            if (sum == k) {
                return true; // Found the sum
            } else if (sum <k) {
                left++ ; // Increment the left pointer
            } else {
                right--; // Decrement the right pointer
            }
        }
        return false; // Return false if no sum is found
    }
};

/*
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, root,  k);
    }
    
    bool dfs(TreeNode* root,  TreeNode* cur, int k){
        if(cur == NULL)return false;
        return search(root, cur, k - cur->val) || dfs(root, cur->left, k) || dfs(root, cur->right, k);
    }
    
    bool search(TreeNode* root, TreeNode *cur, int value){
        if(root == NULL)return false;
        return (root->val == value) && (root != cur) 
            || (root->val < value) && search(root->right, cur, value) 
                || (root->val > value) && search(root->left, cur, value);
    }

Time Complexity: O(N log N)
Space Complexity: O(H)
*/