/*
Given two values n1 and n2, where n1 < n2, and a root pointer to a binary search tree
Find the number of keys in the binary search tree in the range n1 to n2 (inclusive)
*/

// Can use in order traversal recursion but Morris Traversal is more efficient

/*
- intialise current node as root
- While current is not null, check if there is left child
    If there is no left child, append current node if it lies in given range,
    move to right child of current node
    Otherwise, find right most node of left subtree, or node whose right child is current node
    - If right child is null, make current node right child and move to left child of current
    - If right child is current node itself, append the current node and if it lies in given range
    make right child NULL, move to right child of current node
*/

#include <iostream>
#include <vector>
using namespace std;

class Node
{

public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

// Function to print nodes
vector<int> printNearNodes(Node *root, int low, int high)
{
    vector<int> result;
    Node *current = root;
    while (current != nullptr)
    {

        // If left child is null, check
        // current node, move to right node
        if (current->left == nullptr)
        {
            if (current->data >= low && current->data <= high)
                result.push_back(current->data);
            current = current->right;
        }
        else
        {

            // Find the inorder predecessor of current
            Node *pre = current->left;
            while (pre->right != nullptr && pre->right != current)
                pre = pre->right;

            // Make current as right child of its inorder predecessor, move to left node
            if (pre->right == nullptr)
            {
                pre->right = current;
                current = current->left;
            }

            // Revert the changes made in if part to restore the original tree
            else
            {
                pre->right = nullptr;
                if (current->data >= low && current->data <= high)
                    result.push_back(current->data);
                current = current->right;
            }
        }
        return result;
    }
}

int main()
{

    // BST
    //       22
    //      /  \
    //    12    30
    //   /  \
    //  8    20
    Node *root = new Node(22);
    root->left = new Node(12);
    root->right = new Node(30);
    root->left->left = new Node(8);
    root->left->right = new Node(20);
    int n1 = 10, n2 = 22;
    vector<int> ans = printNearNodes(root, n1, n2);

    for (auto num : ans)
        cout << num << " ";

    return 0;
}