/*
Given a singly linked list. The task is to remove duplicates (nodes with duplicate values) from the given list (if it exists).
Note: Try not to use extra space. The nodes are arranged in a sorted way
*/
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = nullptr;
  }
};

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        // Check if the list is empty or has only one node
        if (!head || !head->next) {
            return head;
        }

        // Start with the head node
        Node* current = head;

        // Traverse the list
        while (current && current->next) {
            // Check if the current node and the next node have same value
            while (current->next && current->data == current->next->data) {
                // Duplicate found, so skip node
                Node* temp = current->next;     // Temporary pointer to the duplicate node
                current->next = current->next->next; // Bypass the duplicate node
                delete temp;
            }
                current = current->next;
        }
        return head;
    }
};