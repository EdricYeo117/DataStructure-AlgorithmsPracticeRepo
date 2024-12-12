/*
Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.

Time Complexity:
- Each pointer traverses its respective list once and then traverses the other list once.
- In total, each pointer traverses a maximum of (m + n) nodes, where m is the length of list A and n is the length of list B.
- Overall Time Complexity: O(m + n)

Space Complexity:
- The algorithm uses only two pointers (ptrA and ptrB) and no additional data structures.
- Overall Space Complexity: O(1)
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Filter edge cases, where the list is empty or has only one node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Step 1: Create a dummy node to help build the sorted list
        ListNode* dummy = new ListNode(0); 
        ListNode* current = head;

        // Step 2: Process each node in the original list
        while (current != nullptr) {
            // Save the next node to process
            ListNode* nextNode = current->next;

            // Step 3: Find the correct position to insert the current node in the sorted list
            ListNode* prev = dummy;
            while (prev->next != nullptr && prev->next->val < current->val) {
                prev = prev->next;
            }

            // Step 4: Insert the current node into the sorted list
            current->next = prev->next;
            prev->next = current;

            // Move to the next node in the original list
            current = nextNode;
        }

        // Step 5: Return the head of the sorted list
        return dummy->next;
    }
};