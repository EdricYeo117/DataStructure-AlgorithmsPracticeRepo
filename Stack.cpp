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
        if (height == 0) return INT_MIN;
        // Create a temp node to store the top node
        Node* temp = top;
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

    myStack->getTop();
    myStack->getHeight();

    cout << "\nStack:\n";
    myStack->printStack();
}
