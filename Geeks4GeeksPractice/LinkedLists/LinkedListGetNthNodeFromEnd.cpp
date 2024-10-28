// C++ program to find Nth node from end of linked list

#include <bits/stdc++.h>
using namespace std;

// Link list node
struct Node {
    int data;
    Node* next;
    
      // Constructor to initialize a new node with data
    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

/*
    Function: findNthFromLast
    -------------------------
    Finds the data at the Nth node from the end of the linked list by first
    calculating the total length of the list.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.
        - N (int): The 1-based position from the end of the node whose data is to be retrieved.

    Returns:
        - int: The data of the Nth node from the end if it exists; otherwise, -1 indicating that N is greater than the length of the list.

    Time Complexity:
        O(n) - Traverses the entire list to calculate its length, and then traverses again to find the desired node.

    Space Complexity:
        O(1) - Uses a constant amount of extra space regardless of the list size.
*/
int findNthFromLast(Node* head, int N) {
    int len = 0, i;          // Initialize length counter and loop variable

    Node* temp = head;       // Temporary pointer to traverse the list

    // Traverse the linked list to count the total number of nodes
    while (temp != NULL) {
        temp = temp->next;   // Move to the next node
        len++;               // Increment the node count
    }

    // Check if N is greater than the length of the list
    if (len < N)
        return -1;           // Return -1 to indicate that N is out of bounds

    temp = head;             // Reset temp to the head of the list

    /*
        Calculate the position from the beginning of the list.
        Since we need the Nth node from the end, it corresponds to the (len - N + 1)th node from the start.
    */
    for (i = 1; i < len - N + 1; i++)
        temp = temp->next;   // Move temp to the desired node

    return temp->data;       // Return the data of the Nth node from the end
}

/*
    Function: nthFromEnd
    --------------------
    Finds the data at the Nth node from the end of the linked list using the two-pointer technique.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.
        - N (int): The 1-based position from the end of the node whose data is to be retrieved.

    Returns:
        - int: The data of the Nth node from the end if it exists; otherwise, -1 indicating that N is greater than the length of the list.

    Time Complexity:
        O(n) - Traverses the list only once using two pointers.

    Space Complexity:
        O(1) - Uses a constant amount of extra space regardless of the list size.
*/
int nthFromEnd(Node *head, int N) {
    Node* main_ptr = head;    // Pointer to traverse the list starting from the head
    Node* ref_ptr = head;     // Reference pointer to create a gap of N nodes from main_ptr

    // Move ref_ptr to the Nth node from the beginning
    for (int i = 1; i < N; i++) {
        ref_ptr = ref_ptr->next;  // Move ref_ptr one node ahead

        /*
            If ref_ptr becomes NULL before reaching the Nth node,
            it means that N is greater than the number of nodes in the list.
        */
        if (ref_ptr == NULL) {
            return -1;            // Return -1 to indicate that N is out of bounds
        }
    }

    /*
        Move both ref_ptr and main_ptr one node at a time until ref_ptr reaches the last node.
        At this point, main_ptr will be pointing to the Nth node from the end.
    */
    while (ref_ptr->next != NULL) {
        ref_ptr = ref_ptr->next;      // Move ref_ptr one node ahead
        main_ptr = main_ptr->next;    // Move main_ptr one node ahead
    }

    return main_ptr->data;            // Return the data of the Nth node from the end
}