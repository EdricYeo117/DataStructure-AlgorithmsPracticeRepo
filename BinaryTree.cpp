#include <iostream>
#include <queue>
using namespace std;

// Define the structure of a Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// In-order Traversal Function
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    // 1) Traverse left subtree
    inorderTraversal(root->left);
    
    // 2) Visit current node
    cout << root->data << " ";
    
    // 3) Traverse right subtree
    inorderTraversal(root->right);
}

// Pre-order Traversal Function
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Visit the root node
    cout << root->data << " ";
    
    // Traverse the left subtree
    preorderTraversal(root->left);
    
    // Traverse the right subtree
    preorderTraversal(root->right);
}

// Post-order Traversal Function
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // Traverse the left subtree
    postorderTraversal(root->left);
    
    // Traverse the right subtree
    postorderTraversal(root->right);
    
    // Visit the root node
    cout << root->data << " ";
}

// Level-Order Traversal Function
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    // Use a queue to hold nodes at each level
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        // Print the current node's data
        cout << current->data << " ";
        
        // Enqueue left child if it exists
        if (current->left != nullptr) {
            q.push(current->left);
        }
        
        // Enqueue right child if it exists
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
}

// Search for a key in a Binary Search Tree
bool searchBST(TreeNode* root, int key) {
    if (root == nullptr) {
        return false; // Key not found
    }

    if (root->data == key) {
        return true; // Key found
    }

    if (key < root->data) {
        return searchBST(root->left, key); // Search left subtree
    } else {
        return searchBST(root->right, key); // Search right subtree
    }
}

// Insert Function in BST
TreeNode* insertBST(TreeNode* root, int key) {
    // If the tree is empty, create a new node
    if (root == nullptr) {
        return new TreeNode(key);
    }

    // If the key is smaller, go to the left subtree
    if (key < root->data) {
        root->left = insertBST(root->left, key);
    }
    // If the key is larger, go to the right subtree
    else if (key > root->data) {
        root->right = insertBST(root->right, key);
    }
    
    // Return the unchanged root node
    return root;
}

// Find the Inorder Successor (Smallest node in the right subtree)
TreeNode* findMin(TreeNode* node) {
    if (node == nullptr) {
        return nullptr; // Empty subtree
    }

    TreeNode* current = node;
    while (current->left != nullptr) {
        current = current->left; // Keep moving left
    }

    return current; // Return the leftmost node
}

// Find Maximum Value in BST
TreeNode* findMax(TreeNode* node) {
    if (node == nullptr) {
        return nullptr; // Empty subtree
    }

    TreeNode* current = node;
    while (current->right != nullptr) {
        current = current->right; // Keep moving right
    }

    return current; // Return the rightmost node
}

// Find Floor in BST
TreeNode* findFloor(TreeNode* root, int key) {
    TreeNode* floorNode = nullptr;

    while (root != nullptr) {
        if (root->data == key) {
            // Exact match, this is the floor
            return root;
        } 
        else if (key < root->data) {
            // Move to the left subtree
            root = root->left;
        } 
        else {
            // Store the current node as a potential floor
            floorNode = root;
            // Move to the right subtree
            root = root->right;
        }
    }

    return floorNode;
}

// Find Ceiling in BST
TreeNode* findCeiling(TreeNode* root, int key) {
    TreeNode* ceilingNode = nullptr;

    while (root != nullptr) {
        if (root->data == key) {
            // Exact match, this is the ceiling
            return root;
        } 
        else if (key > root->data) {
            // Move to the right subtree
            root = root->right;
        } 
        else {
            // Store the current node as a potential ceiling
            ceilingNode = root;
            // Move to the left subtree
            root = root->left;
        }
    }

    return ceilingNode;
}

// Find Inorder Predecessor in BST
TreeNode* findPredecessor(TreeNode* root, TreeNode* target) {
    if (target == nullptr) return nullptr;

    // Case 1: Node has a left subtree
    if (target->left != nullptr) {
        return findMax(target->left);
    }

    // Case 2: Node does not have a left subtree
    TreeNode* predecessor = nullptr;
    TreeNode* current = root;

    while (current != nullptr) {
        if (target->data > current->data) {
            predecessor = current; // Update predecessor
            current = current->right;
        } else if (target->data < current->data) {
            current = current->left;
        } else {
            break;
        }
    }

    return predecessor;
}

// Find Inorder Successor in BST
TreeNode* findSuccessor(TreeNode* root, TreeNode* target) {
    if (target == nullptr) return nullptr;

    // Case 1: Node has a right subtree
    if (target->right != nullptr) {
        return findMin(target->right);
    }

    // Case 2: Node does not have a right subtree
    TreeNode* successor = nullptr;
    TreeNode* current = root;

    while (current != nullptr) {
        if (target->data < current->data) {
            successor = current; // Update successor
            current = current->left;
        } else if (target->data > current->data) {
            current = current->right;
        } else {
            break;
        }
    }

    return successor;
}

// Delete Node in BST
TreeNode* deleteBST(TreeNode* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }

    // Search for the node
    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    } else {
        // **Case 1: Leaf Node**
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // **Case 2: One Child**
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // **Case 3: Two Children**
        TreeNode* temp = findMin(root->right); // Find Inorder Successor
        root->data = temp->data; // Copy value
        root->right = deleteBST(root->right, temp->data); // Delete successor
    }

    return root;
}

int main() {
    // Construct the tree from your diagram
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(10);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(3);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(11);

    cout << "Pre-order Traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
