#include <iostream>
using namespace std;

// Node class representing each node in the linked list
class Node {
public:
    int data;       // Holds the data part of the node
    Node* next;     // Pointer to the next node in the list

    // Constructor to initialize the node with a given value
    Node(int data) {
        this->data = data;    // Assign the provided data to the node
        this->next = nullptr; // Initialize the next pointer to nullptr indicating the end of the list
    }
};

/*
    Operations of a singly linked list:
    1. Traversal - Visiting each node in the list
    2. Searching - Finding a node with a specific value
    3. Length - Determining the number of nodes in the list
    4. Insertion:
        a. Insert at the beginning
        b. Insert at the end
        c. Insert at a specific position
    5. Deletion:
        a. Delete from the beginning
        b. Delete from the end
        c. Delete a specific node
*/

class LinkedList {
private:
    Node* head;  // Pointer to the head node of the linked list

public:
    // Constructor to initialize an empty linked list
    LinkedList() : head(nullptr) {}

    // Destructor to delete all nodes in the linked list
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    /*
        Function: traverseLinkedList
        Purpose: Traverse the linked list from the head and print each node's data.
        Parameters:
            - None.
        Returns:
            - void
        Time Complexity:
            O(n) - Where n is the number of nodes in the list, as it visits each node once.
        Space Complexity:
            O(1) - Uses a constant amount of extra space.
        Steps:
            1. Initialize a pointer 'current' to the head of the list.
            2. Use a while loop to iterate through the list until 'current' becomes nullptr.
            3. Inside the loop, print the 'data' of the current node.
            4. Move the 'current' pointer to the next node in the list.
            5. After traversal, print a newline character for better readability.
    */
    void traverseLinkedList() {
        Node* current = head;  // Initialize 'current' to start at the head of the list

        // Iterate through the list until the end is reached
        while (current != nullptr) {
            cout << current->data << " ";  // Output the data of the current node
            current = current->next;       // Move to the next node in the list
        }

        cout << endl;  // Print a newline character after traversal for better output formatting
    }

    /*
        Function: searchLinkedList
        Purpose: Search for a specific value in the linked list.
        Parameters:
            - value: The integer value to search for in the list.
        Returns:
            - bool: Returns true if the value is found, otherwise false.
        Time Complexity:
            O(n) - In the worst case, where n is the number of nodes, the function may need to traverse the entire list.
        Space Complexity:
            O(1) - Uses a constant amount of extra space.
        Steps:
            1. Initialize a pointer 'current' to the head of the list.
            2. Use a while loop to traverse the list until 'current' is nullptr.
            3. Inside the loop, check if the 'data' of the current node matches the target 'value'.
            4. If a match is found, return true immediately.
            5. If not, move the 'current' pointer to the next node.
            6. If the end of the list is reached without finding the value, return false.
    */
    bool searchLinkedList(int value) {
        Node* current = head;  // Initialize 'current' to start at the head of the list

        // Traverse the list to search for the value
        while (current != nullptr) {
            if (current->data == value) {  // Check if current node contains the target value
                return true;               // Value found; return true
            }
            current = current->next;       // Move to the next node in the list
        }

        return false;  // Value not found after complete traversal; return false
    }

    /*
        Function: findLength
        Purpose: Calculate the number of nodes in the linked list.
        Parameters:
            - None.
        Returns:
            - int: The total number of nodes in the list.
        Time Complexity:
            O(n) - Where n is the number of nodes, as it traverses each node once.
        Space Complexity:
            O(1) - Uses a constant amount of extra space.
        Steps:
            1. Initialize a counter 'length' to 0.
            2. Initialize a pointer 'current' to the head of the list.
            3. Use a while loop to traverse the list until 'current' becomes nullptr.
            4. Inside the loop, increment 'length' for each node encountered.
            5. Move the 'current' pointer to the next node.
            6. After traversal, return the value of 'length'.
    */
    int findLength() {
        int length = 0;         // Initialize counter to track the number of nodes
        Node* current = head;   // Initialize 'current' to start at the head of the list

        // Traverse the list to count the nodes
        while (current != nullptr) {
            length++;                  // Increment the counter for each node
            current = current->next;   // Move to the next node in the list
        }

        return length;  // Return the total number of nodes in the list
    }

