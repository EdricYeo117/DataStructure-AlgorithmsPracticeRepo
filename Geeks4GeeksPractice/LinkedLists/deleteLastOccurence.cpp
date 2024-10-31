// C++ program to delete last occurrence 
// of key in singly linked list

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* deleteLastOccurence(Node* head, int key) {
     // Initialize pointers to track the last occurrence of the key and its previous node
    Node* last = nullptr;         // Pointer to the last occurrence of key
    Node* lastPrev = nullptr;     // Pointer to the node before the last occurrence
    Node* current = head;         // Pointer to traverse the list
    Node* prev = nullptr;         // Pointer to keep track of the previous node during traversal

    // Traverse the list to find the last occurrence of key
    while (current != nullptr) {
        // Check if the current node contains the key
        if (current->data == key) {
            // Update lastPrev and last pointers to track the last occurrence of the key
            lastPrev = prev;
            last = current;
        }
        // Move prev to current and current to the next node in the list
        prev = current;
        current = current->next;
    }

    // If the key was found, last not nullptr
    if (last != nullptr) {
        // Check if the last occurrence is not the head
        if (last != head) {
            // Delete the last occurrence by bypassing it in list
            lastPrev->next = last->next;
        } else {
            // If last occurrence is head, update head to the next node
            head = head->next;
        }
        // Delete the last occurrence node, free memory
        delete last;
    }
    return head;
}