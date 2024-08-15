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
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }
      // Solution: Uses Floyd's Cycle Detection Algorithm
      // Time Complexity: O(n)
      // Space Complexity: O(1)
      bool hasLoop () {
        // Create two pointers, slow and fast, both initially pointing to the head of the linked list.
          Node* slow = head;
          Node* fast = head;
        // Loop until the end of the list is reached
        /*Start a while loop that continues as long as the fast pointer is not null and the next node of the fast pointer is not null. 
        The loop will break if either of these conditions is false, indicating that the end of the list has been reached, and thus there is no loop.*/
         while (fast != nullptr && fast->next != nullptr) {
             // Move slow pointer one step forward
             slow = slow->next;
             // Move fast pointer two steps forward
             fast = fast->next->next;
             // Check if slow and fast pointers meet
             if (slow == fast) {
                 // A loop is found, return true
                 return true;
             }
         }
        // No loop is found, return false
        return false;
      }

};


