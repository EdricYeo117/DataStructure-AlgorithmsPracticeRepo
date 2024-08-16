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
        if (currentNode->left)
            destroy(currentNode->left);
        if (currentNode->right)
            destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    // Insert a value in the BST
    bool insert(int value)
    {
        // Creating a new node with the given value
        Node *newNode = new Node(value);

        // If the tree is empty, make the new node the root
        if (root == nullptr)
        {
            root = newNode;
            return true;
        }

        // Start from the root for the insertion process
        Node *temp = root;

        // Infinite loop to find the correct position for newNode
        while (true)
        {
            // If value already exists in the tree, return false
            if (newNode->value == temp->value)
                return false;

            // If value is less than current node's value
            if (newNode->value < temp->value)
            {
                // If left child is null, insert newNode there
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                    return true;
                }
                // Move to left child for the next iteration
                temp = temp->left;
            }
            else
            {
                // If right child is null, insert newNode there
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                    return true;
                }
                // Move to right child for the next iteration
                temp = temp->right;
            }
        }
    }

    // Search for a value in the BST
    // Check if the BST contains a node with the specified integer value
    bool contains(int value)
    {
        // If the BST is empty, return false
        if (root == nullptr)
            return false;

        // Create a temp node pointer, initializing it to the root
        Node *temp = root;

        // Loop that continues while temp is not null
        while (temp)
        {
            // If value to search is less than current node's value
            if (value < temp->value)
            {
                // Move to the left child
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                // If value to search is greater than current node's value
                // Move to the right child
                temp = temp->right;
            }
            else
            {
                // If value to search equals current node's value
                // Return true
                return true;
            }
        }
        // If value is not found in the tree, return false
        return false;
    }

    // Delete a value from the BST
    // This function finds the node with the minimum value in a subtree.
    Node *minValueNode(Node *node)
    {
        Node *current = node;

        // Traverse the left subtree to find the leftmost node (smallest value)
        while (current && current->left != nullptr)
            current = current->left;

        return current; // Return the node with the minimum value
    }

    // This function deletes a node with the specified value from the BST.
    Node *deleteNode(Node *root, int value)
    {
        // Base case: If the tree is empty or the node to be deleted is not found
        if (root == nullptr)
            return root;

        // If the value to be deleted is smaller than the root's value,
        // then it lies in the left subtree
        if (value < root->value)
            root->left = deleteNode(root->left, value);
        // If the value to be deleted is greater than the root's value,
        // then it lies in the right subtree
        else if (value > root->value)
            root->right = deleteNode(root->right, value);
        // If the value matches the root's value, this is the node to be deleted
        else
        {
            // Case 1: Node with only one child or no child

            // If the left child is null, return the right child
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root; // Delete the current node
                return temp; // Return the right child to connect it to the parent
            }
            // If the right child is null, return the left child
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root; // Delete the current node
                return temp; // Return the left child to connect it to the parent
            }

            // Case 2: Node with two children
            // Get the inorder successor (smallest value in the right subtree)
            Node *temp = minValueNode(root->right);

            // Copy the inorder successor's value to this node
            root->value = temp->value;

            // Delete the inorder successor since its value is now copied
            root->right = deleteNode(root->right, temp->value);
        }

        return root; // Return the (potentially new) root to the caller
    }

    // This function starts the deletion process from the root of the tree.
    void deleteValue(int value)
    {
        root = deleteNode(root, value); // Initiate the deletion from the root
    }
};

int main()
{

    BinarySearchTree *myBST = new BinarySearchTree();

    // ROOT MUST BE PUBLIC FOR THIS LINE TO WORK:
    cout << "Root: " << myBST->root;

    /*
        EXPECTED OUTPUT:
        ----------------
        Root: 0x0

    */
}
