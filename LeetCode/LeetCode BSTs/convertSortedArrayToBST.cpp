/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Approach:
1. Find the middle element of the array
2. Create new treenode with the middle value
3. Recursively build:
    - Left subtree with left half of the array
    - Right subtree with right half of the array
4. Return the root of the tree
*/
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
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        // Base case: if left is greater than right, return null
        if(left > right) return nullptr;
        
        // Find the middle element of the array
        int mid = left + (right - left) / 2;

        // Create new treenode with the middle value
        TreeNode* node = new TreeNode(nums[mid]);

        // Recursively build left subtree with left half of the array
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
};