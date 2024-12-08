#include <stack>
#include <string>

using namespace std;

bool isBalancedParentheses(const string& parentheses) {
    stack<char> charStack;

    for (char ch : parentheses) {
        if (ch == '(') {
            charStack.push(ch);  // Push open parenthesis onto stack
        } else if (ch == ')') {
            if (charStack.empty() || charStack.top() != '(') {
                return false;  // Unbalanced if stack is empty or top is not matching
            }
            charStack.pop();  // Pop the matching open parenthesis
        }
    }

    // If the stack is empty, all parentheses are balanced
    return charStack.empty();
}
