#include <iostream>
using namespace std;

// Definition of a Node in a singly linked list
struct Node {
    int data;       // Holds the data part of the node
    Node *next;     // Pointer to the next node in the list

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

/*
    Function: traverseLinkedList
    Purpose: Traverse the linked list from the head and print each node's data.
    Parameters:
        - head: Pointer to the head node of the linked list.
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
void traverseLinkedList(Node* head) {
    Node* current = head; // Initialize 'current' to start at the head of the list

    // Iterate through the list until the end is reached
    while(current != nullptr) {
        cout << current->data << " "; // Output the data of the current node
        current = current->next;       // Move to the next node in the list
    }

    cout << endl; // Print a newline character after traversal for better output formatting
}

/*
    Function: searchLinkedList
    Purpose: Search for a specific value in the linked list.
    Parameters:
        - head: Pointer to the head node of the linked list.
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
bool searchLinkedList(Node* head, int value) {
    Node* current = head; // Initialize 'current' to start at the head of the list

    // Traverse the list to search for the value
    while (current != nullptr) {
        if (current->data == value) { // Check if current node contains the target value
            return true;              // Value found; return true
        }
        current = current->next;      // Move to the next node in the list
    }

    return false; // Value not found after complete traversal; return false
}

/*
    Function: findLength
    Purpose: Calculate the number of nodes in the linked list.
    Parameters:
        - head: Pointer to the head node of the linked list.
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
int findLength(Node* head) {
    int length = 0;        // Initialize counter to track the number of nodes
    Node* current = head;  // Initialize 'current' to start at the head of the list

    // Traverse the list to count the nodes
    while (current != nullptr) {
        length++;                    // Increment the counter for each node
        current = current->next;     // Move to the next node in the list
    }

    return length; // Return the total number of nodes in the list
}

/*
    Function: insertAtBeginning
    Purpose: Insert a new node with a given value at the beginning of the linked list.
    Parameters:
        - head: Pointer to the head node of the linked list.
        - value: The integer value to be inserted into the new node.
    Returns:
        - Node*: Pointer to the new head of the linked list.
    Time Complexity:
        O(1) - Constant time insertion at the beginning.
    Space Complexity:
        O(1) - Only a new node is created regardless of list size.
    Steps:
        1. Create a new node 'newNode' with the provided 'value'.
        2. Set the 'next' pointer of 'newNode' to the current 'head'.
        3. Update 'head' to point to 'newNode', making it the new head of the list.
        4. Return the updated 'head'.
*/
Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node(value); // Create a new node with the specified value
    newNode->next = head;            // Link the new node to the current head of the list
    head = newNode;                  // Update 'head' to point to the new node, making it the new head
    return head;                     // Return the updated head of the list
}

/*
    Function: insertAtEnd
    Purpose: Insert a new node with a given value at the end of the linked list.
    Parameters:
        - head: Pointer to the head node of the linked list.
        - value: The integer value to be inserted into the new node.
    Returns:
        - Node*: Pointer to the head of the linked list after insertion.
    Time Complexity:
        O(n) - In the worst case, where n is the number of nodes, the function traverses the entire list to find the last node.
    Space Complexity:
        O(1) - Only a new node is created regardless of list size.
    Steps:
        1. Create a new node 'newNode' with the provided 'value'.
        2. Check if the list is empty (i.e., 'head' is nullptr).
            a. If empty, return 'newNode' as the new head of the list.
        3. If the list is not empty, initialize a pointer 'current' to the head.
        4. Traverse the list to find the last node (where 'current->next' is nullptr).
        5. Link the last node's 'next' pointer to 'newNode'.
        6. Return the original 'head' of the list.
*/
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value); // Create a new node with the specified value

    if (head == nullptr) {           // Check if the list is empty
        return newNode;              // If empty, the new node becomes the head of the list
    }

    Node* current = head;            // Initialize 'current' to start at the head of the list

    // Traverse the list to find the last node
    while (current->next != nullptr) {
        current = current->next;     // Move to the next node in the list
    }

    current->next = newNode;         // Link the last node to the new node, effectively adding it to the end
    return head;                     // Return the head of the list (unchanged)
}

