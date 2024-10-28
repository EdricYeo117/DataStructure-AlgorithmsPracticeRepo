// C++ program to delete a node
// from the beginning of given linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};


/*
    Function: deleteHead
    ---------------------
    Deletes the head node of the linked list.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - Node*: Pointer to the new head of the linked list after deletion.

    Time Complexity:
        O(1) - Constant time deletion of the head node.

    Space Complexity:
        O(1) - Uses a constant amount of extra space.

    Steps:
        1. Check if the linked list is empty. If so, return nullptr.
        2. Store the current head node in a temporary pointer 'temp'.
        3. Update 'head' to point to the next node in the list.
        4. Delete the old head node pointed to by 'temp' to free memory.
        5. Return the new head of the linked list.
*/
Node* deleteHead(Node* head)
{
    // Base case if linked list is empty
    if (head == nullptr)
        return nullptr;

    // Store the current head in a temporary pointer
    Node* temp = head;

    // Update the head to point to the next node
    head = head->next;

    // Delete the old head node to free memory
    delete temp;

    // Return the new head
    return head;
}

/*
    Function: deleteNodeAtPosition
    ------------------------------
    Deletes a node at a specified position in the linked list.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.
        - position (int): The 1-based position of the node to be deleted.

    Returns:
        - Node*: Pointer to the head of the linked list after deletion.

    Time Complexity:
        O(n) - In the worst case, it traverses the entire list to reach the desired position.

    Space Complexity:
        O(1) - Uses a constant amount of extra space.

    Steps:
        1. Check if the linked list is empty. If so, return the head as is.
        2. If the position is 1, delete the head node using deleteHead function.
        3. Traverse the list to reach the node just before the desired position.
        4. If the position is beyond the length of the list, output an error message and return the head.
        5. Otherwise, unlink the node at the specified position and delete it to free memory.
*/
Node* deleteNodeAtPosition(Node* head, int position){
    // Base case: If linked list is empty
    if (head == nullptr)
        return head;

    // If head needs to be removed
    if (position == 1)
        return deleteHead(head);

    // Find the previous node of the node to be deleted
    Node* prev = head;
    for (int i = 1; i < position - 1 && prev != nullptr; i++) {
        prev = prev->next;
    }

    // If position is more than number of nodes
    if (prev == nullptr || prev->next == nullptr) {
        cout << "Position " << position << " is out of bounds.\n";
        return head;
    }

    // Node temp will point to node to be deleted
    Node* temp = prev->next;

    // Unlink the node from linked list
    prev->next = temp->next;

    // Free memory
    delete temp;

    return head;
}

/*
    Function: removeLastNode
    ------------------------
    Deletes the last node of the linked list.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - Node*: Pointer to the head of the linked list after deletion.

    Time Complexity:
        O(n) - Traverses the entire list to find the second last node.

    Space Complexity:
        O(1) - Uses a constant amount of extra space.

    Steps:
        1. If the linked list is empty, return nullptr.
        2. If the linked list has only one node, delete it and return nullptr.
        3. Traverse the list to find the second last node.
        4. Delete the last node and set the next pointer of the second last node to nullptr.
        5. Return the head of the modified list.
*/
Node* removeLastNode(Node* head)
{
    // If the list is empty, return nullptr
    if (head == nullptr) {
        return nullptr;
    }

    // If the list has only one node, delete it and return nullptr
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }

    // Find the second last node
    Node* second_last = head;
    while (second_last->next->next != nullptr) {
        second_last = second_last->next;
    }

    // Delete the last node
    delete second_last->next;

    // Change next of second last
    second_last->next = nullptr;

    return head;
}