/*
Given the root of a Binary Search Tree (BST),
return the minimum difference between the values of any two different nodes in the tree.
*/

/*
1) Perform an in-order traversal of the BST
2) Track the previous node's value and calculate absolute difference with the current node's value
3) Update the minimum difference if the current difference is smaller
4) Return the minimum difference after the traversal
*/
#include <climits>
#include <cmath>
#include <stack>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

// Time Complexity: O(N)
// Space Complexity: O(H) - where H is the height of the BST

class Solution {
private: 
    int minDiif = INT_MAX; // Initialize the minimum difference
    int prev = -1; // Initialize the previous node's value

    void inOrderTraversal (TreeNode* root) {
        // Base case - return if the current node is null
        if (!root) return;

        // Traverse the left subtree
        inOrderTraversal(root->left);

        // Process the current node
        if (prev != -1) {
            minDiif = min(minDiif, abs(root->val - prev)); // Update the minimum difference
        }
        // Update the previous node's value
        prev = root->val;

        // Traverse the right subtree
        inOrderTraversal(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        inOrderTraversal(root); // Perform in-order traversal
        return minDiif; // Return the minimum difference
    }
};

// Iterative Approach
// Time Complexity: O(N) 
// Space Complexity: O(H) - where H is the height of the BST
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        // Initialize a stack for the iterative in-order traversal
        stack<TreeNode*> st;
        // Initialize the minimum difference and the previous node's value
        TreeNode* curr = root;
        int minDiff = INT_MAX;
        int prev = -1;

        // Perform the iterative in-order traversal
        // While loop will run until the stack is empty and the current node is null
        while (!st.empty() || curr != nullptr) {
            while (curr != nullptr) {
                // Push the current node into the stack and move to the left child
                st.push(curr);
                // Move to the left child
                curr = curr->left;
            }
            // Pop the top node from the stack
            curr = st.top();
            // Remove the top node from the stack
            st.pop();

            // Process the current node
            if (prev != -1) {
                // Update the minimum difference
                minDiff = min(minDiff, abs(curr->val - prev));
            }
            // Update the previous node's value
            prev = curr->val;
            // Move to the right child
            curr = curr->right;
        }
        // Return the minimum difference
        return minDiff;
    }
};