/*
    Function: insertAtPosition
    Purpose: Insert a new node with a given data value at a specific position in the linked list.
    Parameters:
        - head: Pointer to the head node of the linked list.
        - position: The position (1-based index) where the new node should be inserted.
        - data: The integer value to be inserted into the new node.
    Returns:
        - Node*: Pointer to the head of the linked list after insertion.
    Time Complexity:
        O(n) - In the worst case, where n is the number of nodes, the function may need to traverse up to position-1 nodes.
    Space Complexity:
        O(1) - Only a new node is created regardless of list size.
    Steps:
        1. Validate that 'position' is a positive integer (>= 1).
            a. If not, output an error message and return the original 'head'.
        2. Create a new node 'newNode' with the provided 'data'.
        3. If 'position' is 1, insert the new node at the beginning:
            a. Set 'newNode->next' to the current 'head'.
            b. Return 'newNode' as the new head of the list.
        4. Initialize a pointer 'current' to the head of the list and a counter 'currentPosition' to 1.
        5. Traverse the list to find the node just before the desired insertion position:
            a. While 'currentPosition' is less than 'position - 1' and 'current' is not nullptr:
                i. Move 'current' to the next node.
                ii. Increment 'currentPosition'.
        6. After traversal, check if 'current' is nullptr:
            a. If so, the desired position is out of bounds; output an error message.
            b. Delete 'newNode' to prevent a memory leak.
            c. Return the original 'head' without making changes.
        7. Insert 'newNode' at the desired position:
            a. Set 'newNode->next' to 'current->next'.
            b. Set 'current->next' to 'newNode'.
        8. Return the original 'head' (unchanged).
*/
Node* insertAtPosition(Node* head, int position, int data) {
    // Validate that the position is a positive integer
    if (position < 1) {
        std::cerr << "Error: Invalid position " << position << ". Position must be >= 1." << std::endl;
        return head; // Return the original head without making changes
    }

    Node* newNode = new Node(data); // Create a new node with the specified data

    // If the position is 1, insert the new node at the beginning
    if (position == 1) {
        newNode->next = head; // Link the new node to the current head
        return newNode;       // The new node becomes the new head of the list
    }

    Node* current = head;      // Initialize 'current' to start at the head of the list
    int currentPosition = 1;   // Initialize a counter to track the current position

    // Traverse the list to find the node just before the desired insertion position
    while (currentPosition < position - 1 && current != nullptr) {
        current = current->next; // Move to the next node in the list
        currentPosition++;       // Increment the position counter
    }

    // After traversal, check if 'current' is nullptr, indicating an out-of-bounds position
    if (current == nullptr) {
        std::cerr << "Error: Position " << position << " is out of bounds." << std::endl;
        delete newNode; // Delete the new node to prevent a memory leak
        return head;    // Return the original head without making changes
    }

    // Insert the new node at the desired position
    newNode->next = current->next; // Link the new node to the next node in the list
    current->next = newNode;       // Link the previous node to the new node

    return head; // Return the head of the list (unchanged)
}

/*
    Function: deleteFromBeginning
    Purpose: Delete the first node (head) of the linked list.
    Parameters:
        - head: Pointer to the head node of the linked list.
    Returns:
        - Node*: Pointer to the new head of the linked list after deletion.
    Time Complexity:
        O(1) - Constant time deletion from the beginning.
    Space Complexity:
        O(1) - Uses a constant amount of extra space.
    Steps:
        1. Check if the list is empty (i.e., 'head' is nullptr).
            a. If empty, output an error message and return nullptr.
        2. Store the current head node in a temporary pointer 'temp'.
        3. Update 'head' to point to the next node in the list.
        4. Delete the old head node pointed to by 'temp' to free memory.
        5. Return the updated 'head' of the list.
*/
Node* deleteFromBeginning(Node* head) {
    if (head == nullptr) { // Check if the list is empty
        std::cerr << "Error: Cannot delete from an empty list." << std::endl;
        return head; // Return nullptr as the list is already empty
    }

    Node* temp = head;    // Temporarily store the current head node
    head = head->next;    // Update 'head' to point to the next node in the list
    delete temp;          // Delete the old head node to free memory

    return head;          // Return the new head of the list
}

