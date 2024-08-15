#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        length = 1;
    }

    ~LinkedList()
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
            cout << "empty";
        }
        else
        {
            while (temp != nullptr)
            {
                cout << temp->value;
                temp = temp->next;
                if (temp != nullptr)
                {
                    cout << " -> ";
                }
            }
        }
        cout << endl;
    }

    Node *getHead()
    {
        return head;
    }

    int getLength()
    {
        return length;
    }

    void makeEmpty()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
        length = 0;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *currentNode = head;
            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = newNode;
        }
        length++;
    }

    void deleteFirst()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }

    void reverseBetween(int m, int n)
    {
        // 1. Initial Check:
        // If the list is empty, there's nothing to reverse.
        // So, exit the function without doing anything.
        if (head == nullptr)
            return;

        // 2. Dummy Node Creation:
        // We initiate a new 'dummy' node with value 0.
        // This is a trick to simplify the edge cases.
        Node *dummy = new Node(0);

        // Connect our actual list right after the dummy node.
        // So, the dummy node temporarily stands before the head.
        dummy->next = head;

        // 3. Positioning 'prev':
        // Start with 'prev' pointing to the dummy node.
        Node *prev = dummy;

        // Move 'prev' up to the node just before the starting
        // point of the section we want to reverse.
        for (int i = 0; i < m; i++)
        {
            prev = prev->next;
        }

        // 4. Setting up 'current':
        // 'current' is set right after 'prev'.
        // It marks the start of the section to be reversed.
        Node *current = prev->next;

        // 5. Main Reversal Logic:
        // We now enter our core reversal loop.
        for (int i = 0; i < n - m; i++)
        {
            // 'temp' points to the node that's next in line
            // for our reversal process.
            Node *temp = current->next;

            // Detach 'temp' from the current sequence by
            // making 'current' skip over 'temp'.
            current->next = temp->next;

            // To move 'temp' to the start of our reversed section,
            // we first let 'temp' point to whatever node 'prev' is pointing to.
            temp->next = prev->next;

            // Finally, we adjust 'prev' to point to 'temp', thereby
            // moving 'temp' to the front of the reversed section.
            prev->next = temp;
        }

        // 6. Updating Head:
        // If our reversed section included the original head of the list,
        // our list's head would have changed.
        // So, we need to update the head of our list.
        head = dummy->next;

        // 7. Cleanup:
        // The dummy node has served its purpose.
        // We free up its memory to avoid memory leaks.
        delete dummy;
    }
};
