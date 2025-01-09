/*
Given the root of a binary search tree, return a balanced binary search tree with the same node values. 
If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Approach:
1) In Order Traversal 
    - Perform an in-order traversal to extract all node values
    in ascending order into a sorted array
    - Array will serve as the foundation for constructing a balanced BST
2) Build a balanced BST
    - Use the divide-and-conquer approach:
        - Choose the middle element of the sorted array as the root
        - Recursively construct the left and right subtrees using the 
        left and right halves of the array, respectively
*/

// Time Complexity: O(N)
// Space Complexity: O(N) [O(log N) for building BST]
#include <vector>
using namespace std;

// Definition of TreeNode
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
    // Perform in-order traversal to store values in ascending order
    void inOrderTraversal(TreeNode* node, vector<int>& values) {
        // Base case - null node
        if (!node) return;
        // Recursive case - traverse left subtree, current node, right subtree
        inOrderTraversal(node->left, values);
        // Store current node value
        values.push_back(node->val);
        // Traverse right subtree
        inOrderTraversal(node->right, values);
    }

    // Build a balanced BST from a sorted array
    TreeNode* buildBalancedBST(vector<int>& values, int left, int right) {
        if (left > right) return nullptr; // Base case

        int mid = left + (right - left) / 2; // Choose middle element as root
        TreeNode* root = new TreeNode(values[mid]);

        // Recursively build left and right subtrees
        root->left = buildBalancedBST(values, left, mid - 1);
        root->right = buildBalancedBST(values, mid + 1, right);

        return root;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> values;
        inOrderTraversal(root, values); // Step 1: Extract values in sorted order
        return buildBalancedBST(values, 0, values.size() - 1); // Step 2: Reconstruct balanced BST
    }
};