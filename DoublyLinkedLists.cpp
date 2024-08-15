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
        this->next = nullptr;
        this->prev = nullptr;
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
        while (temp != nullptr)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead()
    {
        if (head == nullptr)
        {
            cout << "Head: nullptr" << endl;
        }
        else
        {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail()
    {
        if (tail == nullptr)
        {
            cout << "Tail: nullptr" << endl;
        }
        else
        {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    // Append a new node to the end of the linked list
    // O(1) time complexity
    // O(1) space complexity
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
            // Set the next node of the current tail to the new node
            tail->next = newNode;
            // Set the previous node of the new node to the current tail
            newNode->prev = tail;
            // Set the tail to the new node
            tail = newNode;
        }
        // Increment the length
        length++;
    }

    // Delete the last node of the linked list
    // O(1) time complexity
    // O(1) space complexity
    void deleteLast()
    {
        if (length == 0)
            return;
        // Temp variable
        Node *temp = tail;
        // Fringe case if linked list is 1 node
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            // Set the tail to the previous node of the current tail
            tail = tail->prev;
            // Set the next node of the new tail to nullptr
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    // Prepend a new node to the beginning of the linked list
    // O(1) time complexity
    // O(1) space complexity
    void prepend(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // Set the newNodes next node to the current head
            newNode->next = head;
            // Set the previous node of head to newNode
            head->prev = newNode;
            // Set the head to the newNode
            head = newNode;
        }
        length++;
    }

    // Delete the first node of the linked list
    // O(1) time complexity
    // O(1) space complexity
    void deleteFirst()
    {
        if (length == 0)
            return;
        Node *temp = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            // Set the head to the next node of the current head
            head = head->next;
            // Set the previous node of the new head to nullptr
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

    // Get the node at the specified index
    // O(n) time complexity
    // O(1) space complexity
    Node *get(int index)
    {
        // Check if the index is valid
        if (index < 0 || index >= length)
            return nullptr;
        // Create a temp variable
        Node *temp = head;
        if (index < length / 2) // If the index is closer to the start of the list
        {
            // Loop through the list from the start to the index
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else // If the index is closer to the end of the list
        {
            temp = tail;
            // Loop through the list from the end to the index
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        return temp;
    }

    // Set the value of the node at the specified index
    // O(n) time complexity
    // O(1) space complexity
    bool set(int index, int value)
    {
        Node *temp = get(index);
        if (temp)
        {
            // Set the value of the node at the specified index
            temp->value = value;
            return true;
        }
        return false;
    }

    // Insert a new node at the specified index
    // O(n) time complexity
    // O(1) space complexity
    bool insert(int index, int value)
    {
        // Check if the index is valid
        if (index < 0 || index > length)
            return false;
        // If the index is at the start of the list
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }
        // Create nodes, befor and after and newNode
        Node *newNode = new Node(value);
        // Get the node before the index
        Node *before = get(index - 1);
        // Get the node after the index, faster because O(1)
        Node *after = before->next;
        // Set the prev node of the new node to before
        newNode->prev = before;
        // Set the next node of the new node to after
        newNode->next = after;
        // Set the next node of before to the new node
        before->next = newNode;
        // Set the prev node of after to the new node
        after->prev = newNode;
        // Increment the length
        length++;
        return true;
    }

    // Remove the node at the specified index
    // O(n) time complexity
    // O(1) space complexity
    void deleteNode(int index)
    {
        // Check if the index is valid
        if (index < 0 || index >= length)
            return;
        // If the index is at the start of the list
        if (index == 0)
            return deleteFirst();
        // If the index is at the end of the list
        if (index == length - 1)
            return deleteLast();
        // Create temp variable
        Node *temp = get(index);
        // Set the next node of the previous node to the next node of the current node
        temp->next->prev = temp->prev;
        // Set the previous node of the next node to the previous node of the current node
        temp->prev->next = temp->next;
        // Delete the current node
        delete temp;
        // Decrement the length
        length--;
    }
};

int main()
{

    DoublyLinkedList *myDLL = new DoublyLinkedList(7);

    myDLL->getHead();
    myDLL->getTail();
    myDLL->getLength();

    cout << "\nDoubly Linked List:\n";
    myDLL->printList();
}
