/*
Given a linked list, swap every two adjacent nodes and return its head. 
You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

Time Complexity:
- The while loop traverses the entire linked list once, visiting each node exactly once.
- For a linked list with n nodes, the loop runs approximately n/2 iterations.
- Each iteration involves constant-time operations (pointer adjustments).
- Total time complexity: O(n)

Space Complexity:
- The algorithm uses a few extra pointers (prev, first, second) for tracking nodes.
- There is no recursion or additional data structures used.
- Total space complexity: O(1)

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
    ListNode* swapPairs(ListNode* head) {
        // Base case: if the list has fewer than two nodes
        if (!head || !head->next)
        {
            return head;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;

        // Swap the nodes in pairs
        while (prev->next && prev->next->next)
        {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the next pair
            prev = first;
        }
        return dummy.next;
    }
};