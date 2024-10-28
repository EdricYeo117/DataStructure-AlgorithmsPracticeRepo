#include <iostream>
#include <queue>

using namespace std;


class Node { 
    public: 
        int value;
        Node* left;
        Node* right;

    
        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};


class BinarySearchTree {
    public:
        Node* root;

    public:
        BinarySearchTree() { root = nullptr; }


        // ---------------------------------------------------
        //  Helper function used by destructor
        //  Deletes all nodes in BST
        //  Similar to DFS PostOrder in Tree Traversal section
        // ---------------------------------------------------
        void destroy(Node* currentNode) {
            if (currentNode) {
                destroy(currentNode->left);
                destroy(currentNode->right);
                delete currentNode;
            }
        }

        ~BinarySearchTree() { destroy(root); }
 

        void insert(int value) {
            Node* newNode = new Node(value);
            if (root == nullptr) {
                root = newNode;
                return;
            }
            Node* temp = root;
            while(true) {
                if (newNode->value == temp->value) return;
                if (newNode->value < temp->value) {
                    if (temp->left == nullptr) {
                        temp->left = newNode;
                        return;
                    }
                    temp = temp->left;
                } else {
                    if (temp->right == nullptr) {
                        temp->right = newNode;
                        return;
                    }
                    temp = temp->right;
                }
            }
        }

        bool contains(int value) {
            if (root == nullptr) return false;
            Node* temp = root;
            while(temp) {
                if (value < temp->value) {
                    temp = temp->left;
                } else if (value > temp->value) {
                    temp = temp->right;
                } else {
                    return true;
                }
            }
            return false;
        }
        
    // ---------------------------------------------------
    //  Breadth First Search
    // ---------------------------------------------------

void BFS() {    
    // Start BFS from the root node of the tree
    Node* currentNode = root;
    
    // Create a queue to keep track of nodes to visit
    queue<Node*> myQueue;
    myQueue.push(currentNode);
    
    // Loop through the queue until all nodes are visited
    while (!myQueue.empty()) {
        // Get the next node from the front of the queue
        currentNode = myQueue.front();
        myQueue.pop();
    
        // Print the value of the current node
        cout << currentNode->value << " ";
    
        // Add the left child of the current node to the queue if it exists
        if (currentNode->left) {
            myQueue.push(currentNode->left);
        }
    
        // Add the right child of the current node to the queue if it exists
        if (currentNode->right) {
            myQueue.push(currentNode->right);
        }
}
}

    // ---------------------------------------------------
    //  Depth First Search - PreOrder Traversal
    // ---------------------------------------------------

void DFSPreOrder(Node* currentNode) {
    // print current node's value
    cout << currentNode->value << " ";
    // traverse left subtree recursively
    if (currentNode->left != nullptr) {
        // Recursively call the DFSPreOrder function on the left child
        DFSPreOrder(currentNode->left);
    }
    // traverse right subtree recursively
    if (currentNode->right != nullptr) {
        // Recursively call the DFSPreOrder function on the right child
        DFSPreOrder(currentNode->right);
    }
}

void DFSPreOrder() {
    DFSPreOrder(root);
}

    // ---------------------------------------------------
    //  Depth First Search - PostOrder Traversal
    // ---------------------------------------------------

void DFSPostOrder(Node* currentNode) {
    // traverse left subtree recursively
    if (currentNode->left != nullptr) {
        // Recursively call the DFSPostOrder function on the left child
        DFSPostOrder(currentNode->left);
    }
    // traverse right subtree recursively
    if (currentNode->right != nullptr) {
        // Recursively call the DFSPostOrder function on the right child
        DFSPostOrder(currentNode->right);
    }
    // print current node's value
    cout << currentNode->value << " ";
}

void DFSPostOrder() {
    DFSPostOrder(root);
}

    // ---------------------------------------------------
    //  Depth First Search - InOrder Traversal
    // ---------------------------------------------------
    
void DFSInOrder(Node* currentNode) {
    // Check if the left child of the current node exists
    if (currentNode->left != nullptr) {
        // Recursively call the DFSInOrder function on the left child
        DFSInOrder(currentNode->left);
    }
    
    // Print the value of the current node
    cout << currentNode->value << " ";
 
    // Check if the right child of the current node exists
    if (currentNode->right != nullptr) {
        // Recursively call the DFSInOrder function on the right child
        DFSInOrder(currentNode->right);
    }
}

void DFSInOrder() {
    DFSInOrder(root);
}
};

int main() {
    BinarySearchTree* myBST = new BinarySearchTree();

    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(27);
    myBST->insert(52);
    myBST->insert(82);

    cout << "Breadth First Search:\n";
    myBST->BFS();
    cout << "\n";

    cout << "Depth First Search - PreOrder:\n";
    myBST->DFSPreOrder();
    cout << "\n";

    cout << "Depth First Search - InOrder:\n";
    myBST->DFSInOrder();
    cout << "\n";

    cout << "Depth First Search - PostOrder:\n";
    myBST->DFSPostOrder();
    cout << "\n";

    delete myBST;
    return 0;
}

