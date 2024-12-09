/*
void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.

Implemented stack utilising queue
*/

#include <iostream>
#include <queue>
using namespace std;

class MyStack {

private:
    queue<int> queue;

public:
    MyStack() {
        // Constructor to intialise the stack
    }
    
    void push(int x) {
        // Method to push an element to the stack
        queue.push(x);
        // Rotate the queue to make the last element the first element
        int size = queue.size();
        // Rotate the queue to make the last element the first element
        for (int i = 0; i < size - 1; i++) {
            queue.push(queue.front());
            queue.pop();
        }
        
    }
    
    int pop() {
        // Method to remove the top element from the stack
        int top = queue.front();
        queue.pop();
        return top;
        
    }
    
    int top() {
        // Method to return the top element of the stack
        return queue.front();
    }
    
    bool empty() {
        // Method to check if the stack is empty
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */