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
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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
        
        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            tail = nullptr;
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
        }
    
    // Solution
      Node* findMiddleNode() {
        // Initialize two pointers, slow and fast, both pointing to the head of the linked list.
          Node* slow = head;
          Node* fast = head;
          /* Traverse the linked list using a while loop.
          The loop continues as long as fast is not nullptr (i.e., it has not reached the end of the list), 
          and fast->next is also not nullptr (i.e., there is at least one more node after the current fast node). */
          while (fast != nullptr && fast-> next != nullptr) {
            /* Inside the loop, move the slow pointer one step forward (i.e., slow = slow->next) 
            and the fast pointer two steps forward (i.e., fast = fast->next->next).*/
              slow = slow->next;
              fast = fast->next->next;
              /* Since the fast pointer moves twice as fast as the slow pointer,
               by the time the fast pointer reaches the end of the list or goes beyond it, the slow pointer will be at the middle node.*/
          }
          // When the loop terminates, return the slow pointer, which now points to the middle node.
        return slow;
      }

};


