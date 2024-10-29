#include <bits/stdc++.h>
#include<iostream>

using namespace std;

#define MAX 1000  // Define the maximum size of the stack

// Stack class implemented using an array
class Stack {
    int top;           // Index of the top element in the stack

public:
    int a[MAX];        // Array to hold stack elements, with maximum size defined by MAX

    Stack() { top = -1; }   // Constructor to initialize top to -1, indicating an empty stack
    bool push(int x);       // Function to add an element to the stack
    int pop();              // Function to remove the top element from the stack
    int peek();             // Function to get the top element without removing it
    bool isEmpty();         // Function to check if the stack is empty
};

// Function to add an element to the stack
bool Stack::push(int x) {
    if (top >= (MAX - 1)) {           // Check if the stack is full
        cout << "Stack Overflow";     // Print overflow message if the stack is full
        return false;                 // Return false as the element cannot be pushed
    } else {
        a[++top] = x;                 // Increment top and add element to the stack
        cout << x << " pushed into stack\n";  // Print the pushed element
        return true;                  // Return true indicating successful push
    }
}

// Function to remove and return the top element from the stack
int Stack::pop() {
    if (top < 0) {                    // Check if the stack is empty
        cout << "Stack Underflow";    // Print underflow message if the stack is empty
        return 0;                     // Return 0 indicating no element to pop
    } else {
        int x = a[top--];             // Store the top element, then decrement top
        return x;                     // Return the popped element
    }
}

// Function to get the top element without removing it from the stack
int Stack::peek() {
    if (top < 0) {                    // Check if the stack is empty
        cout << "Stack is Empty";     // Print message if the stack is empty
        return 0;                     // Return 0 indicating no element at the top
    } else {
        int x = a[top];               // Get the top element
        return x;                     // Return the top element without popping it
    }
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return (top < 0);                 // Return true if top is less than 0, meaning stack is empty
}
