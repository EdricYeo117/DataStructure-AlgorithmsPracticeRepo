#include <iostream>
using namespace std;

class Node {
    public: 
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
    Node* head;
    Node* tail;
    int length;

    // Constructor
    public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    // Destructor
    ~LinkedList() {
        // Temp variable
        Node* temp = head;
        // Loop through the linked list
        while (head) {
            // Moves the head to the next node
            head = head->next;
            // Removes the temp node from memory
            delete temp;
            // Moves the temp to the new head
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl; 
            temp = temp->next;
        }
    }

    void getHead() {
        cout << "Head: " << head->value << endl;
    }

    void getTail() {
        cout << "Tail: " << tail->value << endl;
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

       // Append a new node - O(1)
    void append(int value) {
        Node* newNode = new Node(value);
        // Check if the linked list is empty
        if (length == 0) {
            // Set the head and tail to the new node
            head = newNode;
            tail = newNode;
        } else {
            // Set the next node of the tail to the new node
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    
    // Delete the last node - O(n)
    void deleteLast() {
        // Check if the linked list is empty
        if (length == 0) return;
        Node* temp = head;
        // Fringe case if linked list is 1 node
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
        Node* pre = head;
        // While loop checks if temp is pointing to another node
        while (temp->next) {
            // This checks if pre node = temp node
            pre = temp;
            // Moves the temp node to the next node
            temp = temp->next;
        }
        // Set the tail to the pre node
        tail = pre;
        // Set the next node of the pre node to nullptr
        tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    // Prepend a new node - O(1)
    void prepend(int value) {
        // Create node 
        Node* newNode = new Node(value);
        // Check if the linked list is empty
        if (length == 0) {
            // Set head to new node
            head = newNode;
            // Set tail to new node
            tail = newNode;
        } else {
            // Set the next node of new node to head
            newNode->next = head;
            // Set the head to new node
            head = newNode;
        }
        length++;
    }
    
    // Delete the first node - O(1)
    void deleteFirst() {
        // Check if the linked list is empty
        if (length == 0) return;
        // Create a temp node, set to head
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            // Moves the head to the next node
            head = head->next;
        }
        delete temp;
        length--;
    }

    // Get a node at a particular index - O(n)
    Node* get(int index) {
        // Checks if index is negative or exceeds length of LinkedList
        if (index < 0 || index >= length) {
            return nullptr;
        }
        // Create a temp node, set to head
        Node* temp = head;
        // Iterate through the loop until the index is reached
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp;
    }

    // Set a value at a particular index - O(n)
    bool set(int index, int value) {
        // Get the node at the index
        Node* temp = get(index);
        // Check if temp is pointing to a node
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    // Insert a value at a particular index - O(n)
    bool insert(int index, int value) {
         // Check if index is negative or exceeds length of LinkedList
        if (index < 0 || index > length) return false;
        // If index = 0, call prepend method
        if (index == 0) {
           prepend(value);
           return true;
        }
        // If index = length of linked list, call append method
        if (index == length) {
            append(value);
            return true;
        }
        // Create a new Node
        Node* newNode = new Node(value);
        // Get the node, right before intended index, set to temp
        Node* temp = get(index - 1);
        // Set the next node of the new node, to the correct node in the linked list
        newNode->next = temp->next;
        // Set the next node of the temp node to the new node
        temp->next = newNode;
        length++;
        return true;
    }

    // Remove a node at a particular index - O(n)
    void deleteNode(int index) {
        // Check if index is negative or exceeds length of LinkedList
        if (index < 0 || index >= length) return;
        // Check if index = 0
        if (index == 0) return deleteFirst();
        // Check if index = length of linked list
        if (index == length - 1) return deleteLast();
        // Get the node, right before intended index, set to prev
        Node* prev = get(index - 1);
        // Get the node at the index, which is temp
        Node* temp = prev->next;
        // Set the next node of prev to the next node of temp
        prev->next = temp->next;
        // Delete the temp node
        delete temp;
        // Decrement the length of the linked list
        length--;
    }

    // Reverse the linked list - O(n)
    void reverse() {
        // Create a temp node, set to head
        Node* temp = head;
        // Set the head to the tail
        head = tail;
        // Set the tail to the temp node
        tail = temp;
        // Create an after node, set to temp->next
        Node* after = temp->next;
        // Create a before node, set to nullptr
        Node* before = nullptr;
        // Loop through the linked list
        for (int i = 0; i < length; i++) {
            // Set the before node to the temp node
            // After must be set to the next node, before temp is set to the next node, so the linked list doesn't break
            after = temp->next;
            // Flips pointer to the previous node
            temp->next = before;
            // Moves the before node to the temp node
            before = temp;
            // Moves the temp node to the after node, lets the loop continue, because temp must move to the next node
            temp = after;
        }
    }
};

int main() {
    // Create a new LinkedList with an initial value
    LinkedList* myLinkedList = new LinkedList(4);

    // Test the getHead, getTail, and getLength functions
    cout << "Initial state:" << endl;
    myLinkedList->getHead();    // Expected: Head: 4
    myLinkedList->getTail();    // Expected: Tail: 4
    myLinkedList->getLength();  // Expected: Length: 1

    // Append a new node with value 2
    myLinkedList->append(2);

    cout << "\nAfter appending 2:" << endl;
    myLinkedList->getHead();    // Expected: Head: 4
    myLinkedList->getTail();    // Expected: Tail: 2
    myLinkedList->getLength();  // Expected: Length: 2
    myLinkedList->printList();  // Expected: 4 2

    // Prepend a new node with value 6
    myLinkedList->prepend(6);

    cout << "\nAfter prepending 6:" << endl;
    myLinkedList->getHead();    // Expected: Head: 6
    myLinkedList->getTail();    // Expected: Tail: 2
    myLinkedList->getLength();  // Expected: Length: 3
    myLinkedList->printList();  // Expected: 6 4 2

    // Insert a new node with value 10 at index 1
    myLinkedList->insert(1, 10);

    cout << "\nAfter inserting 10 at index 1:" << endl;
    myLinkedList->getHead();    // Expected: Head: 6
    myLinkedList->getTail();    // Expected: Tail: 2
    myLinkedList->getLength();  // Expected: Length: 4
    myLinkedList->printList();  // Expected: 6 10 4 2

    // Delete the node at index 2
    myLinkedList->deleteNode(2);

    cout << "\nAfter deleting the node at index 2:" << endl;
    myLinkedList->getHead();    // Expected: Head: 6
    myLinkedList->getTail();    // Expected: Tail: 2
    myLinkedList->getLength();  // Expected: Length: 3
    myLinkedList->printList();  // Expected: 6 10 2

    // Reverse the linked list
    myLinkedList->reverse();

    cout << "\nAfter reversing the linked list:" << endl;
    myLinkedList->getHead();    // Expected: Head: 2
    myLinkedList->getTail();    // Expected: Tail: 6
    myLinkedList->getLength();  // Expected: Length: 3
    myLinkedList->printList();  // Expected: 2 10 6

    // Delete the first node
    myLinkedList->deleteFirst();

    cout << "\nAfter deleting the first node:" << endl;
    myLinkedList->getHead();    // Expected: Head: 10
    myLinkedList->getTail();    // Expected: Tail: 6
    myLinkedList->getLength();  // Expected: Length: 2
    myLinkedList->printList();  // Expected: 10 6

    // Delete the last node
    myLinkedList->deleteLast();

    cout << "\nAfter deleting the last node:" << endl;
    myLinkedList->getHead();    // Expected: Head: 10
    myLinkedList->getTail();    // Expected: Tail: 10
    myLinkedList->getLength();  // Expected: Length: 1
    myLinkedList->printList();  // Expected: 10

    // Clean up
    delete myLinkedList;

    /*
        EXPECTED OUTPUT:
        ----------------
        Initial state:
        Head: 4
        Tail: 4
        Length: 1

        After appending 2:
        Head: 4
        Tail: 2
        Length: 2
        4
        2

        After prepending 6:
        Head: 6
        Tail: 2
        Length: 3
        6
        4
        2

        After inserting 10 at index 1:
        Head: 6
        Tail: 2
        Length: 4
        6
        10
        4
        2

        After deleting the node at index 2:
        Head: 6
        Tail: 2
        Length: 3
        6
        10
        2

        After reversing the linked list:
        Head: 2
        Tail: 6
        Length: 3
        2
        10
        6

        After deleting the first node:
        Head: 10
        Tail: 6
        Length: 2
        10
        6

        After deleting the last node:
        Head: 10
        Tail: 10
        Length: 1
        10
    */
}
