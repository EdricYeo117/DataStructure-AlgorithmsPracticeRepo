#include <iostream>
using namespace std;

struct ListNode {
    int data;
    ListNode* next;
    ListNode(int x) : data(x), next(nullptr) {}
};

void deleteNNodesAfterMNodes(ListNode* head, int m, int n) {
    // If the list is empty, return immediately
    if (head == nullptr) {
        return;
    }

    // Initialize current node pointer
    ListNode* current = head;

    // Loop through the list to perform the skip and delete operations
    while (current) {
        // Step 1: Skip M nodes
        for (int i = 0; i < m && current; ++i) {
            current = current->next; // Move current forward M times
        }
        
        // If we reach the end of the list, return as there are no more nodes to process
        if (current == nullptr) {
            return;
        }

        // Step 2: Delete N nodes
        // Set a temporary pointer to the node after the M-th node
        ListNode* temp = current->next;
        for (int i = 0; i < n && temp != nullptr; ++i) {
            ListNode* nodeToDelete = temp; // Identify the node to delete
            temp = temp->next; // Move temp to the next node
            delete nodeToDelete; // Delete the identified node
        }

        // Step 3: Link the current node (M-th node) to the node after the deleted nodes
        current->next = temp;

        // Move current to the next M nodes (if available)
        current = temp;
    }
}
