/*
2nd last element in inorder traversal or 2nd element in reverse inorder traversal
*/

#include <iostream>
#include <functional> // For std::function
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

// Generic Reverse In-Order Traversal
void reverseInorder(Node* root, function<bool(Node*)> visit) {
    if (root == nullptr) {
        return;
    }

    // Traverse the right subtree
    reverseInorder(root->right, visit);

    // Visit the current node
    if (visit(root)) {
        return; // Stop traversal if the callback indicates to stop
    }

    // Traverse the left subtree
    reverseInorder(root->left, visit);
}

// Function to find the second largest element in BST
int findSecondLargest(Node* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        cout << "Tree does not have enough nodes." << endl;
        return -1;
    }

    int count = 0; 
    int result = -1;

    // Use the generic reverseInorder with a lambda function
    reverseInorder(root, [&](Node* node) {
        count++;
        if (count == 2) {
            result = node->data;
            return true; // Stop traversal once second largest is found
        }
        return false; // Continue traversal
    });

    return result;
}

// Driver Code
int main() {
    /*
    Representation of the input BST:
                7
               / \
              4   8
             / \   
            3   5 
    */
    Node* root = new Node(7);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    int secondLargest = findSecondLargest(root);

    if (secondLargest != -1) {
        cout << "The second largest element is: " << secondLargest << endl;
    }

    return 0;
}
