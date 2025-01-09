/*
You are given the root node of a binary search tree 
(BST) and a value to insert into the tree. 
Return the root node of the BST after the insertion. 
It is guaranteed that the new value does not exist in the original BST.

Approach:
1) Base Case:
    If the root is nullptr, create a new node with the value va
    and return. This will be the new leaf node

2) Recursive Case:
    - Compare val with the root->val;
    - If val < root->val,  recurse/iterate into the left subtree
    - If val > root->val, recurse/iterate into the right subtree

3) Update the tree:
    - Set the result of the recursive call to root->left or root->right, as appropiate
    - Return the root node

*/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Base case - If the root is nullptr, create a new node with the value val
        if(root == nullptr) {
            return new TreeNode(val);
        }

        // Recursive case - Compare val with the root->val
        if(val < root->val) {
            // Insert into left subtree
            root->left = insertIntoBST(root->left, val);
        } else {
            // Insert into right subtree
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the tree is empty, create a new root node
        if (root == nullptr) {
            return new TreeNode(val);
        }

        TreeNode* current = root;
        while (true) {
            if (val < current->val) {
                // If there's no left child, insert here
                if (current->left == nullptr) {
                    current->left = new TreeNode(val);
                    break;
                }
                current = current->left; // Move to the left subtree
            } else {
                // If there's no right child, insert here
                if (current->right == nullptr) {
                    current->right = new TreeNode(val);
                    break;
                }
                current = current->right; // Move to the right subtree
            }
        }

        return root; // Return the root of the tree
    }
};