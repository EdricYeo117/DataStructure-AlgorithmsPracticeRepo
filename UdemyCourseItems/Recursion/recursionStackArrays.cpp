// Recursive function to reverse a stack
/*
Time complexity: O(n^2)
- Each element is removed and inserted back, requiing O(n) operations per element
Space complexity: O(n)
- N recursive calls
*/
void Stack::reverser() {
    if (isEmpty()) {
        return; // Base case: If the stack is empty, stop recursion
    }

    // Step 1: Remove the top element of the stack
    int topElement = top();
    pop();

    // Step 2: Recursively reverse the rest of the stack
    reverser();

    // Step 3: Insert the removed element at the bottom of the stack
    insertAtBottom(topElement);
}

void Stack::insertAtBottom(int item) {
    if (isEmpty()) {
        // Base case: If the stack is empty, push the item
        push(item);
        return;
    }

    // Step 1: Remove the top element
    int topElement = top();
    pop();

    // Step 2: Recursively insert the item at the bottom
    insertAtBottom(item);

    // Step 3: Push the removed element back on top
    push(topElement);
}

// Recursive function to display a stack
/*
Time complexity: O(n^2)
- Each element is removed and inserted back, requiing O(n) operations per element
Space complexity: O(n)
- N recursive calls
*/
void Stack::PrintStack(Stack s) {
    // Base case: If the stack is empty, stop recursion
    if (s.empty()) {
        return;
    }

    // Step 1: Get the top element of the stack
    int x = s.top();

    // Step 2: Remove the top element from the stack
    s.pop();

    // Step 3: Recursively print the rest of the stack
    PrintStack(s);

    // Step 4: Print the current element
    cout << x << " ";

    // Note: Since `s` is passed by value, this does not modify the original stack
}


// Recursive function to display a stack in revrese order
void Stack::displayInOrderOfInsertionR() {
    // Create a temporary stack to assist in reversing the display
    Stack temp;

    // If the stack is not empty, display its contents in insertion order
    if (!isEmpty()) {
        cout << displayInOrderOfInsertionR2(temp) << endl;

        // Restore the original stack order
        displayInOrderOfInsertionR3(temp);
    }
}

string Stack::displayInOrderOfInsertionR2(Stack &tempStack) {
    // Base case: If the stack is empty, return an empty string
    if (isEmpty()) {
        return "";
    }

    // Recursive step: Pop the top element, save it in the temp stack, and process the rest
    ItemType temp;
    pop(temp);              // Remove the top element from the current stack
    tempStack.push(temp);   // Save it in the temporary stack

    // Recur for the remaining stack and append the current element to the result string
    return displayInOrderOfInsertionR2(tempStack) + " " + to_string(temp);
}

void Stack::displayInOrderOfInsertionR3(Stack &tempStack) {
    // Base case: If the temporary stack is empty, stop recursion
    if (tempStack.isEmpty()) {
        return;
    }

    // Recursive step: Pop from the temporary stack and push it back into the original stack
    ItemType temp;
    tempStack.pop(temp);    // Remove the top element from the temporary stack
    push(temp);             // Restore it to the original stack

    // Recur for the rest of the temporary stack
    displayInOrderOfInsertionR3(tempStack);
}

// Recursive function to sort a stack using recursion
void Stack::sortStack() {
    // Base case: If the stack is empty, return
    if (isEmpty()) {
        return;
    }

    // Step 1: Remove the top element
    int topElement = top();
    pop();

    // Step 2: Recursively sort the remaining stack
    sortStack();

    // Step 3: Insert the removed element back into the sorted stack
    insertSorted(topElement);
}

void Stack::insertSorted(int item) {
    // Base case: If the stack is empty or the item is greater than the top element
    if (isEmpty() || item > top()) {
        push(item);
        return;
    }

    // Step 1: Remove the top element
    int topElement = top();
    pop();

    // Step 2: Recursively insert the item into the sorted stack
    insertSorted(item);

    // Step 3: Push the top element back onto the stack
    push(topElement);
}