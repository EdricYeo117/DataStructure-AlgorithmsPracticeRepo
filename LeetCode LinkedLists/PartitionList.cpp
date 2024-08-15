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
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
        }

        Node* getHead() {
            return head;
        }

        int getLength() {
            return length;
        }
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }

void partitionList(int x) {
    // Return if the list is empty
    if (head == nullptr) return;
 
    // Create dummy nodes for two lists
    Node dummy1(0);
    Node dummy2(0);
    // Initialize pointers for two lists
    // prev1 pointer set to address of dummy node1, prev2 pointer set to addres of dummy node2
    Node* prev1 = &dummy1;
    Node* prev2 = &dummy2;
    // Initialize the current pointer
    // current pointer set to head
    Node* current = head;
 
    // Iterate through the list
    // Iterates through the list until the current pointer is not null
    while (current != nullptr) {
        // If the value is less than x
        if (current->value < x) {
            // Next pointer of prev1 node is updated to the point of current node;
            prev1->next = current;
            // prev1 pointer is updated to the current node, moves iteration forward
            prev1 = current;
        } else { // If the value is >= x
            // Next pointer of prev2 node is updated to the point of current node;
            prev2->next = current;
            // prev2 pointer is updated to the current node, moves iteration forward
            prev2 = current;
        }
        // Move to the next node
        current = current->next;
    }
 
    // Terminate the second list
    prev2->next = nullptr;
    // Connect the two lists
    prev1->next = dummy2.next;
    // Update the head of the list
    head = dummy1.next;
}
};


