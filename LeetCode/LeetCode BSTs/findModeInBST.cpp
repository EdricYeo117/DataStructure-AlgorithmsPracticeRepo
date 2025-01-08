/*
Given the root of a binary search tree (BST) with duplicates, 
eturn all the mode(s) (i.e., the most frequently occurred element) in it.
If the tree has more than one mode, return them in any order.

Approach:
1) Perform an in-order traversal of the BST

2) Track the following:
    a) current value
        - Current value being processed
    b) current count
        - Frequency of currentValue
    c) max count
        - Highest frequency of any value
    d) mode count
        - List of all modes

3) Update modes based on currentCount and maxCount

4) Return modeCount
*/

// Recursive approach
// Time complexity: O(n)
// Space complexity: O(h)
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
    vector<int> modes; // Store the mode(s)
    int currentVal; // Current value being processed
    int currentCount; // Frequency of currentValue
    int maxCount; // Highest frequency of any value

    // Helper function for in-order traversal
    void inOrder(TreeNode* node) {
        // Base case - root is null
        if (node == nullptr) {
            return;
        }

        // Traverse left subtree
        inOrder(node->left);

        // Process current node
        if (node->val == currentVal) {
            currentCount++;
        } else {
            currentVal = node->val;
            currentCount = 1;
        }

        // Update modes based on currentCount and maxCount
        if (currentCount > maxCount) {
            maxCount = currentCount; 
            modes = {currentVal}; // New mode found, reset modes list
        } else if (currentCount == maxCount) {
            modes.push_back(currentVal); // Add currentVal to modes list
        }

        // Right subtree
        inOrder(node->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        currentVal = 0;
        currentCount = 0;
        maxCount = 0;
        modes.clear();

        inOrder(root); 
        return modes;
    }
};

// Iterative approach
// Time complexity: O(n)
// Space complexity: O(h)
#include <stack>
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        // Base case - root is null
        if (!root) return {};

        vector<int> modes;
        stack<TreeNode*> st;
        TreeNode* current = root;

        // Track current value, current count, and max count
        int currentVal = 0, currentCount = 0, maxCount = 0;

        // In-order traversal of the BST
        while (!st.empty() || current != nullptr) {
            // Traverse left subtree
            while (current != nullptr) {
                // Push current node to stack
                st.push(current);
                // Move to left child
                current = current->left;
            }
            
            // Process current node
            current = st.top();
            // Pop current node
            st.pop();

            // Process current node
            if (current->val == currentVal) {
                // Increment current count
                currentCount++;
            } else {
                // Update current value and count
                currentVal = current->val;
                // Reset current count
                currentCount = 1;
            }

            // Update modes based on currentCount and maxCount
            if (currentCount > maxCount) {
                // Update max count
                maxCount = currentCount;
                modes = {currentVal}; // Reset modes
            } else if (currentCount == maxCount) {
                modes.push_back(currentVal); // Add to modes
            }
            // Move to right child
            current = current->right;   
        }
        return modes;
    }
};
