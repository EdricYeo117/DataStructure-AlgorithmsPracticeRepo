#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
For each node in the list, find the value of the next greater node. 
That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Time Complexity:
- Converting the linked list to a vector of values takes O(n), where n is the number of nodes in the list.
- The traversal of the vector in reverse to find the next greater element takes O(n).
- Each element is pushed and popped from the stack at most once, so the stack operations also take O(n).
- Overall Time Complexity: O(n)

Space Complexity:
- The `values` vector requires O(n) space to store the values of the linked list.
- The `result` vector requires O(n) space to store the final answer.
- The stack requires O(n) space in the worst case (if all elements are stored in the stack).
- Overall Space Complexity: O(n)
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solutions
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        // Step 1 : Traverse the list and store the values in a vector
        vector<int> values;
        // Head is the current node
        ListNode* current = head;
        // Traverse the list
        while (current != nullptr)
        {
            values.push_back(current->val);
            current = current->next;
        }

        // Step 2: Uses stack to find the next greater element
        vector<int> result(values.size(), 0);
        // Stack to store the indices of the elements
        stack<int> stack;

        // Traverse the list
        for (int i = values.size() -1; i >= 0; i--)
        {
            // Pop smaller elemnents from the stack
            while (!stack.empty() && values[i] >= values[stack.top()])
            {
                stack.pop();
            }

            // If the stack is not empty, the next greater element is the top of the stack
            if (!stack.empty())
            {
                result[i] = values[stack.top()];
            }

            // Push the current element to the stack
            stack.push(i);
        }
        return result;
    }
};