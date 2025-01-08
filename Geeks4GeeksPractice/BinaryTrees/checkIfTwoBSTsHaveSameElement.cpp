/*
Given two Binary Search Trees consisting of unique positive elements, 
the task is to check whether the two BSTs contain the same set of elements or not. 
The structure of the two given BSTs can be different. 

The simple idea is to traverse the first tree. For each node,
 check if a node exists with the same value in the second tree.
  If it exists, then set the node value of the 
  second tree to -1 (to mark the node as visited) a
  nd recursively check for the left and right subtree. Otherwise, return false. 
Finally, check if all the nodes of the second tree have a value of -1.
*/

/*
Time Complexity: O( n * n ), where n is the number of nodes in the BST. 
Auxiliary Space: O( h1 + h2 ), where h1 and h2 are the heights of the two trees.
*/

// C++ program to check if two 
// BSTs contain same set of elements
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left, *right;
    Node (int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to append nodes of BST1 into set.
void appendNodes(Node* root, unordered_set<int> &s) {
    if (root == nullptr) return;
    
    s.insert(root->data);
    appendNodes(root->left, s);
    appendNodes(root->right, s);
}

// Recursive function to check if each
// node of BST2 exists in BST1 or not.
bool checkNodes(Node* root, unordered_set<int> &s) {
    if (root == nullptr) return true;
    
    // If current node does not exist in 
    // set, then return false.
    if (s.find(root->data) == s.end()) 
        return false;
    
    // Remove the value from the set     
    s.erase(root->data);
    
    // Recursively check the left and 
    // right subtrees.
    return 
    checkNodes(root->left, s)
    &&
    checkNodes(root->right, s);
}

// Main function to compare two BST.
bool checkBSTs(Node* root1, Node* root2) {
    
    // append node values into set.
    unordered_set<int> s;
    appendNodes(root1, s);
    
    // Check nodes of BST2
    bool ans = checkNodes(root2, s);
    
    // If BST2 does not contain all values
    // of BST1
    if (ans == false) 
        return false;
    
    // If BST2 still contains any value, 
    // then return false. Otherwise return 
    // true.
    return s.empty() == true;
}

int main() {
    
    // Tree 1
    //         15
    //        /  \
    //      10    20
    //     /  \     \
    //    5   12     25
    Node* root1 = new Node(15);
    root1->left = new Node(10);
    root1->right = new Node(20);
    root1->left->left = new Node(5);
    root1->left->right = new Node(12);
    root1->right->right = new Node(25);
    
    // Tree 2
    //         15
    //        /  \
    //      12    20
    //     /       \
    //    5         25
    //     \
    //     10
    Node* root2 = new Node(15);
    root2->left = new Node(12);
    root2->right = new Node(20);
    root2->left->left = new Node(5);
    root2->left->left->right = new Node(10);
    root2->right->right = new Node(25);
    
    if (checkBSTs(root1, root2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    return 0;
}

/*
// In-order function to append 
// nodes of BST into array
void appendNodes(Node* root, vector<int> &arr) {
    if (root == nullptr) return;
    
    appendNodes(root->left, arr);
    arr.push_back(root->data);
    appendNodes(root->right, arr);
}

// Main function to compare two BST.
bool checkBSTs(Node* root1, Node* root2) {
    
    vector<int> arr1, arr2;
    appendNodes(root1, arr1);
    appendNodes(root2, arr2);
    
    // If size of two arrays is not 
    // same, return false.
    if (arr1.size() != arr2.size())
        return false;
        
    for (int i=0; i<arr1.size(); i++) {
        
        // If elements do not match,
        // return false.
        if (arr1[i] != arr2[i]) 
            return false;
    }
    
    return true;
}
*/