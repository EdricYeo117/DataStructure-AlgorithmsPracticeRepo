#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList()
    {
        Node *temp = head;
        if (temp == nullptr)
        {
            cout << "empty" << endl;
            return;
        }
        while (temp->next != nullptr)
        {
            cout << temp->value << " <-> ";
            temp = temp->next;
        }
        cout << temp->value << endl;
    }

    Node *getHead()
    {
        return head;
    }

    Node *getTail()
    {
        return tail;
    }

    int getLength()
    {
        return length;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void swapPairs()
    {
        // If the list is empty or has only one node, do nothing
        if (length <= 1)
        {
            return;
        }

        // Create a dummy node to handle edge cases smoothly, especially when the head is involved in a swap
        Node *dummyNode = new Node(0);
        dummyNode->next = head; // Point the dummy node's next to the current head
        head->prev = dummyNode; // Set the current head's prev to the dummy node

        Node *current = dummyNode; // Start from the dummy node

        // Loop through the list, swapping nodes in pairs
        while (current->next != nullptr && current->next->next != nullptr)
        {
            Node *first = current->next;        // First node in the pair
            Node *second = current->next->next; // Second node in the pair

            // Adjust the first node's next pointer to skip the second node
            first->next = second->next;
            if (second->next != nullptr)
            {
                second->next->prev = first; // If the second node has a next, update its prev pointer
            }

            // Link the second node's prev pointer to the first node's prev
            second->prev = first->prev;
            first->prev->next = second; // Link the first node's previous node's next pointer to the second node

            // Adjust the second node's next pointer to point to the first node, completing the swap
            second->next = first;
            first->prev = second; // Update the first node's prev pointer to point to the second node

            // Move current to the first node (which is now the second node in the original list)
            current = first;
        }

        // After all pairs are swapped, update the head pointer to point to the new head (first node after the dummy node)
        head = dummyNode->next;
        head->prev = nullptr; // Ensure the new head's prev pointer is null

        // Update the tail pointer
        if (tail == head->next)
        { // If the list had exactly two nodes, update tail to point to the first node
            tail = head;
        }
        else
        {
            // Otherwise, traverse to the last node and update the tail pointer
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            tail = temp;
        }

        // Delete the dummy node to free memory
        delete dummyNode;
    }
};
