/*
void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.

Implement queue using stack
*/
#include <iostream>
#include <stack>

using namespace std;
class MyQueue {
private:
    stack<int> inputStack,
                outputStack;
public:
    MyQueue() {
        // Constructor
    }
    
    void push(int x) {
        // Push element onto the input stack
        inputStack.push(x);
    }
    
    int pop() {
        // Ensure output stack is not empty
        if (outputStack.empty()) {
            // Move elements from input stack to output stack
            while (!inputStack.empty()) {
                // Push elements from input stack to output stack
                outputStack.push(inputStack.top());
                // Pop elements from input stack
                inputStack.pop();
            }
        }
        // Pop element from output stack
        int topElement = outputStack.top();
        // Remove the front element
        outputStack.pop();
        // Return the front element
        return topElement;
    }
    
    int peek() {
        // Ensure output stack is not empty
        if (outputStack.empty()) {
            // Move elements from input stack to output stack
            while(!inputStack.empty()) {
                // Push elements from input stack to output stack
                outputStack.push(inputStack.top());
                // Pop elements from input stack
                inputStack.pop();
            }
        }
        // Return the front element
        return outputStack.top();
    }
    
    bool empty() {
        // Return true if both stacks are empty
        return inputStack.empty() && outputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */