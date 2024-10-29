#include <bits/stdc++.h>
using namespace std;

// A structure to represent a node in the stack
class StackNode {
public:
    int data;           // Data stored in the stack node
    StackNode* next;    // Pointer to the next node in the stack

    // Constructor to initialize a stack node with given data
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    StackNode(int data) : data(data), next(nullptr) {}
};

// Stack class to manage stack operations
class Stack {
private:
    StackNode* root;    // Pointer to the top node in the stack

public:
    // Constructor to initialize an empty stack
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    Stack() : root(nullptr) {}

    // Destructor to free all nodes in the stack
    // Time Complexity: O(n), where n is the number of nodes in the stack
    // Space Complexity: O(1)
    ~Stack() {
        while (root) {
            StackNode* temp = root;
            root = root->next;
            delete temp;  // Delete each node in the stack
        }
    }

    // Function to check if the stack is empty
    // Pre: None
    // Post: Returns true if the stack is empty; otherwise, false.
    // Time Complexity: O(1)
    // Space Complexity: O(1)
    bool isEmpty() const {
        return root == nullptr;
    }

    // Function to push a new element onto the stack
    // Pre: None
    // Post: A new element is added to the top of the stack.
    //       The size of the stack increases by 1.
    // Time Complexity: O(1) - Constant time as it only adds a single node at the top
    // Space Complexity: O(1) - Only a single pointer is allocated for the new node
    
    void push(int data) {
        StackNode* stackNode = new StackNode(data); // Create a new node
        stackNode->next = root;                     // Link new node to the top of the stack
        root = stackNode;                           // Update root to the new node
        cout << data << " pushed to stack\n";       // Output the pushed element
    }

    // Function to pop the top element from the stack
    // Pre: Stack is not empty.
    // Post: The top element is removed from the stack.
    //       The size of the stack decreases by 1.
    //       Returns the data of the popped element.
    // Time Complexity: O(1) - Constant time as it only removes a single node from the top
    // Space Complexity: O(1) - Only temporary storage for a pointer is needed
    int pop() {
        if (isEmpty()) {                            // Check if stack is empty
            cout << "Stack is empty\n";
            return INT_MIN;                         // Return a minimum integer if stack is empty
        }
        StackNode* temp = root;                     // Store the current top node in temp
        root = root->next;                          // Move root to the next node in the stack
        int popped = temp->data;                    // Retrieve the data of the popped node
        delete temp;                                // Delete the popped node
        return popped;                              // Return the popped element's data
    }

    // Function to get the top element of the stack without popping it
    // Pre: Stack is not empty.
    // Post: Returns the data of the top element without modifying the stack.
    // Time Complexity: O(1) - Constant time as it only accesses the top element
    // Space Complexity: O(1) - No extra space required
    int peek() const {
        if (isEmpty()) {                            // Check if stack is empty
            cout << "Stack is empty\n";
            return INT_MIN;                         // Return a minimum integer if stack is empty
        }
        return root->data;                          // Return data of the top element
    }

    /*
        Function: append
        Purpose: Add an item to the back of the stack (treated as a list).
        Parameters:
            - data: The integer value to be appended at the end.
        Pre: None.
        Post: The item is added to the end of the stack, increasing the size by 1.
        Time Complexity: O(n) - Linear time as it may need to traverse the entire stack to find the end.
        Space Complexity: O(1) - Only a single pointer is allocated for the new node.
    */
    void append(int data) {
        StackNode* newNode = new StackNode(data);  // Create a new node with the specified data

        if (isEmpty()) {                            // If the stack is empty, the new node becomes the root
            root = newNode;
            cout << data << " appended to stack\n";
            return;
        }

        StackNode* current = root;                  // Initialize 'current' to start at the root of the stack

        // Traverse to the last node in the stack
        while (current->next != nullptr) {
            current = current->next;                // Move to the next node
        }

        current->next = newNode;                     // Link the last node to the new node
        cout << data << " appended to stack\n";       // Output the appended element
    }
}