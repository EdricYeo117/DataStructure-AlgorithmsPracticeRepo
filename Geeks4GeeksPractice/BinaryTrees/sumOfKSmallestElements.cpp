/*
Find the sum of all elements smaller than and equal to kth smallest element
*/

#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
        Node(int data) {
            this->data = data;
            left = right = NULL;
        }
};

// Recursive function to calculate sum of first k smallest elements
void calculateSum(Node* root, int& k, int& ans) {
    if (root == nullptr || k <= 0) {
        return; // Base case: null node or already counted k elements
    }

    // In-order traversal: Left → Root → Right
    calculateSum(root->left, k, ans);

    // Process the current node if k > 0
    if (k > 0) {
        ans += root->data; // Add current node's data to the sum
        k--;               // Decrease k (one more element counted)
    } else {
        return; // Stop further traversal when k elements are processed
    }

    calculateSum(root->right, k, ans);
}

// Function to find the sum of the first k smallest elements
int sum(Node* root, int k) {
    int ans = 0; // Initialize sum to 0
    calculateSum(root, k, ans); // Start in-order traversal
    return ans; // Return the calculated sum
}

// Driver Code
int main() {
    /*
    Input BST:
             8
           /   \
          7     10
        /      /  \
       2      9    13
    */
    Node* root = new Node(8);
    root->left = new Node(7);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->right->left = new Node(9);
    root->right->right = new Node(13);

    int k = 3; // Find the sum of the first 3 smallest elements
    cout << "Sum of first " << k << " smallest elements: " << sum(root, k) << "\n";

    return 0;
}