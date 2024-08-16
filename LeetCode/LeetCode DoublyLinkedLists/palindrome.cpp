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

    bool isPalindrome()
    {
        // A list with 0 or 1 node is a palindrome
        if (length <= 1)
        {
            return true;
        }

        Node *forwardNode = head;
        Node *backwardNode = tail;

        // Loop from the start to the middle of the list
        while (forwardNode != nullptr && backwardNode != nullptr)
        {
            // Compare forwardNode and backwardNode values
            if (forwardNode->value != backwardNode->value)
            {
                return false;
            }

            // Move the pointers
            forwardNode = forwardNode->next;
            backwardNode = backwardNode->prev;

            // Break the loop when the nodes cross or meet in the middle
            if (forwardNode == backwardNode || forwardNode->prev == backwardNode)
            {
                break;
            }
        }

        return true;
    }
};
