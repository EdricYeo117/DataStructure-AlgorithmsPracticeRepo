#include <iostream>
using namespace std;

// Definition of a Node in the singly linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize a new node with given data
    Node(int new_data) {
        data = new_data;
        next = nullptr; // Initially, the next pointer is set to null
    }
};

/*
    Function: searchIterative
    -------------------------
    Searches for a given key in the linked list using an iterative approach.

    Parameters:
        head : Pointer to the head of the linked list.
        key  : The integer value to search for in the list.

    Returns:
        true  - If the key is found in the list.
        false - If the key is not found in the list.

    Time Complexity:
        O(n) - In the worst case, where n is the number of nodes in the list,
              the function may need to traverse the entire list.

    Space Complexity:
        O(1) - Only a constant amount of extra space is used regardless of the list size.
*/
bool searchIterative(Node* head, int key) {
    Node* current = head; // Initialize a pointer to traverse the list starting from head

    // Traverse the linked list
    while (current != nullptr) {
        // If the current node's data matches the key, return true
        if (current->data == key) {
            return true; // Key found
        }
        // Move to the next node in the list
        current = current->next;
    }

    // If the key was not found after traversing the entire list, return false
    return false;
}

/*
    Function: searchRecursive
    -------------------------
    Searches for a given key in the linked list using a recursive approach.

    Parameters:
        head : Pointer to the head of the linked list.
        key  : The integer value to search for in the list.

    Returns:
        true  - If the key is found in the list.
        false - If the key is not found in the list.

    Time Complexity:
        O(n) - In the worst case, where n is the number of nodes in the list,
              the function may need to traverse the entire list recursively.

    Space Complexity:
        O(n) - Due to recursive function calls, the space used grows linearly with the list size.
*/
bool searchRecursive(Node* head, int key) {
    // Base case: If the current node is null, the key is not found
    if (head == nullptr) {
        return false;
    }

    // If the current node's data matches the key, return true
    if (head->data == key) {
        return true; // Key found
    }

    // Recursively search in the next node
    return searchRecursive(head->next, key);
}