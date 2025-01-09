/*
Implement the BSTIterator class that represents an iterator over the in-order traversal 
    of a binary search tree (BST):

- BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. 
    The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
- boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer,
     otherwise returns false.
- int next() Moves the pointer to the right, then returns the number at the pointer.

Time Complexity: O(H) for the constructor, O(1) for hasNext and next
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

class BSTIterator {
private:
    // stack to store nodes
    stack<TreeNode*> st;

    // Helper Function to push all the left nodes of the current node
    void pushLeftNodes(TreeNode* root) {
        // While root is not null
        while (root) {
            // Push the root to the stack
            st.push(root);
            // Move to the left child
            root = root->left;
        }
    }

public:
    // Constructor - Intialise the iterator and push all left nodes
    BSTIterator(TreeNode* root) {
        pushLeftNodes(root);
    }
    
    // Return the next smallest value in BST
    int next() {
        // Get the top element of the stack
        TreeNode* top = st.top();
        // Pop the top element
        st.pop();

        // If the node has right child, push its left descendants onto the stack
        if (top->right) {
            pushLeftNodes(top->right);
        }

        // Return the value of the top element
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */