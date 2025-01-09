/*
Given an array of integers preorder, 
which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.

It is guaranteed that there is always possible to find a 
binary search tree with the given requirements for the given test cases.

Time complexity: O(n)
Space complexity: O(h)
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
private: 
    TreeNode* buildBST(vector<int> &preorder, int&index, int bound) {
        // Base case : if all elements are processed or the current value exceeds the bound
        if(index == preorder.size() || preorder[index] > bound) {
            return nullptr;
        }

        // Create a new node with the current value
        TreeNode* node = new TreeNode(preorder[index++]);

        // Recursively build the left subtree
        node->left = buildBST(preorder, index, node->val);

        // Recursively build the right subtree
        node->right = buildBST(preorder, index, bound);

        return node;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildBST(preorder, index, INT_MAX);    
    }
};

/*
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return build(preorder,i,INT_MAX);
    }
    TreeNode* build(vector<int>& preorder,int &i,int bound){
        if(i==preorder.size() || preorder[i]>bound) return nullptr;

        TreeNode* root=new TreeNode(preorder[i++]);
        root->left =build(preorder,i,root->val);
        root->right =build(preorder,i,bound);
        return root;

    }
};
*/