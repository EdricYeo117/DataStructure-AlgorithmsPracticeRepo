
 /*
 You are given the root of a binary search tree and an array queries of size n consisting of positive integers.

Find a 2D array answer of size n where answer[i] = [mini, maxi]:

mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.
maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.
Return the array answer.

Approach:
1) BST Property
- Left subtree contains values less than or equal to the root's value
- Right subtree contains values greater than or equal to the root's value

2) Inorder Traversal of BST
- Perform inorder traversal of get a sorted array of the BSTs values.
    This allows us to use binary search for efficient queries

3) Binary Search for Closest Values
 - For each query:
    - Use binary search to find the cloest values in the sorted array
    Determine:
        - Mini - Largest value less than or equal to the query 
        - Maxi - Smallest value greater than or equal to the query
 */
#include <vector>
#include <algorithm>
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
    // Perform in-order traversal to get sorted values 
    void inOrderTraversal(TreeNode* root, vector<int>& sortedValues){
        if (root == nullptr) return;

        // Traverse Left Subtree
        inOrderTraversal(root->left, sortedValues);
        // Visit the Node
        sortedValues.push_back(root->val);
        // Traverse Right Subtree
        inOrderTraversal(root->right, sortedValues);
    }

public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        // Get sorted values of the BST
        vector<int> sortedValues;
        inOrderTraversal(root, sortedValues); // Step 1: Get sorted values

        vector<vector<int>> answer;

        // For each query
        for (int query : queries) {
            int mini = -1, maxi = -1;

            // Find the smallest value >= query
            auto itMax = lower_bound(sortedValues.begin(), sortedValues.end(), query);
            if (itMax != sortedValues.end()) {
                maxi = *itMax; // Set maxi
            }

            // Find the largest value <= query
            if (itMax != sortedValues.begin()) {
                auto itMin = prev(itMax);
                mini = *itMin;
            }

            // Handle the case where query == *itMax
            if (itMax != sortedValues.end() && *itMax == query) {
                mini = query;
            }

            answer.push_back({mini, maxi});
        }

        return answer;
    }
};
