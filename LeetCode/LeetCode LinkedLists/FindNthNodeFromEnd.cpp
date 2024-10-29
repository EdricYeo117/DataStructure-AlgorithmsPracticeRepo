
 struct ListNode {
      int val;
   ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Initialize slow and fast pointers to head
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Move the fast pointer k steps ahead
    for (int i = 0; i < n; ++i)
    {
        // If fast reaches the end, k is too large
        if (fast->next == nullptr)
        {
            return head;
        }
        // Move fast to the next node
        fast = fast->next;
    }

    // Traverse the list until fast reaches the end
    while (fast->next != nullptr)
    {
        // Move slow and fast pointers to the next nodes
        slow = slow->next;
        fast = fast->next;
    }

        // Slow is now before the node to remove, skip it
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // Free the memory of the removed node

        // Return the head of the modified list
        ListNode* result = dummy->next;
        delete dummy; // Free the dummy node
        return result;
    }
};