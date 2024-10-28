//C++ program to find the data at nth node
//recursively

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) {
      data = x;
      next = NULL;
    }
};

/*
    Function: GetNthRecursive
    -------------------------
    Recursively retrieves the data at the nth node of the linked list.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.
        - index (int): The 1-based position of the node whose data is to be retrieved.

    Returns:
        - int: The data of the nth node if it exists; otherwise, -1 indicating an out-of-bounds index.

    Time Complexity:
        O(n) - Each node is visited exactly once during the recursion.

    Space Complexity:
        O(n) - Due to the recursion stack, the space used grows linearly with the number of nodes.
*/
int GetNthRecursive(Node* head, int index) {
    // Base case: If the list is empty or index is out of bounds
    if (head == NULL)
        return -1;

    // If index equals 1, return the current node's data
    if (index == 1)
        return head->data;

    // Recursively call the function for the next node with decremented index
    return GetNthRecursive(head->next, index - 1);
}

/*
    Function: GetNthIterative
    -------------------------
    Iteratively retrieves the data at the nth node of the linked list.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.
        - index (int): The 1-based position of the node whose data is to be retrieved.

    Returns:
        - int: The data of the nth node if it exists; otherwise, -1 indicating an out-of-bounds index.

    Time Complexity:
        O(n) - Traverses the list once until the nth node is found.

    Space Complexity:
        O(1) - Uses a constant amount of extra space regardless of the list size.
*/
int GetNthIterative(Node* head, int index) {
    Node* curr = head; // Initialize a pointer to traverse the list starting from the head
    int count = 1;     // Initialize a counter to keep track of the current node's position

    // Traverse the list until the end is reached
    while (curr != nullptr) {
        if (count == index) // If the current node is at the desired index
            return curr->data; // Return the data of the current node
        count++;             // Increment the position counter
        curr = curr->next;   // Move to the next node in the list
    }

    // If the index is out of bounds (greater than the number of nodes)
    return -1;
}