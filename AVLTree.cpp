#include <iostream>
#include <algorithm> // For max()
using namespace std;

// Node structure for AVL Tree
struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
};

// Utility Function: Get the height of a node
int height(Node* node) {
    return (node == nullptr) ? 0 : node->height;
}

// Utility Function: Get the balance factor of a node
int getBalance(Node* node) {
    return (node == nullptr) ? 0 : height(node->left) - height(node->right);
}

// Utility Function: Perform Right Rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    // Return new root
    return x;
}

// Utility Function: Perform Left Rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    // Return new root
    return y;
}

// Recursive Function to Insert a Key in the AVL Tree
Node* insert(Node* node, int key) {
    // 1. Perform standard BST insertion
    if (node == nullptr)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    // 2. Update height of the current node
    node->height = 1 + max(height(node->left), height(node->right));

    // 3. Get the balance factor
    int balance = getBalance(node);

    // 4. Handle Imbalance Cases

    // **Left-Left (LL) Case**
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // **Right-Right (RR) Case**
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // **Left-Right (LR) Case**
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // **Right-Left (RL) Case**
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// Utility Function: Find the Node with the Minimum Key in a Tree
Node* findMin(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Recursive Function to Delete a Node in AVL Tree
Node* deleteNode(Node* root, int key) {
    // Step 1: Perform standard BST deletion
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp; // Copy the contents of the non-empty child
            }
            delete temp;
        } else {
            // Node with two children: Get inorder successor (smallest in right subtree)
            Node* temp = findMin(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    // Step 2: Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Step 3: Check balance and perform rotations if necessary
    int balance = getBalance(root);

    // **Left-Left (LL) Case**
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // **Left-Right (LR) Case**
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // **Right-Right (RR) Case**
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // **Right-Left (RL) Case**
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Preorder Traversal
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Main Function
int main() {
    Node* root = nullptr;

    // Insert nodes into AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder Traversal after insertion:\n";
    preOrder(root);
    cout << endl;

    // Delete a node from AVL tree
    root = deleteNode(root, 40);

    cout << "Preorder Traversal after deleting 40:\n";
    preOrder(root);
    cout << endl;

    return 0;
}
