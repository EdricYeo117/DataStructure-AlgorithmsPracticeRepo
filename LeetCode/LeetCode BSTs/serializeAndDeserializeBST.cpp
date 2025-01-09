/*
Serialization is converting a data structure or object into a sequence of bits 
so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later
 in the same or another computer environment.

 Approach:
 1) Serialisation 
    - Traverse the tree in preorder (root-> left -> right)
    - Convert each node value to a string and append it to the result, seperated by delimiter
    - Use a placeholder to preserve tree structure

 2) Deserialisation
    - Split the serialised string into individual node values 
    - Use recursive approach to reconstruct the tree
       - If the current node value is a placeholder, return null
         - Create a new node with the current value

Time Complexity : O(N) where N is the number of nodes in the tree
Space Complexity : O(N) where N is the number of nodes in the tree
*/

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Codec {
private: 
    TreeNode* buildTree(queue<string> &nodes) {
        // Base case : Empty node
        if(nodes.empty()) return nullptr;

        // Get the next value from the queue
        string val = nodes.front();
        nodes.pop();

        // If the value is a placeholder, return null
        if(val == "null") return nullptr;

        // Create a new node with the current value
        TreeNode* newNode = new TreeNode(stoi(val));
        // Recursively build the left and right subtrees
        newNode->left = buildTree(nodes);
        newNode->right = buildTree(nodes);

        return newNode;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // Base case : Null node
        if(root == NULL) return "null";

        // Predorder traversal (root -> left -> right)
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Queue to store the node values
        queue<string> nodes;
        // Split the string into individual node values
        stringstream ss(data);
        // String to store the current node value
        string item;

        // Split the serialised string into individual node values
        while(getline(ss, item, ',')){
            nodes.push(item);
        }
        
        // Helper function to construct the tree recursively 
        return buildTree(nodes);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;