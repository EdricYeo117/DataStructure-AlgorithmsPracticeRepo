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
    int length;

public:
    LinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
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
            tail = newNode;
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
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete temp;
        length--;
    }

    void recursiveInsertionSortHelper(Node *&sorted, Node *current)
    {
        if (current == nullptr)
        {
            return; // Base case: No more nodes to process
        }

        Node *nextNode = current->next; // Store the next node

        // Insert current node into the sorted part of the list
        if (sorted == nullptr || sorted->value >= current->value)
        {
            // Insert at the beginning of the sorted list
            current->next = sorted;
            sorted = current;
        }
        else
        {
            // Traverse the sorted list to find the correct position
            Node *temp = sorted;
            while (temp->next != nullptr && temp->next->value < current->value)
            {
                temp = temp->next;
            }
            // Insert the current node after the temp node
            current->next = temp->next;
            temp->next = current;
        }

        // Recursively process the next node
        recursiveInsertionSortHelper(sorted, nextNode);
    }

    void insertionSort()
    {
        if (length <= 1)
            return; // If the list is empty or has only one element, it's already sorted

        Node *sorted = nullptr;                     // Pointer to the sorted part of the list
        recursiveInsertionSortHelper(sorted, head); // Start the recursive sorting

        // Update head to point to the sorted list
        head = sorted;

        // Update tail to point to the last node in the sorted list
        tail = sorted;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }
    }
};

/*
template <typename ItemType>
void recursiveSelectionSort(Node<ItemType>* current, ItemType item) {
    if (current == nullptr || current->next == nullptr) {
        // Base case: If the list is empty or has one element, it's already sorted
        return;
    }

    Node<ItemType>* smallest = current; // Assume the current node is the smallest
    Node<ItemType>* nextNode = current->next;

    // Find the smallest element in the remaining list
    while (nextNode != nullptr) {
        if (nextNode->value < smallest->value) {
            smallest = nextNode; // Update the smallest node
        }
        nextNode = nextNode->next;
    }

    // Swap the values of the current node and the smallest node found
    if (smallest != current) {
        item = current->value;
        current->value = smallest->value;
        smallest->value = item;
    }

    // Recursively sort the rest of the list
    recursiveSelectionSort(current->next, item);
}

// Wrapper function to start the sorting process
template <typename ItemType>
void selectionSort(ItemType item) {
    // Assuming `head` and `length` are accessible globally
    if (length <= 1) return; // If the list is empty or has one element, it's already sorted
    recursiveSelectionSort(head, item); // Start recursive sorting
}

*/