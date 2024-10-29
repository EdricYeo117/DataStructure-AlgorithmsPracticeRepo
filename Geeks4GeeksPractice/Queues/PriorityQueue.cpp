#include <bits/stdc++.h>
using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    int data;        // Data stored in the node
    int priority;    // Priority of the node
    Node* next;      // Pointer to the next node in the list

    /*
        Constructor: Node
        Purpose: Initialize a node with the given data and priority.
        Parameters:
            - int new_data: The integer value to be stored in the node.
            - int priority: The priority of the node.
        Pre: None.
        Post:
            - A node is created with 'data' set to 'new_data', 'priority' set to 'priority', and 'next' set to nullptr.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    Node(int new_data, int priority)
    {
        this->data = new_data;    // Assign the provided data to the node
        this->priority = priority; // Assign the priority
        this->next = nullptr;     // Initialize the next pointer to nullptr indicating the end of the list
    }
};

/*
    Class: PriorityQueue
    Purpose: Implements priority queue operations using a singly linked list.
    Features:
        - enqueue: Add an element to the queue based on priority.
        - dequeue: Remove the element with the highest priority.
        - getFront: Retrieve the front element without removing it.
        - getRear: Retrieve the rear element without removing it.
        - isEmpty: Check if the queue is empty.
    - Includes constructor and destructor for proper resource management.
*/
class PriorityQueue {

    Node* front;  // Pointer to the front (highest priority) of the linked list

public:
    /*
        Constructor: PriorityQueue
        Purpose: Initialize an empty queue by setting front to nullptr.
        Parameters: None.
        Pre: None.
        Post:
            - front pointer is set to nullptr, indicating an empty queue.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    PriorityQueue() { 
        front = nullptr; 
    }

    /*
        Destructor: ~PriorityQueue
        Purpose: Clean up all dynamically allocated nodes to prevent memory leaks when a PriorityQueue object is destroyed.
        Parameters: None.
        Pre: None.
        Post:
            - All nodes in the queue are deleted.
            - front pointer is set to nullptr.
        Time Complexity: O(n), where n is the number of nodes in the queue.
        Space Complexity: O(1)
    */
    ~PriorityQueue() {
        while (!isEmpty()) {
            dequeue();  // Continuously dequeue until the queue is empty, ensuring all nodes are deleted
        }
    }

    /*
        Function: isEmpty
        Purpose: Check if the priority queue is empty.
        Parameters: None.
        Returns: 
            - bool: Returns true if the queue is empty; otherwise, false.
        Pre: None.
        Post: No changes to the queue.
        Time Complexity: O(1) - Constant time as it only checks the front pointer.
        Space Complexity: O(1) - Uses a constant amount of extra space.
    */
    bool isEmpty() const {
        return front == nullptr;
    }

    /*
        Function: enqueue
        Purpose: Add an element to the queue based on priority.
        Parameters:
            - int new_data: The integer value to be added to the queue.
            - int priority: The priority of the node.
        Returns: 
            - void
        Pre: None.
        Post: 
            - The new node is added in the correct position based on priority.
        Time Complexity: O(n) - In the worst case, traverses the entire queue to find the insertion point.
        Space Complexity: O(1) - Allocates space for one new node regardless of queue size.
    */
    void enqueue(int new_data, int priority) {
        Node* new_node = new Node(new_data, priority);

        // If the queue is empty or the new node has a higher priority than the front
        if (isEmpty() || front->priority < priority) {
            new_node->next = front;
            front = new_node;
        } else {
            // Find the correct position to insert the new node
            Node* temp = front;
            while (temp->next != nullptr && temp->next->priority >= priority) {
                temp = temp->next;
            }
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }

    /*
        Function: dequeue
        Purpose: Remove the element with the highest priority (front element).
        Parameters: None.
        Returns: 
            - void
        Pre: The queue must not be empty.
        Post: 
            - The front element is removed from the queue.
            - The size of the queue decreases by 1.
        Time Complexity: O(1) - Constant time as it only removes the front node.
        Space Complexity: O(1) - Uses a constant amount of extra space for temporary storage.
    */
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        Node* temp = front;
        front = front->next;
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
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        return front->data;
    }

    /*
        Function: getRear
        Purpose: Retrieve the rear element of the queue without removing it.
        Parameters: None.
        Returns: 
            - int: The data of the rear element. Returns INT_MIN if the queue is empty.
        Pre: The queue must not be empty.
        Post: No changes to the queue.
        Time Complexity: O(n) - Traverses the list to find the rear element.
        Space Complexity: O(1) - No extra space required.
    */
    int getRear() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return INT_MIN;
        }
        
        Node* temp = front;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        return temp->data;
    }
};