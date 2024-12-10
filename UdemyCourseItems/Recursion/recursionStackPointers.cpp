// Recursive function to count the number of elements in a stack
int Stack::count() {
    Node* tmp = topNode;
    return count2(0, tmp);
}

int Stack::count2(int index, Node* tmp) {
    // Base case: If the current node is NULL, return the index
    if (tmp == nullptr) {
        return index;
    }

    // Recursive case: Increment the index and move to the next node
    return count2(index + 1, tmp->next);
}
