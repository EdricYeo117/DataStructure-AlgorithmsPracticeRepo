/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 Return the root node reference (possibly updated) of the BST.

Approach:

1) Node to the delete has no children (leaf node)
- Remove the node by returning nullptr

2) Node to delete has one child
- Remove the node by returning the child

3) Node to delete has two children
- Find the inorder successor of the node to delete
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
private:
    TreeNode* findMin(TreeNode* node) {
        // Helper function to find minimum value node in BST
        while(node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case - if root is null
        if(root == nullptr) {
            return root;
        }

        // Find the node to delete
        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Recursively search in left subtree
        } else if (key > root->val) {
            root->right = deleteNode(root->right , key); // Recursively search in right subtree
        } else {
            // Node to be deleted is found
            if (!root->left) {
                // Case 1 or 2: No Left Child
                TreeNode* rightChild = root->right;
                delete root; // Delete the node
                return rightChild; // Return right child
            } else if (!root->right) {
                // Case 1 or 2: No Right Child
                TreeNode* leftChild = root->left;
                delete root; // Delete the node
                return leftChild; // Return left child
            } else {
                // Case 3: Two Children 
                TreeNode* inorderSuccessor = findMin(root->right); // Find inorder successor
                root->val = inorderSuccessor->val; // Copy the value of inorder successor to root
                root->right = deleteNode(root->right, inorderSuccessor->val); // Delete the inorder successor
            }
        }
        return root;
    }
};