/*Given the head of a singly linked list, reverse the list, and return the reversed list.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Initialize three pointers: previous, current, and next
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        // Traverse the list
        while (current != nullptr) {
            // Store the next node temporarily
            next = current->next;

            // Reverse the current node's pointer
            current->next = previous;

            // Move the pointers one step forward
            previous = current;
            current = next;
        }
        
        // Previous now points to the new head of the reversed list
        return previous;
    }
};
