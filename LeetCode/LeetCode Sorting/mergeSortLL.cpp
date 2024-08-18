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
        
void merge(LinkedList& otherList) {
    // Initialize a pointer to the head node of the
    // other linked list we are going to merge.
    Node* otherHead = otherList.getHead();
 
    // Create a 'dummy' node to serve as a starting point.
    // This will simplify handling the head of the new list.
    Node* dummy = new Node(0);
 
    // 'current' will point to the last node in our new,
    // merged list as we build it up.
    Node* current = dummy;
 
    // The loop will run as long as neither of the linked
    // lists is empty.
    while (head != nullptr && otherHead != nullptr) {
 
        // Compare the values at the heads of the two lists.
        // We will take the node with the smaller value.
        if (head->value < otherHead->value) {
            // The current node from our list is smaller.
            current->next = head; // Add it to the merged list.
            head = head->next;    // Move our list's head.
        } else {
            // The node from the other list is smaller.
            current->next = otherHead; // Add it to merged list.
            otherHead = otherHead->next; // Move other head.
        }
        // Move 'current' to the last node in our new list.
        current = current->next;
    }
 
    // At this point, one of the lists is empty. If there
    // are any elements left in the other list, we append
    // them to the end of the merged list.
    if (head != nullptr) {
        current->next = head;
        while (current->next != nullptr) {
            current = current->next; // Move to list's end.
        }
    } else {
        current->next = otherHead;
        while (current->next != nullptr) {
            current = current->next; // Move to list's end.
        }
    }
 
    // Final housekeeping steps. Point our list's head to the
    // first real element, update the tail, and delete dummy.
    tail = current;
    head = dummy->next;
    delete dummy;
 
    // Update the length of our list by adding the length
    // of the other list.
    length += otherList.getLength();
 
    // Clear the other list as it's now merged into ours.
    otherList.head = nullptr;
    otherList.tail = nullptr;
    otherList.length = 0;
}
		
};


