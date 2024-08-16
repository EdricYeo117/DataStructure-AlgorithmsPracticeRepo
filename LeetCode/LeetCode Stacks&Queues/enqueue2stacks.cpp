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

  // Method to add an element to the end of the queue
    void enqueue(int value) {
        stack1.push(value); // Simply push the new value onto stack1
    }
    
};


