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
    Node *tail;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
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

    Node *getTail()
    {
        return tail;
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
        tail = nullptr;
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Function to find the kth node from the end of the list
    Node *findKthFromEnd(int k)
    {
        // Initialize slow and fast pointers to head
        Node *slow = head;
        Node *fast = head;

        // Move the fast pointer k steps ahead
        for (int i = 0; i < k; ++i)
        {
            // If fast reaches the end, k is too large
            if (fast == nullptr)
            {
                return nullptr;
            }
            // Move fast to the next node
            fast = fast->next;
        }

        // Traverse the list until fast reaches the end
        while (fast != nullptr)
        {
            // Move slow and fast pointers to the next nodes
            slow = slow->next;
            fast = fast->next;
        }

        // Return the slow pointer, now at the kth node
        // from the end of the list
        return slow;
    }
};
