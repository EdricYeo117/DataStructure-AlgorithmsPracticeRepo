
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Initialize two pointers, slow and fast, both starting at the head of the list
        ListNode* slow = head;
        ListNode* fast = head;
        // Traverse the list with the fast pointer moving two steps at a time
        // and the slow pointer moving one step at a time
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // When the fast pointer reaches the end of the list, the slow pointer
        // will be at the middle node
        return slow;
    }
};