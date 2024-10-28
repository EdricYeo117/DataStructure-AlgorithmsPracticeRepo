#include <bits/stdc++.h>
using namespace std;

// Definition of a Node in the singly linked list
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize a new node with given data
    Node(int new_data) {
        data = new_data;
        next = nullptr; // Initially, the next pointer is set to null
    }
};

// Function to insert a new node at the beginning of the list
// Parameters:
// - head: Pointer to the current head of the list
// - new_data: The data value for the new node
// Returns:
// - Pointer to the new head of the list
Node* insertAtFront(Node* head, int new_data) {
    // Allocate memory for the new node and initialize it with new_data
    Node* new_node = new Node(new_data);

    // Link the new node to point to the current head
    new_node->next = head;

    // The new node becomes the new head of the list
    return new_node;
}

// Function to insert a new node after a node containing the specified key
// Parameters:
// - head: Pointer to the head of the list
// - key: The data value after which the new node should be inserted
// - newData: The data value for the new node
// Returns:
// - Pointer to the head of the list (unchanged if key not found)
Node* insertAfter(Node* head, int key, int newData) {
    // Initialize a pointer to traverse the list starting from head
    Node* curr = head;

    // Traverse the list to find the node with data equal to key
    while (curr != nullptr) {
        if (curr->data == key)
            break; // Key found; exit the loop
        curr = curr->next; // Move to the next node
    }

    // If the key was not found in the list, return the original head
    if (curr == nullptr)
        return head;

    // Allocate memory for the new node and initialize it with newData
    Node* newNode = new Node(newData);

    // Link the new node to the next node of the current node
    newNode->next = curr->next;

    // Link the current node to the new node, effectively inserting it after current
    curr->next = newNode;

    // Return the head of the list (unchanged)
    return head;
}

// Function to insert a new node before a node containing the specified key
// Parameters:
// - head: Pointer to the head of the list
// - key: The data value before which the new node should be inserted
// - newData: The data value for the new node
// Returns:
// - Pointer to the head of the list (updated if insertion is at the head)
Node* insertBeforeKey(Node* head, int key, int newData) {
    // If the list is empty, there's nothing to insert before
    if (head == nullptr) {
        return nullptr;
    }

    // Special case: if the key is found at the head of the list
    if (head->data == key) {
        // Create a new node and link it before the current head
        Node* new_node = new Node(newData);
        new_node->next = head;
        return new_node; // New node becomes the new head
    }

    // Initialize pointers to traverse the list
    Node* curr = head;    // Current node being examined
    Node* prev = nullptr; // Previous node to keep track of the node before current

    // Traverse the list to find the node with data equal to key
    while (curr != nullptr && curr->data != key) {
        prev = curr;       // Update previous to current before moving forward
        curr = curr->next; // Move to the next node
    }

    // If the key was found in the list
    if (curr != nullptr) {
        // Allocate memory for the new node and initialize it with newData
        Node* new_node = new Node(newData);

        // Link the previous node to the new node
        prev->next = new_node;

        // Link the new node to the current node, effectively inserting it before current
        new_node->next = curr;
    }

    // If the key was not found, the list remains unchanged
    return head;
}

// Function to insert a new node at a specific position in the list
// Parameters:
// - head: Pointer to the head of the list
// - position: The position at which to insert the new node (1-based index)
// - data: The data value for the new node
// Returns:
// - Pointer to the head of the list (updated if insertion is at the head)
Node* insertAtPosition(Node* head, int position, int data) {
    // Create a new node with the specified data
    Node* newNode = new Node(data);

    // If inserting at the beginning (position 1)
    if (position == 1) {
        newNode->next = head; // Link new node to current head
        head = newNode;       // Update head to the new node
        return head;
    }

    // Initialize a pointer to traverse the list
    Node* current = head;

    // Traverse the list to find the node just before the desired position
    for (int i = 1; i < position - 1 && current != nullptr; ++i) {
        current = current->next; // Move to the next node
    }

    // If current is nullptr, the position is out of bounds
    if (current == nullptr) {
        cout << "Position is out of bounds." << endl;
        
        // Deallocate the newly created node to prevent memory leaks
        delete newNode; 
                           
        return head; // Return the original head without changes
    }

    // Link the new node to the next node in the list
    newNode->next = current->next;

    // Link the current node to the new node, inserting it at the desired position
    current->next = newNode;

    // Return the head of the list (unchanged)
    return head;
}

// Function to insert a new node at the end of the list
// Parameters:
// - head: Pointer to the head of the list
// - new_data: The data value for the new node
// Returns:
// - Pointer to the head of the list (updated if the list was empty)
Node* insertAtEnd(Node* head, int new_data) {
    // Create a new node with the specified data
    Node* new_node = new Node(new_data);

    // If the linked list is empty, the new node becomes the head
    if (head == nullptr) {
        return new_node;
    }

    // Initialize a pointer to traverse the list starting from head
    Node* last = head;

    // Traverse the list to reach the last node (where next is nullptr)
    while (last->next != nullptr) {
        last = last->next; // Move to the next node
    }

    // Link the last node to the new node, effectively appending it
    last->next = new_node;

    // The new node is now the last node, so its next remains nullptr

    // Return the head of the list (unchanged)
    return head;
}