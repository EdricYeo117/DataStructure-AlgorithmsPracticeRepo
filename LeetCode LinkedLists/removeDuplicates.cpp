#include <iostream>
#include <unordered_set>

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

void removeDuplicates() {
    Node* current = head; // Start at the head of the list
    while (current != nullptr) { // Iterate through the list
        Node* runner = current; // Secondary iterator
        // Check all subsequent nodes
        while (runner->next != nullptr) { 
            // If a duplicate is found
            if (runner->next->value == current->value) {
                Node* temp = runner->next; // Temp node for deletion
                // Bypass the node to be deleted
                runner->next = runner->next->next;
                delete temp; // Delete the node
                length -= 1; // Decrement length
            } else {
                runner = runner->next; // Move to next node
            }
        }
        current = current->next; // Move to next node
    }
}

};