    /*
        Function: insertAtBeginning
        Purpose: Insert a new node with a given value at the beginning of the linked list.
        Parameters:
            - value: The integer value to be inserted into the new node.
        Returns:
            - void
        Time Complexity:
            O(1) - Constant time insertion at the beginning.
        Space Complexity:
            O(1) - Only a new node is created regardless of list size.
        Steps:
            1. Create a new node 'newNode' with the provided 'value'.
            2. Set the 'next' pointer of 'newNode' to the current 'head'.
            3. Update 'head' to point to 'newNode', making it the new head of the list.
    */
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);  // Create a new node with the specified value
        newNode->next = head;             // Link the new node to the current head of the list
        head = newNode;                   // Update 'head' to point to the new node, making it the new head
    }

    /*
        Function: insertAtEnd
        Purpose: Insert a new node with a given value at the end of the linked list.
        Parameters:
            - value: The integer value to be inserted into the new node.
        Returns:
            - void
        Time Complexity:
            O(n) - In the worst case, where n is the number of nodes, the function traverses the entire list to find the last node.
        Space Complexity:
            O(1) - Only a new node is created regardless of list size.
        Steps:
            1. Create a new node 'newNode' with the provided 'value'.
            2. Check if the list is empty (i.e., 'head' is nullptr).
                a. If empty, assign 'newNode' as the head.
            3. If the list is not empty, initialize a pointer 'current' to the head.
            4. Traverse the list to find the last node (where 'current->next' is nullptr).
            5. Link the last node's 'next' pointer to 'newNode'.
    */
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);  // Create a new node with the specified value

        if (head == nullptr) {  // Check if the list is empty
            head = newNode;     // If empty, the new node becomes the head of the list
            return;
        }

        Node* current = head;  // Initialize 'current' to start at the head of the list

        // Traverse the list to find the last node
        while (current->next != nullptr) {
            current = current->next;  // Move to the next node in the list
        }

        current->next = newNode;  // Link the last node to the new node, effectively adding it to the end
    }

    /*
        Function: deleteFromBeginning
        Purpose: Delete the first node (head) of the linked list.
        Parameters:
            - None.
        Returns:
            - void
        Time Complexity:
            O(1) - Constant time deletion from the beginning.
        Space Complexity:
            O(1) - Uses a constant amount of extra space.
        Steps:
            1. Check if the list is empty (i.e., 'head' is nullptr).
                a. If empty, output an error message and return.
            2. Store the current head node in a temporary pointer 'temp'.
            3. Update 'head' to point to the next node in the list.
            4. Delete the old head node pointed to by 'temp' to free memory.
    */
    void deleteFromBeginning() {
        if (head == nullptr) {  // Check if the list is empty
            cerr << "Error: Cannot delete from an empty list." << endl;
            return;
        }

        Node* temp = head;   // Temporarily store the current head node
        head = head->next;   // Update 'head' to point to the next node in the list
        delete temp;         // Delete the old head node to free memory
    }

    /*
        Function: removeLastNode
        Purpose: Delete the last node of the linked list.
        Parameters:
            - None.
        Returns:
            - void
        Time Complexity:
            O(n) - In the worst case, where n is the number of nodes, the function traverses the entire list to find the second last node.
        Space Complexity:
            O(1) - Uses a constant amount of extra space.
        Steps:
            1. Check if the list is empty (i.e., 'head' is nullptr).
                a. If empty, output an error message and return nullptr.
            2. Check if the list has only one node (i.e., 'head->next' is nullptr).
                a. If so, delete the head node and return nullptr as the list becomes empty.
            3. Initialize a pointer 'second_last' to the head of the list.
            4. Traverse the list to find the second last node.
            5. Delete the last node.
            6. Set 'second_last->next' to nullptr to indicate the new end of the list.
    */
    void removeLastNode() {
        if (head == nullptr) {  // Check if the list is empty
            cerr << "Error: Cannot delete from an empty list." << endl;
            return;
        }

        if (head->next == nullptr) {  // Check if there is only one node in the list
            delete head;               // Delete the single node
            head = nullptr;            // Set head to nullptr as the list is now empty
            return;
        }

        Node* second_last = head;  // Initialize 'second_last' to start at the head of the list

        // Traverse the list to find the second last node
        while (second_last->next->next != nullptr) {
            second_last = second_last->next;  // Move 'second_last' to the next node
        }

        // After traversal, 'second_last->next' is the last node
        delete second_last->next;     // Delete the last node to free memory
        second_last->next = nullptr;  // Set 'second_last->next' to nullptr to indicate the new end of the list
    }


    // Function to rotate the linked list by moving the first 'k' nodes to the end
    void rotateList(int k) {
        if (k <= 0 || head == nullptr || head->next == nullptr) return;

        // Find the length of the list
        int length = 1;
        Node* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // If k is greater than or equal to the length, we take k % length
        k = k % length;
        if (k == 0) return;  // No rotation needed if k is a multiple of length

        // Find the new tail (at position length - k)
        Node* newTail = head;
        for (int i = 1; i < length - k; i++) {
            newTail = newTail->next;
        }

        // Set the new head and rotate
        Node* newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        head = newHead;
    }
};