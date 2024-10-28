// C++ program to illustrate how to find the middle element
// by counting the number of nodes
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
  
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

/*
    Function: getLength
    -------------------
    Helper function to find the length of the linked list by traversing it.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - int: The total number of nodes in the linked list.

    Time Complexity:
        O(n) - Traverses the entire linked list once, where n is the number of nodes.

    Space Complexity:
        O(1) - Uses a constant amount of extra space.
*/
int getLength(Node* head) {

    // Variable to store the length of the linked list
    int length = 0;

    // Traverse the entire linked list and increment length by 1 for each node
    while (head) {
        length++;        // Increment the node count
        head = head->next; // Move to the next node
    }

    // Return the total number of nodes in the linked list
    return length;
}

/*
    Function: getMiddle
    -------------------
    Finds the middle element of the linked list by first counting the number of nodes.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - int: The data of the middle node if the list is non-empty; otherwise, returns -1 to indicate an empty list.

    Time Complexity:
        O(n) - Traverses the linked list twice: once to find the length and once to reach the middle node.

    Space Complexity:
        O(1) - Uses a constant amount of extra space.
*/
int getMiddle(Node* head) {

    // Finding the total length of the linked list
    int length = getLength(head);

    // If the linked list is empty, return -1 to indicate no middle element
    if (length == 0)
        return -1;

    // Calculate the index of the middle node
    // For even lengths, this will point to the second of the two middle nodes
    int mid_index = length / 2;

    // Traverse the list until the middle node is reached
    while (mid_index--) {
        head = head->next; // Move to the next node
    }

    // After traversal, head points to the middle node
    return head->data; // Return the data of the middle node
}