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

    // Method to append a new node to the linked list
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

    void prepend (int value) {
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
    
    // Method to delete the first node
    void deleteFirst () {
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

    // Get a node at particular index
    Node* get (int index) {
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

    // Set a value at a particular index
    bool set (int index, int value) {
        // Get the node at the index
        Node* temp = get(index);
        // Check if temp is pointing to a node
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    // Insert a value at a particular index
    bool insert (int index, int value) {
         // Check if index is negative or exceeds length of LinkedList
        if (index < 0 || index > length) return false;
        // If index = 0, call prepend method
        if (index == 0) {
           prepend(value);
           return true;
        }
        // If index = length of linked ist, call append method
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

    // Remove a node at a particular index
    void deleteNode (int index) {
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
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();
    myLinkedList->append(2);

    myLinkedList->printList();
}