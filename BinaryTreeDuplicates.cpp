#include <iostream>
#include <queue>
using namespace std;

// Tree Node Structure with Duplicate Handling
struct TreeNode {
    int data;
    int count; // Count occurrences of the value
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), count(1), left(nullptr), right(nullptr) {}
};

// --- Traversals ---

// In-order Traversal (Left, Root, Right)
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);
    for (int i = 0; i < root->count; i++) {
        cout << root->data << " ";
    }
    inorderTraversal(root->right);
}

// Pre-order Traversal (Root, Left, Right)
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    for (int i = 0; i < root->count; i++) {
        cout << root->data << " ";
    }
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Post-order Traversal (Left, Right, Root)
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    for (int i = 0; i < root->count; i++) {
        cout << root->data << " ";
    }
}

// Level-Order Traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        for (int i = 0; i < current->count; i++) {
            cout << current->data << " ";
        }

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// --- Search ---
bool searchBST(TreeNode* root, int key) {
    if (root == nullptr) return false;

    if (key == root->data) return true;
    else if (key < root->data) return searchBST(root->left, key);
    else return searchBST(root->right, key);
}

// --- Insertion with Duplicate Handling ---
TreeNode* insertBST(TreeNode* root, int key) {
    if (root == nullptr) return new TreeNode(key);

    if (key == root->data) {
        root->count++; // Increment count for duplicates
    } else if (key < root->data) {
        root->left = insertBST(root->left, key);
    } else {
        root->right = insertBST(root->right, key);
    }

    return root;
}

// --- Deletion with Duplicate Handling ---
TreeNode* deleteBST(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    } else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    } else {
        // Handle duplicate count
        if (root->count > 1) {
            root->count--;
            return root;
        }

        // Case 1: Leaf Node
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        // Case 2: One Child
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two Children
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->count = temp->count;
        temp->count = 1;
        root->right = deleteBST(root->right, temp->data);
    }

    return root;
}

// --- Find Minimum Node ---
TreeNode* findMin(TreeNode* node) {
    while (node && node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// --- Find Maximum Node ---
TreeNode* findMax(TreeNode* node) {
    while (node && node->right != nullptr) {
        node = node->right;
    }
    return node;
}

// --- Floor in BST ---
TreeNode* findFloor(TreeNode* root, int key) {
    TreeNode* floorNode = nullptr;

    while (root != nullptr) {
        if (key == root->data) {
            return root;
        } else if (key < root->data) {
            root = root->left;
        } else {
            floorNode = root;
            root = root->right;
        }
    }

    return floorNode;
}

// --- Ceiling in BST ---
TreeNode* findCeiling(TreeNode* root, int key) {
    TreeNode* ceilingNode = nullptr;

    while (root != nullptr) {
        if (key == root->data) {
            return root;
        } else if (key > root->data) {
            root = root->right;
        } else {
            ceilingNode = root;
            root = root->left;
        }
    }

    return ceilingNode;
}

// --- Find Inorder Predecessor ---
TreeNode* findPredecessor(TreeNode* root, TreeNode* target) {
    if (target->left != nullptr) {
        return findMax(target->left);
    }

    TreeNode* predecessor = nullptr;
    TreeNode* current = root;

    while (current != nullptr) {
        if (target->data > current->data) {
            predecessor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    return predecessor;
}

// --- Find Inorder Successor ---
TreeNode* findSuccessor(TreeNode* root, TreeNode* target) {
    if (target->right != nullptr) {
        return findMin(target->right);
    }

    TreeNode* successor = nullptr;
    TreeNode* current = root;

    while (current != nullptr) {
        if (target->data < current->data) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return successor;
}

// --- Main Function ---
int main() {
    TreeNode* root = nullptr;

    root = insertBST(root, 10);
    root = insertBST(root, 5);
    root = insertBST(root, 20);
    root = insertBST(root, 10); // Duplicate

    cout << "In-order Traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Deleting 10..." << endl;
    root = deleteBST(root, 10);
    inorderTraversal(root);
    cout << endl;

    cout << "Level-order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
