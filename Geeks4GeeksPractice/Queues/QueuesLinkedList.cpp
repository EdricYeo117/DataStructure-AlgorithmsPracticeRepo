// Linked List Implementation of Queue in C++
#include <bits/stdc++.h>
using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    /*
        Constructor: Node
        Purpose: Initialize a node with the given data.
        Parameters:
            - int new_data: The integer value to be stored in the node.
        Pre: None.
        Post:
            - A node is created with 'data' set to 'new_data' and 'next' set to nullptr.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    Node(int new_data)
    {
        this->data = new_data;    // Assign the provided data to the node
        this->next = nullptr;     // Initialize the next pointer to nullptr indicating the end of the list
    }
};

/*
    Class: Queue
    Purpose: Implements queue operations using a singly linked list.
    Features:
        - enqueue: Add an element to the rear of the queue.
        - dequeue: Remove an element from the front of the queue.
        - getFront: Retrieve the front element without removing it.
        - getRear: Retrieve the rear element without removing it.
        - isEmpty: Check if the queue is empty.
    - Includes constructor and destructor for proper resource management.
*/
class Queue {

    // Pointer to the front and the rear of the linked list
    Node *front, *rear;

public:
    /*
        Constructor: Queue
        Purpose: Initialize an empty queue by setting front and rear to nullptr.
        Parameters: None.
        Pre: None.
        Post:
            - front and rear pointers are set to nullptr, indicating an empty queue.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    Queue() { 
        front = rear = nullptr; 
    }

    /*
        Destructor: ~Queue
        Purpose: Clean up all dynamically allocated nodes to prevent memory leaks when a Queue object is destroyed.
        Parameters: None.
        Pre: None.
        Post:
            - All nodes in the queue are deleted.
            - front and rear pointers are set to nullptr.
        Time Complexity: O(n), where n is the number of nodes in the queue.
        Space Complexity: O(1)
    */
    ~Queue() {
        while (!isEmpty()) {
            dequeue();  // Continuously dequeue until the queue is empty, ensuring all nodes are deleted
        }
    }

    /*
        Function: isEmpty
        Purpose: Check if the queue is empty.
        Parameters: None.
        Returns: 
            - bool: Returns true if the queue is empty; otherwise, false.
        Pre: None.
        Post: No changes to the queue.
        Time Complexity: O(1) - Constant time as it only checks the front pointer.
        Space Complexity: O(1) - Uses a constant amount of extra space.
    */
    bool isEmpty() const
    {
        // If the front is null, then the queue is empty; otherwise, it's not
        return front == nullptr;
    }

    /*
        Function: enqueue
        Purpose: Add an element to the rear of the queue.
        Parameters:
            - int new_data: The integer value to be added to the queue.
        Returns: 
            - void
        Pre: None.
        Post: 
            - If the queue was empty, both front and rear point to the new node.
            - Otherwise, the new node is added at the end, and rear is updated.
            - The size of the queue increases by 1.
        Time Complexity: O(1) - Constant time as it only adds a single node at the end.
        Space Complexity: O(1) - Allocates space for one new node regardless of queue size.
    */
    void enqueue(int new_data) {

        // Create a new linked list node with the provided data
        Node* new_node = new Node(new_data);

        // If queue is empty, the new node becomes both front and rear
        if (this->isEmpty()) {
            front = rear = new_node;
            return;
        }

        // Otherwise, add the new node at the end of the queue and update rear
        rear->next = new_node;
        rear = new_node;
    }

    /*
        Function: dequeue
        Purpose: Remove an element from the front of the queue.
        Parameters: None.
        Returns: 
            - void
        Pre: The queue must not be empty.
        Post: 
            - The front element is removed from the queue.
            - If the queue becomes empty after removal, both front and rear are set to nullptr.
            - The size of the queue decreases by 1.
        Time Complexity: O(1) - Constant time as it only removes the front node.
        Space Complexity: O(1) - Uses a constant amount of extra space for temporary storage.
    */
    void dequeue() {

        // If queue is empty, output underflow message and return
        if (this->isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        // Store the current front node in a temporary pointer
        Node* temp = front;

        // Move front to the next node in the queue
        front = front->next;

        // If front becomes nullptr after moving, set rear to nullptr as well
        if (front == nullptr)
            rear = nullptr;

        // Deallocate memory of the old front node
        delete temp;
    }

    /*
        Function: getFront
        Purpose: Retrieve the front element of the queue without removing it.
        Parameters: None.
        Returns: 
            - int: The data of the front element. Returns INT_MIN if the queue is empty.
        Pre: The queue must not be empty.
        Post: No changes to the queue.
        Time Complexity: O(1) - Constant time as it only accesses the front element.
        Space Complexity: O(1) - No extra space required.
    */
    int getFront() const {
        // Check if the queue is empty
        if (this->isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return front->data;    // Return the data of the front node
    }

    /*
        Function: getRear
        Purpose: Retrieve the rear element of the queue without removing it.
        Parameters: None.
        Returns: 
            - int: The data of the rear element. Returns INT_MIN if the queue is empty.
        Pre: The queue must not be empty.
        Post: No changes to the queue.
        Time Complexity: O(1) - Constant time as it only accesses the rear element.
        Space Complexity: O(1) - No extra space required.
    */
    int getRear() const {

        // Check if the queue is empty
        if (this->isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }

        return rear->data;     // Return the data of the rear node
    }
};

