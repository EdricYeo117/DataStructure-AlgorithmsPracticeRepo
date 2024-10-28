#include <bits/stdc++.h>
using namespace std;

// Link list node
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize a new node with data
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};


/*
    Function: countNodes
    --------------------
    Counts the number of nodes in a linked list using an iterative approach.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - int: The total number of nodes in the linked list.

    Time Complexity:
        O(n) - Where n is the number of nodes in the linked list. The function traverses each node exactly once.

    Space Complexity:
        O(1) - Uses a constant amount of extra space regardless of the list size.

    Steps:
        1. Initialize a counter 'count' to 0 to keep track of the number of nodes.
        2. Initialize a pointer 'current' to the head of the list.
        3. Traverse the linked list:
            a. While 'current' is not nullptr:
                i. Increment 'count' by 1.
                ii. Move 'current' to the next node in the list.
        4. After traversal, return the value of 'count' as the total number of nodes.
*/
int countNodes(Node* head) {
    int count = 0;             // Initialize count to 0
    Node* current = head;     // Initialize 'current' with head of the list

    // Traverse the list and increment count for each node
    while (current != nullptr) {
        count++;               // Increment the node count
        current = current->next; // Move to the next node
    }

    return count;              // Return the total number of nodes
}

/*
    Function: countNodesRecursive
    -----------------------------
    Counts the number of nodes in a linked list using a recursive approach.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.

    Returns:
        - int: The total number of nodes in the linked list.

    Time Complexity:
        O(n) - Where n is the number of nodes in the linked list. Each node is visited once in the recursion.

    Space Complexity:
        O(n) - Due to the recursion stack, the space used grows linearly with the number of nodes.

    Steps:
        1. Check the base case:
            a. If 'head' is nullptr, the list is empty. Return 0.
        2. If 'head' is not nullptr:
            a. Return 1 plus the result of counting the remaining nodes recursively.
*/
int countNodesRecursive(Node* head) {
    // Base case: if head is null, return 0
    if (head == nullptr) {
        return 0;
    }

    // Recursive call to count nodes in the rest of the list
    return 1 + countNodesRecursive(head->next);
}