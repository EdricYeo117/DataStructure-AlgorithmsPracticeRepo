#include <iostream>

using namespace std;

// Queue Class
// First In First Out
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

class Queue
{
private:
    Node *first;
    Node *last;
    int length;

public:
    Queue(int value)
    {
        Node *newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    ~Queue()
    {
        Node *temp = first;
        while (first)
        {
            first = first->next;
            delete temp;
            temp = first;
        }
    }

    void printQueue()
    {
        Node *temp = first;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getFirst()
    {
        if (first == nullptr)
        {
            cout << "First: nullptr" << endl;
        }
        else
        {
            cout << "First: " << first->value << endl;
        }
    }

    void getLast()
    {
        if (last == nullptr)
        {
            cout << "Last: nullptr" << endl;
        }
        else
        {
            cout << "Last: " << last->value << endl;
        }
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    bool isEmpty()
    {
        if (length == 0)
            return true;
        return false;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        if (length == 0)
        {
            first = newNode;
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int dequeue()
    {
        if (length == 0)
            return INT_MIN;
        Node *temp = first;
        int dequeuedValue = first->value;
        if (length == 1)
        {
            first = nullptr;
            last = nullptr;
        }
        else
        {
            first = first->next;
        }
        delete temp;
        length--;
        return dequeuedValue;
    }
};

int main()
{
    Queue *myQueue = new Queue(7);

    // Initial state
    myQueue->getFirst();  // Should print 7
    myQueue->getLast();   // Should print 7
    myQueue->getLength(); // Should print 1

    // Print initial queue
    cout << "\nQueue:\n";
    myQueue->printQueue(); // Should print 7

    // Enqueue more elements
    myQueue->enqueue(10);
    myQueue->enqueue(15);
    myQueue->enqueue(20);

    // State after enqueuing
    myQueue->getFirst();  // Should print 7
    myQueue->getLast();   // Should print 20
    myQueue->getLength(); // Should print 4

    // Print queue after enqueuing
    cout << "\nQueue after enqueuing 10, 15, 20:\n";
    myQueue->printQueue(); // Should print 7, 10, 15, 20

    // Dequeue some elements
    cout << "\nDequeued value: " << myQueue->dequeue() << endl; // Should print 7
    cout << "Dequeued value: " << myQueue->dequeue() << endl;   // Should print 10

    // State after dequeuing
    myQueue->getFirst();  // Should print 15
    myQueue->getLast();   // Should print 20
    myQueue->getLength(); // Should print 2

    // Print queue after dequeuing
    cout << "\nQueue after dequeuing two elements:\n";
    myQueue->printQueue(); // Should print 15, 20

    // Dequeue all elements
    cout << "\nDequeued value: " << myQueue->dequeue() << endl; // Should print 15
    cout << "Dequeued value: " << myQueue->dequeue() << endl;   // Should print 20

    // State after all dequeuing
    myQueue->getFirst();  // Should print nullptr
    myQueue->getLast();   // Should print nullptr
    myQueue->getLength(); // Should print 0

    // Print queue after all elements are dequeued
    cout << "\nQueue after dequeuing all elements:\n";
    myQueue->printQueue(); // Should print nothing

    // Test dequeue on empty queue
    cout << "\nDequeued value from empty queue: " << myQueue->dequeue() << endl; // Should print INT_MIN

    // Clean up
    delete myQueue;

    return 0;
}
