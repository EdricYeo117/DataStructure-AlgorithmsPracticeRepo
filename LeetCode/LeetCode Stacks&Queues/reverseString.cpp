#include <stack>
#include <string>

using namespace std;

string reverseString(const string& str) {
    stack<char> charStack;
    string reversedString;

    // Push each character of 'str' onto the stack
    for (char ch : str) {
        charStack.push(ch);
    }

    // Pop from the stack and append to 'reversedString'
    while (!charStack.empty()) {
        reversedString += charStack.top();  // Get the top character
        charStack.pop();                    // Remove the top character from the stack
    }

    return reversedString;
}
