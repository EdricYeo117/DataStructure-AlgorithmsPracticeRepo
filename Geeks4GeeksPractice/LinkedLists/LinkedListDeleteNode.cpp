// C++ program to delete a linked list node at a given
// position
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node(int data)
        : data(data)
        , next(nullptr)
    {
    }
};

/*
    Function: deleteNode
    --------------------
    Deletes a node from the linked list at the specified position.
    
    Parameters:
        - head (Node*): Pointer to the head node of the linked list.
        - position (int): The 1-based position of the node to be deleted.
    
    Returns:
        - Node*: Pointer to the head of the modified linked list after deletion.
    
    Time Complexity:
        O(n) - In the worst case, where n is the number of nodes in the list, the function traverses the entire list.
    
    Space Complexity:
        O(1) - Uses a constant amount of extra space.
    
    Steps:
        1. Initialize two pointers: 'prev' (to keep track of the previous node) and 'temp' (to traverse the list).
        2. Check if the linked list is empty. If it is, return the head as is.
        3. If the position to delete is 1, delete the head node:
            a. Update the head to point to the next node.
            b. Free the memory of the old head node.
            c. Return the new head.
        4. Traverse the list to reach the node just before the desired position:
            a. Loop from 1 to (position - 1), moving 'prev' and 'temp' forward.
        5. After traversal, check if the node at the desired position exists:
            a. If 'temp' is not nullptr, unlink the node from the list and free its memory.
            b. If 'temp' is nullptr, the position is out of bounds. Output an error message.
        6. Return the head of the modified linked list.
*/
Node* deleteNode(Node* head, int position)
{
    Node* prev;      // Pointer to store the previous node
    Node* temp = head; // Temporary pointer initialized to head

    // Base case: If the linked list is empty, return the head as is
    if (temp == NULL)
        return head;

    // Case 1: If the head needs to be deleted (position == 1)
    if (position == 1) {
        // Update the head to point to the next node
        head = temp->next;
        
        // Free the memory allocated for the old head node
        free(temp);
        
        // Return the updated head
        return head;
    }

    // Case 2: If the node to be deleted is in the middle or end of the list
    // Traverse the list to reach the node just before the one to be deleted
    for (int i = 1; i != position; i++) {
        prev = temp;         // Update 'prev' to current node
        temp = temp->next;   // Move 'temp' to the next node
    }

    // After traversal, 'temp' points to the node to be deleted
    if (temp != NULL) {
        prev->next = temp->next; // Unlink the node from the list
        free(temp);              // Free the memory allocated for the node
    }
    else {
        // If 'temp' is NULL, the position is beyond the length of the list
        cout << "Data not present\n";
    }

    // Return the head of the modified linked list
    return head;
}