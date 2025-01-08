/*
Given the root of a Binary Search Tree (BST) and two integers low and high, 
return the sum of all node values that fall within the inclusive range [low, high].
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

// Recursive solution
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        // Base case: if root is null, return 0
        if(root == nullptr) return 0;
        int sum = 0;

        // Include the current node's value if it's within range
        if(root->val >= low && root->val <= high) {
            sum += root->val;
        }

        // If currentnode's value is greater than low, explore left subtree
        if(root->val > low) {
            sum += rangeSumBST(root->left, low, high);
        }

        // If currentnode's value is less than high, explore right subtree
        if(root->val < high) {
            sum += rangeSumBST(root->right, low, high);
        }
        return sum;
    }
};

// Iterative solution (Stack)

#include <stack>
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {

        // Bae case: if root is null, return 0
        if(root == nullptr) return 0;

        // Initialize stack to store nodes
        stack<TreeNode*> st;
        st.push(root);
        int sum = 0;

        // While loop to traverse the tree
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            // If current node's value is within range, add it to sum
            if (!node) continue;

            // If current node's value is within range, add it to sum
            if(node->val >= low && node->val <= high) {
                sum += node->val;
            }

            // If current node's value is greater than low, add left child to stack
            if(node->val > low) {
                st.push(node->left);
            }

            // If current node's value is less than high, add right child to stack
            if(node->val < high) {
                st.push(node->right);
            }
        }
        return sum;
    }
};

