/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Time Complexity:
- O(n), where n is the number of nodes in the linked list.
- Each node is visited exactly once, and the pointer reversal takes constant time.

Space Complexity:
- O(1), as the algorithm uses only a few pointers (`previous`, `current`, and `next`) to reverse the list.
- No additional memory is allocated.
*/

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
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current != nullptr) {
            // Store next node
            next = current->next;

            // Reverse current node pointer
            current->next = previous;

            // Move pointers one position forward
            previous = current;
            current = next;
        }
        return previous;
    }
};