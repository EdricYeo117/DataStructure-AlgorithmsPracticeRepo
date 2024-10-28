// C++ program to count occurrences in
// a linked list by recursion
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
      Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};


/*
    Function: count
    ---------------
    Counts the number of occurrences of a given key in the linked list recursively.

    Parameters:
        - head (Node*): Pointer to the head node of the linked list.
        - key (int): The integer value to count in the linked list.

    Returns:
        - int: The number of times the key occurs in the linked list.

    Time Complexity:
        O(n) - Each node is visited exactly once during recursion, where n is the number of nodes.

    Space Complexity:
        O(n) - Due to the recursion stack, the space used grows linearly with the number of nodes.
*/
int countOccurrences(struct Node* head, int key) {
    // Base case: If the current node is NULL, return 0 as there are no more nodes to check
    if (head == NULL)
        return 0;

    // Recursively count occurrences in the rest of the list
    int ans = countOccurrences(head->next, key);

    // If the current node's data matches the key, increment the count
    if (head->data == key)
        ans++;

    // Return the cumulative count
    return ans;
}