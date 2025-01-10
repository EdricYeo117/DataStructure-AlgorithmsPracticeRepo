/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    bool validate(TreeNode *node, TreeNode *minNode, TreeNode *maxNode)
    {
        // Base case - if the node is null, then it is a valid BST (Empty tree is a valid BST)
        if (node == nullptr)
        {
            return true;
        }

        // Check if the node's value is within the range of min and max
        if (minNode && node->val <= minNode->val ||
            maxNode && node->val >= maxNode->val)
        {
            return false;
        }

        // Recursive case - check the left and right subtrees
        return validate(node->left, minNode, node) && validate(node->right, node, maxNode);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return validate(root, nullptr, nullptr);
    }
};