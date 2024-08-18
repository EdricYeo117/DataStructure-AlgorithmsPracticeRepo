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
        
void bubbleSort() {
    // If the linked list is empty or has only one element, it's already sorted
    if (length <= 1) return; 

    bool swapped;           // A flag to track if any swaps were made in the current pass
    Node* current;          // Pointer used to traverse the list
    Node* sortedUntil = nullptr; // Marks the boundary where the list is already sorted

    do {
        swapped = false;    // Reset the swapped flag for the new pass
        current = head;     // Start from the head of the list

        // Traverse the list until reaching the sorted portion
        while (current->next != sortedUntil) {
            // If the current node's value is greater than the next node's value, swap them
            if (current->value > current->next->value) {
                // Swap the values of the current node and the next node
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;

                // Set the swapped flag to true to indicate a swap has occurred
                swapped = true;
            }
            // Move to the next node
            current = current->next;
        }
        // After the inner loop, the last element is in its correct position,
        // so we set sortedUntil to the current node to mark it as sorted
        sortedUntil = current; 
    } while (swapped); // Continue sorting until no swaps are made in a full pass
}


};


