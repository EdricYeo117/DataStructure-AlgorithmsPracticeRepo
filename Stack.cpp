#include <iostream>
using namespace std;

// Stack Class
// Last In First Out
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

class Stack
{
private:
    Node *top;
    int height;
    // Constructor
public:
    Stack(int value)
    {
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    ~Stack()
    {
        Node *temp = top;
        while (top)
        {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    void printStack()
    {
        Node *temp = top;
        while (temp)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getTop()
    {
        if (top == nullptr)
        {
            cout << "Top: nullptr" << endl;
        }
        else
        {
            cout << "Top: " << top->value << endl;
        }
    }

    void getHeight()
    {
        cout << "Height: " << height << endl;
    }

    // Push a new node to the stack
    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    // Pop the top node from the stack, returns the value (can be edited to use void)
    int pop()
    {
        if (height == 0)
            return INT_MIN;
        // Create a temp node to store the top node
        Node *temp = top;
        // Store the value of the top node
        int poppedValue = top->value;
        // Move the top node to the next node
        top = top->next;
        delete temp;
        height--;
        return poppedValue;
    }
};

int main()
{
    Stack *myStack = new Stack(4);

    // Initial state
    myStack->getTop();    // Should print 4
    myStack->getHeight(); // Should print 1

    // Print initial stack
    cout << "\nStack:\n";
    myStack->printStack(); // Should print 4

    // Push more elements
    myStack->push(8);
    myStack->push(12);
    myStack->push(16);

    // State after pushing
    myStack->getTop();    // Should print 16
    myStack->getHeight(); // Should print 4

    // Print stack after pushing
    cout << "\nStack after pushing 8, 12, 16:\n";
    myStack->printStack(); // Should print 16, 12, 8, 4

    // Pop some elements
    cout << "\nPopped value: " << myStack->pop() << endl; // Should print 16
    cout << "Popped value: " << myStack->pop() << endl;   // Should print 12

    // State after popping
    myStack->getTop();    // Should print 8
    myStack->getHeight(); // Should print 2

    // Print stack after popping
    cout << "\nStack after popping two elements:\n";
    myStack->printStack(); // Should print 8, 4

    // Pop remaining elements
    cout << "\nPopped value: " << myStack->pop() << endl; // Should print 8
    cout << "Popped value: " << myStack->pop() << endl;   // Should print 4

    // State after popping all elements
    myStack->getTop();    // Should print nullptr
    myStack->getHeight(); // Should print 0

    // Print stack after all elements are popped
    cout << "\nStack after popping all elements:\n";
    myStack->printStack(); // Should print nothing

    // Test pop on empty stack
    cout << "\nPopped value from empty stack: " << myStack->pop() << endl; // Should print INT_MIN

    // Clean up
    delete myStack;

    return 0;
}
