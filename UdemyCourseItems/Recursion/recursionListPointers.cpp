// Add items to a list at specific index, using recursion
/*
TIme Complexity: O(n) worst case, O(index)
Space Complexity: O(n) worst case, O(index)
*/
bool List::addR(int index, ItemType item) {
    // Check if the index is within bounds
    if (index < size) {
        // Start the recursive addition process
        addRHelper(index, item, firstNode, 0);
        return true;
    }
    return false; // Return false if the index is out of bounds
}

Node* List::addRHelper(int index, ItemType item, Node* currentNode, int currentIndex) {
    // Base case: When the current index matches the target index
    if (currentIndex == index) {
        // Create a new node and insert it into the list
        Node* newNode = new Node;
        newNode->item = currentNode->item; // Copy the item of the current node
        newNode->next = currentNode->next; // Set the new node's next pointer
        currentNode->next = newNode;       // Link the current node to the new node
        currentNode->item = item;          // Update the current node's item
        size++;                            // Increment the size of the list
        return nullptr;
    }

    // Recursive case: Traverse the list to the next node
    addRHelper(index, item, currentNode->next, currentIndex + 1);
    return nullptr;
}


// Remove an item from the list at a specific index, using recursion
/*
TIme Complexity: O(n) worst case, O(index)
Space Complexity: O(n) worst case, O(index)
*/
bool List::removeR(int index) {
    // Check if the index is within bounds
    if (index < size) {
        removeRHelper(index, nullptr, firstNode, 0);
        return true;
    }
    return false; // Return false if the index is out of bounds
}

Node* List::removeRHelper(int index, Node* previousNode, Node* currentNode, int currentIndex) {
    // Base case: When the target index is found
    if (currentIndex == index) {
        if (previousNode == nullptr) {
            // Special case: Removing the first node
            Node* tempNode = firstNode;
            firstNode = firstNode->next; // Update the head of the list
            delete tempNode;             // Delete the first node
        } else {
            // General case: Removing a node in the middle or end
            previousNode->next = currentNode->next; // Bypass the current node
            delete currentNode;                     // Delete the current node
        }
        size--; // Decrement the size of the list
        return nullptr;
    }

    // Recursive case: Traverse to the next node
    removeRHelper(index, currentNode, currentNode->next, currentIndex + 1);
    return nullptr;
}

// Count the number of occurrences of an item in the list, using recursion
/*
TIme Complexity: O(n) worst case
Space Complexity: O(n) worst case
*/
int List::countR(ItemType item) {
    // Call the helper function to count occurrences of the item
    return countRHelper(front, item);
}

int List::countRHelper(Node* currentNode, ItemType item) {
    // Base case: If the current node is null, return 0
    if (currentNode == nullptr) {
        return 0;
    }

    // Recursive case: Check the current node's item and proceed to the next node
    int count = (currentNode->item == item) ? 1 : 0;
    return count + countRHelper(currentNode->next, item);
}



// Reverse the list using recursion
/*
Time copmlexity: O(n) due to traversal of the list
Space complexity: O(n) due to n frames in the call stack
*/
void List::reverseR() {
    // Start the recursive reversal process
    reverseRHelper(front);
}

List::Node* List::reverseRHelper(Node* node) {
    // Base case: If the list is empty or only one node remains
    if (node == nullptr) {
        return nullptr; // Return for an empty list
    }
    if (node->next == nullptr) {
        front = node; // Update the head of the list
        return node;  // Return the last node, which will become the first
    }

    // Recursive step: Reverse the rest of the list
    List::Node* lastNode = reverseRHelper(node->next);

    // Adjust the pointers for the current node
    lastNode->next = node; // Set the next of the last node in reversed sublist
    node->next = nullptr;  // Current node becomes the tail in reversed sublist

    return node; // Return the current node
}


// Search for an item in the list using recursion
/*
Time complexity: O(n) due to traversal of the list
Space complexity: O(n) due to n frames in the call stack
*/
bool search(struct Node* front, int x) {
    // Base case: If the list is empty, return false
    if (front == nullptr) {
        return false;
    }

    // Check if the current node contains the target value
    if (front->item == x) {
        return true; // Key found
    }

    // Recur for the remaining nodes
    return search(front->next, x);
}


// Calculate the sum of all items in the list using recursion
/*
Time complexity: O(n) due to traversal of the list
Space complexity: O(n) due to n frames in the call stack
*/
int List::sumList(Node* head) {
    // Base case: If the list is empty or we reach the end, return 0
    if (head == nullptr) {
        return 0;
    }

    // Recursive case: Sum the current node's item with the sum of the rest of the list
    return head->item + sumList(head->next);
}


// Display the list recursively
/*
Time complexity: O(n) due to traversal of the list
Space complexity: O(n) due to n frames in the call stack
*/
void List::displayRecursively(Node* current) {
    // Base case: If the current node is null, stop the recursion
    if (current == nullptr) {
        return;
    }

    // Print the current node's data
    cout << current->data << endl;

    // Recur for the next node
    displayRecursively(current->next);
}

// Find the maximum item in the list using recursion
/*
Time complexity: O(n) due to traversal of the list
Space complexity: O(n) due to n frames in the call stack
*/
int List::findLargest(Node* current) {
    // Base case: If this is the last node, return its value
    if (current->next == nullptr) {
        return current->item;
    }

    // Recursive call to find the largest value in the remaining list
    int largestInRest = findLargest(current->next);

    // Return the larger value between the current node's item and the largest in the rest
    return (current->item > largestInRest) ? current->item : largestInRest;
}

// Calculate the sum of all even items in the list using recursion
/*
Time complexity: O(n) due to traversal of the list
Space complexity: O(n) due to n frames in the call stack
*/
int Sum(Node* head) {
    // Base case: If the list is empty, return 0
    if (head == nullptr) {
        return 0;
    }

    // Recursive case: Check if the current node's data is even
    if (head->data % 2 == 0) {
        // Add the current node's value if it is even
        return head->data + Sum(head->next);
    } else {
        // Skip the current node's value if it is odd
        return Sum(head->next);
    }
}


// Sort the list in ascending order using recursion
// Split the list into two halves
List::Node* List::split(Node* head) {
    // Slow and fast pointers to find the middle of the list
    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    // Use slow-fast pointer technique to find the middle of the list
    while (fast != nullptr && fast->next != nullptr) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    if (prev != nullptr) {
        prev->next = nullptr;
    }
    return slow;
}

// Merge two sorted lists into a single sorted list
List::Node* List::merge(Node* left, Node* right) {
    // Base cases : If either list is empty, return the other list
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }

    // Compare the data and recursively merge the lists
    if (left->item <= right->item) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

// Sort the linked list using Merge Sort
/*
Time Complexity: O(n log n) due to the divide and conquer approach
Space Complexity: O(log n) due to recursion depth
*/

List::Node* List::sort(Node* head) {
    // Base case : If the list is empty or has only one node, its already sorted
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Split the list into two halves
    Node* mid = split(head);

    // Recursively sort the two halves
    Node* left = sort(head);
    Node* right = sort(mid);

    // Merge the sorted halves
    return merge(left, right);
}
