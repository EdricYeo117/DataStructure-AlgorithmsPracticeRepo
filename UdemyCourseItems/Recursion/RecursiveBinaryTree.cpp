#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree
{
public:
    Node *root;

public:
    BinarySearchTree() { root = nullptr; }

    void destroy(Node *currentNode)
    {
        if (currentNode == nullptr)
            return;
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    Node *getRoot()
    {
        return root;
    }

    bool insert(int value)
    {
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }
        Node *temp = root;
        while (true)
        {
            if (newNode->value == temp->value)
                return false;
            if (newNode->value < temp->value)
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                temp = temp->right;
            }
        }
    }

    // Recursive check for the presence of a value in the tree.
    bool rContains(Node *currentNode, int value)
    {
        // Check if the current node is null. If it is, the value
        // is not present in the tree, and we return false.
        if (currentNode == nullptr)
            return false;

        // If the current node's value matches the search value,
        // return true to indicate the value is found in the tree.
        if (currentNode->value == value)
            return true;

        // Determine the direction to continue the search based on
        // the value comparison. If the search value is less than
        // the current node's value, search in the left subtree.
        if (value < currentNode->value)
        {
            return rContains(currentNode->left, value);
        }
        else
        {
            // If the search value is greater than or equal to the
            // current node's value, search in the right subtree.
            return rContains(currentNode->right, value);
        }
    }

    bool rContains(int value)
    {
        return rContains(root, value);
    }

    // Recursive function to insert a value into the tree.
    Node *rInsert(Node *currentNode, int value)
    {
        // Base case: If the current node is null, a new node
        // with the given value is created and returned. This
        // becomes a leaf in the tree.
        if (currentNode == nullptr)
            return new Node(value);

        // If the value to insert is less than the current node's value,
        // proceed to insert the value into the left subtree. The
        // connection to the left child is updated in case a new node is
        // created (when the left child is null).
        if (value < currentNode->value)
        {
            currentNode->left = rInsert(currentNode->left, value);
        }
        else if (value > currentNode->value)
        {
            // If the value is greater than the current node's value,
            // insert the value into the right subtree, similarly
            // updating the connection to the right child.
            currentNode->right = rInsert(currentNode->right, value);
        }
        // If the value is equal to the current node's value, we do nothing.
        // The tree remains unchanged, effectively not allowing duplicate
        // values in this BST implementation.

        // Return the current node to link back up the recursive call stack.
        // This ensures the structure of the tree is maintained after insertion.
        return currentNode;
    }

    void rInsert(int value)
    {
        if (root == nullptr)
            root = new Node(value);
        rInsert(root, value);
    }

    int minValue(Node *currentNode)
    {
        // Loop to move left down the tree. The smallest value
        // in a BST is found at the leftmost node because in a
        // BST, any node's left child is less than the node itself.
        while (currentNode->left != nullptr)
        {
            // Update the current node to its left child,
            // moving closer to the leftmost (and thus
            // smallest) node.
            currentNode = currentNode->left;
        }
        // Once the leftmost node is reached (no further left
        // children), return the value of this node, which is
        // the minimum value in the tree.
        return currentNode->value;
    }

    // Recursive funciton to delete a node with a given value.
   Node* deleteNode(Node* currentNode, int value) { 
    // Base case: If the current node is null, return null.
    // This happens when the value is not found in the tree.
    if (currentNode == nullptr) return nullptr;
 
    // Search for the node to delete.
    if (value < currentNode->value) { 
        // If value is less than current node's value,
        // go left in the tree.
        currentNode->left = deleteNode(currentNode->left, value);
    } else if (value > currentNode->value) { 
        // If value is greater, go right in the tree.
        currentNode->right = deleteNode(currentNode->right, value);
    } else {
        // Node with the value found. Handle deletion.
        if (currentNode->left == nullptr && currentNode->right == nullptr) { 
            // Case 1: No children. Simply delete the node and return null.
            delete(currentNode);
            return nullptr;
        } else if (currentNode->left == nullptr) { 
            // Case 2: One child (right). Bypass the node.
            Node* temp = currentNode->right;
            delete(currentNode);
            return temp; // Return the non-null child.
        } else if (currentNode->right == nullptr) { 
            // Case 3: One child (left). Similar bypass.
            Node* temp = currentNode->left;
            delete(currentNode);
            return temp;
        } else { 
            // Case 4: Two children. Find the minimum value in the
            // right subtree, copy the value to the current node,
            // and delete the duplicate from the right subtree.
            int subTreeMin = minValue(currentNode->right);
            currentNode->value = subTreeMin;
            currentNode->right = deleteNode(currentNode->right, subTreeMin);
        }
    }
    // Return the current (possibly updated) node.
    return currentNode;
}

    void deleteNode(int value)
    {
        // root = nullptr; when leaf node.
        root = deleteNode(root, value);
    }
};

void inOrderTraversal(Node *node)
{
    if (node == nullptr)
        return;

    // Traverse left subtree
    inOrderTraversal(node->left);

    // Visit node
    cout << node->value << " ";

    // Traverse right subtree
    inOrderTraversal(node->right);
}



int main()
{
    // Create a binary search tree
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    // Test rContains method
    cout << "Contains 40? " << (bst.rContains(40) ? "Yes" : "No") << endl; // Should print Yes
    cout << "Contains 25? " << (bst.rContains(25) ? "Yes" : "No") << endl; // Should print No

    // Test deleteNode method
    cout << "Deleting 20\n";
    bst.deleteNode(20);
    cout << "Contains 20? " << (bst.rContains(20) ? "Yes" : "No") << endl; // Should print No

    cout << "Deleting 30\n";
    bst.deleteNode(30);
    cout << "Contains 30? " << (bst.rContains(30) ? "Yes" : "No") << endl; // Should print No

    cout << "Deleting 50\n";
    bst.deleteNode(50);
    cout << "Contains 50? " << (bst.rContains(50) ? "Yes" : "No") << endl; // Should print No

    // Final state of BST (in-order traversal)
    cout << "Final state of BST:\n";
    inOrderTraversal(bst.getRoot());
    cout << endl;

    return 0;
}