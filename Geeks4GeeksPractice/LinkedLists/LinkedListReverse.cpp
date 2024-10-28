// Iterative C++ program to reverse a linked list

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

/*
    Function: reverseListIterative
    ------------------------------
    Reverses a singly linked list using an iterative approach.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - Node*: Pointer to the new head of the reversed linked list.

    Time Complexity:
        O(n) - Where n is the number of nodes in the linked list. Each node is visited exactly once.

    Space Complexity:
        O(1) - Uses a constant amount of extra space regardless of the list size.

    Steps:
        1. Initialize three pointers: curr (current node), prev (previous node), and next (next node).
        2. Traverse the linked list:
            a. Store the next node.
            b. Reverse the current node's pointer to point to the previous node.
            c. Move the prev and curr pointers one step forward.
        3. After traversal, prev will point to the new head of the reversed list.
        4. Return prev as the new head.
*/
Node* reverseListIterative(Node* head) {
    Node* curr = head;    // Initialize 'curr' with head of the list
    Node* prev = nullptr; // Initialize 'prev' as nullptr
    Node* next = nullptr; // Initialize 'next' as nullptr

    // Traverse the list and reverse the links
    while (curr != nullptr) {
        next = curr->next;   // Store the next node
        curr->next = prev;   // Reverse the current node's pointer
        prev = curr;         // Move 'prev' to current node
        curr = next;         // Move to the next node in the original list
    }

    // After the loop, 'prev' points to the new head of the reversed list
    return prev;
}

/*
    Function: reverseListRecursive
    ------------------------------
    Reverses a singly linked list using a recursive approach.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - Node*: Pointer to the new head of the reversed linked list.

    Time Complexity:
        O(n) - Each node is visited exactly once during recursion.

    Space Complexity:
        O(n) - Due to the recursion stack, the space used grows linearly with the number of nodes.

    Steps:
        1. Base Case:
            a. If the list is empty (head is nullptr) or has only one node (head->next is nullptr), return head.
        2. Recursive Case:
            a. Recursively reverse the rest of the list starting from head->next.
            b. Make the next node of the original head point back to head.
            c. Set head->next to nullptr to mark the new end of the list.
            d. Return the new head obtained from recursion.
*/
Node* reverseListRecursive(Node* head) {
    // Base case: if head is null or only one node, return head
    if (head == nullptr || head->next == nullptr)
        return head;

    // Recursively reverse the rest of the list
    Node* rest = reverseListRecursive(head->next);

    // Make the next node of head point back to head
    head->next->next = head;

    // Set head's next to nullptr to mark the new end of the list
    head->next = nullptr;

    // 'rest' is the new head of the reversed list
    return rest;
}

/*
    Function: reverseListUsingStack
    --------------------------------
    Reverses a singly linked list using a stack-based approach.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - Node*: Pointer to the new head of the reversed linked list.

    Time Complexity:
        O(n) - Each node is visited exactly once to push onto the stack and then once to pop and rearrange.

    Space Complexity:
        O(n) - Uses a stack to store all nodes, which requires additional space proportional to the number of nodes.

    Steps:
        1. Create a stack to store the nodes.
        2. Traverse the linked list and push all nodes except the last node onto the stack.
        3. Make the last node as the new head of the linked list.
        4. Pop nodes from the stack one by one and append them to the new list.
        5. Update the next pointer of the last node to nullptr to mark the end of the reversed list.
        6. Return the new head.
*/
Node* reverseListUsingStack(Node* head) {
    if (head == nullptr || head->next == nullptr)
        return head; // No need to reverse if list is empty or has only one node

    stack<Node*> s; // Create a stack to store the nodes
    Node* temp = head;

    // Push all nodes except the last node into the stack
    while (temp->next != nullptr) {
        s.push(temp);
        temp = temp->next;
    }

    head = temp; // Make the last node as the new head

    // Pop all the nodes and append to the linked list
    while (!s.empty()) {
        temp->next = s.top(); // Append the top node from the stack
        s.pop();              // Remove the node from the stack
        temp = temp->next;    // Move to the next node in the reversed list
    }

    temp->next = nullptr; // Update the next pointer of the last node to nullptr

    return head; // Return the new head of the reversed list
}