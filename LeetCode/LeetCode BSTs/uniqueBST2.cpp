/*
Given an integer n, return all the structurally unique BST's (binary search trees), 
which has exactly n nodes of unique values from 1 to n. 
Return the answer in any order.
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
    vector<TreeNode*> buildTrees(int start, int end) {
        // Intialise vector to store trees
        vector<TreeNode*> trees;
        // If loop start > end, return NULL
        // Base Case - Empty tree
        if (start > end) {
            trees.push_back(NULL);
            return trees;
        }

        // For loop to iterate through all the nodes
        for (int i = start; i <= end; ++i) {
            // Generate all possible left subtrees with numbers less than i
            vector<TreeNode*> leftSubTrees = buildTrees(start, i - 1);
            // Generate all possible right subtrees with numbers greater than i
            vector<TreeNode*> rightSubTrees = buildTrees(i + 1, end);

            // Combine each left and right subtree with the current root i
            // For loop to iterate through all the left subtrees
            for (TreeNode* left : leftSubTrees) {
                for (TreeNode* right : rightSubTrees) {
                    // Create a new tree with root i 
                    TreeNode* root = new TreeNode(i);
                    // Assign left and right subtrees
                    root->left = left;
                    root->right = right;
                    // Push the tree to the vector
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        // If n is 0, return empty vector
        if (n == 0) {
            return {};
        }
        return buildTrees(1, n);
    }
};