// C++ program to delete a linked list 
// using recursion

#include <iostream>
using namespace std;

// Definition of the Node class for the linked list
class Node {
public:
    int data;      // Holds the data part of the node
    Node* next;    // Pointer to the next node in the list

    /*
        Constructor: Node
        -----------------
        Initializes a new node with the provided data value.

        Parameters:
            - x (int): The integer value to store in the node.

        Initializes the 'next' pointer to nullptr, indicating that the node
        does not point to any other node initially.
    */
    Node(int x) {
        data = x;        // Assign the provided data to the node
        next = nullptr;  // Initialize the next pointer to nullptr indicating the end of the list
    }
};

/*
    Function: deleteList
    --------------------
    Deletes the entire linked list using a recursive approach.

    Parameters:
        - curr (Node*): Pointer to the current node being deleted.

    Returns:
        - void

    Time Complexity:
        O(n) - Each node is visited exactly once during recursion.

    Space Complexity:
        O(n) - Due to the recursion stack, the space used grows linearly with the number of nodes.

    Steps:
        1. Base Case:
            a. If the current node (curr) is nullptr, the list is empty or end of the list is reached. Return.
        2. Recursive Case:
            a. Recursively call deleteList on the next node (curr->next).
            b. After the recursive call returns, delete the current node (curr) to free memory.
*/
void deleteList(Node* curr) {

    // Base case: If the list is empty, return
    if (curr == nullptr) {
        return;
    }

    // Recursively delete the next node
    deleteList(curr->next);

    // Delete the current node to free memory
    delete curr;
}