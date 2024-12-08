#include <stack>
#include <climits>

using namespace std;

class QueueUsingTwoStacks {
private:
    stack<int> stack1, stack2;

public:
    int front() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        if (stack2.empty()) {
            return INT_MIN;
        }

        return stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }

    void enqueue(int value) {
        stack1.push(value);
    }

   // Method to remove the front element from the queue
    void dequeue() {
        if (stack2.empty()) {
            // Transfer elements from stack1 to stack2 to reverse their order
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        // If stack2 is still empty, the queue is empty
        if (stack2.empty()) {
            return; // or handle empty queue case as needed
        }

        stack2.pop(); // Remove the top element from stack2
    }
    
};


