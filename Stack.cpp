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

class Stack
{
private:
    Node *top;
    int height;

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
};

int main()
{
    Stack *myStack = new Stack(4);

    myStack->getTop();
    myStack->getHeight();

    cout << "\nStack:\n";
    myStack->printStack();
}
