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

    int binaryToDecimal()
    {
        // Initialize a pointer to traverse the linked list
        Node *current = head;

        // Initialize a variable to store the decimal value
        int decimalValue = 0;

        // Iterate through the linked list
        while (current != nullptr)
        {
            // Shift the decimal value left by one bit and add the current digit
            decimalValue = decimalValue * 2 + current->value;

            // Move to the next node
            current = current->next;
        }

        // Return the calculated decimal value
        return decimalValue;
    }
};
