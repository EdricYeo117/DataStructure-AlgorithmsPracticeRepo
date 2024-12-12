#include <stack>

using namespace std;

void sortStack(stack<int>& inputStack) {
    stack<int> sortedStack;

    while (!inputStack.empty()) {
        // Pop the top element from inputStack
        int temp = inputStack.top();
        inputStack.pop();

        // While sortedStack is not empty and top of sortedStack is greater than temp
        while (!sortedStack.empty() && sortedStack.top() > temp) {
            // Move the top element from sortedStack back to inputStack
            inputStack.push(sortedStack.top());
            sortedStack.pop();
        }

        // Push the temp element into sortedStack
        sortedStack.push(temp);
    }

    // Move the sorted elements back to inputStack
    while (!sortedStack.empty()) {
        inputStack.push(sortedStack.top());
        sortedStack.pop();
    }
}