/*
    Function: removeLastNode
    Purpose: Delete the last node of the linked list.
    Parameters:
        - head: Pointer to the head node of the linked list.
    Returns:
        - Node*: Pointer to the head of the linked list after deletion.
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
        4. Traverse the list to find the second last node:
            a. Continue moving 'second_last' until 'second_last->next->next' is nullptr.
        5. After traversal, 'second_last' points to the second last node.
        6. Delete the last node by:
            a. Deleting 'second_last->next'.
            b. Setting 'second_last->next' to nullptr to indicate the new end of the list.
        7. Return the head of the list.
*/
Node* removeLastNode(Node* head) {
    if (head == nullptr) { // Check if the list is empty
        std::cerr << "Error: Cannot delete from an empty list." << std::endl;
        return head; // Return nullptr as the list is already empty
    }

    if (head->next == nullptr) { // Check if there is only one node in the list
        delete head;              // Delete the single node
        return nullptr;           // Return nullptr as the list is now empty
    }

    Node* second_last = head; // Initialize 'second_last' to start at the head of the list

    // Traverse the list to find the second last node
    while (second_last->next->next != nullptr) {
        second_last = second_last->next; // Move 'second_last' to the next node
    }

    // After traversal, 'second_last->next' is the last node
    delete second_last->next; // Delete the last node to free memory
    second_last->next = nullptr; // Set 'second_last->next' to nullptr to indicate the new end of the list

    return head; // Return the head of the list (unchanged)
}

/*
    Function: deleteAtPosition
    Purpose: Delete the node at a specific position in the linked list.
    Parameters:
        - head: Pointer to the head node of the linked list.
        - position: The 1-based position of the node to be deleted.
    Returns:
        - Node*: Pointer to the head of the linked list after deletion.
    Time Complexity:
        O(n) - In the worst case, where n is the number of nodes, the function may need to traverse up to position-1 nodes.
    Space Complexity:
        O(1) - Uses a constant amount of extra space.
    Steps:
        1. Check if the list is empty or if the position is invalid (less than 1).
            a. If either condition is true, output an error message and return the original head.
        2. If the position is 1, delete the head node:
            a. Store the current head in a temporary pointer.
            b. Update the head to point to the next node.
            c. Delete the old head node to free memory.
            d. Return the new head.
        3. Traverse the list to reach the node just before the target position:
            a. Initialize a pointer 'current' to the head.
            b. Loop from 1 to (position - 1), moving 'current' to the next node each time.
            c. If 'current' becomes nullptr before reaching the desired position, output an error message and return the original head.
        4. After traversal, check if the target node exists:
            a. If 'current->next' is nullptr, the position is out of bounds. Output an error message and return the original head.
        5. If the target node exists:
            a. Store the target node in a temporary pointer.
            b. Update 'current->next' to skip the target node and point to the subsequent node.
            c. Delete the target node to free memory.
        6. Return the head of the linked list.
*/
Node* deleteAtPosition(Node* head, int position)
{
    // Step 1: Check if the list is empty or the position is invalid
    if (head == nullptr) {
        cerr << "Error: Cannot delete from an empty list." << endl;
        return head; // Return the original head as the list is empty
    }

    if (position < 1) {
        cerr << "Error: Invalid position " << position << ". Position must be >= 1." << endl;
        return head; // Return the original head as the position is invalid
    }

    // Step 2: If the head needs to be deleted
    if (position == 1) {
        Node* temp = head;    // Store the current head in a temporary pointer
        head = head->next;    // Update 'head' to point to the next node in the list
        delete temp;          // Delete the old head node to free memory
        return head;          // Return the new head of the list
    }

    // Step 3: Traverse to the node before the position to be deleted
    Node* current = head; // Initialize 'current' to start at the head of the list

    // Loop to reach the (position - 1)th node
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next; // Move 'current' to the next node
    }

    // Step 4: Check if the position is out of range
    if (current == nullptr || current->next == nullptr) {
        cerr << "Error: Position " << position << " is out of bounds." << endl;
        return head; // Return the original head as the position is invalid
    }

    // Step 5: Delete the node at the specified position
    Node* temp = current->next;          // Store the node to be deleted
    current->next = current->next->next; // Bypass the node to be deleted
    delete temp;                         // Delete the target node to free memory

    // Step 6: Return the head of the linked list
    return head;
}