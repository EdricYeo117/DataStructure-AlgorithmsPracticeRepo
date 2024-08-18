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

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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

        Node* getTail() {
            return tail; 
        }

        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

       void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
        
void selectionSort() {
    if (length <= 1) return; // If the list is empty or has only one element, it's already sorted

    Node* current = head; // Pointer to traverse the list

    // Outer loop - Traverse through the list
    while (current != nullptr) {
        Node* smallest = current; // Assume the current node is the smallest
        Node* nextNode = current->next; // Pointer to the next node

        // Inner loop - Find the smallest element in the remaining unsorted part
        while (nextNode != nullptr) {
            if (nextNode->value < smallest->value) {
                smallest = nextNode; // Update the smallest node
            }
            nextNode = nextNode->next; // Move to the next node
        }

        // Swap the values of the current node and the smallest node found
        if (smallest != current) {
            int temp = current->value;
            current->value = smallest->value;
            smallest->value = temp;
        }

        // Move to the next node in the list
        current = current->next;
    }
}


};


