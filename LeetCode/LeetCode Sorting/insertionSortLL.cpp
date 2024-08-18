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
        
void insertionSort() {
    if (length <= 1) return; // If the list is empty or has only one element, it's already sorted

    Node* sorted = nullptr; // Pointer to the sorted part of the list
    Node* current = head;   // Pointer to traverse the unsorted part of the list

    while (current != nullptr) {
        Node* nextNode = current->next; // Store the next node to move forward in the original list
        
        // Insert current node into the sorted part of the list
        if (sorted == nullptr || sorted->value >= current->value) {
            // Insert at the beginning of the sorted list
            current->next = sorted;
            sorted = current;
        } else {
            // Traverse the sorted list to find the correct position
            Node* temp = sorted;
            while (temp->next != nullptr && temp->next->value < current->value) {
                temp = temp->next;
            }
            // Insert the current node after the temp node
            current->next = temp->next;
            temp->next = current;
        }

        // Move to the next node in the original list
        current = nextNode;
    }

    // Update head to point to the sorted list
    head = sorted;

    // Update tail to point to the last node in the sorted list
    tail = sorted;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
}


};


