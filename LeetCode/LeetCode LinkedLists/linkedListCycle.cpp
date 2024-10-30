/*Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Initialize two pointers, slow and fast, both starting at the head
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list with two pointers
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow pointer one step forward
            slow = slow->next;
            // Move fast pointer two steps forward
            fast = fast->next->next;
            
            // If slow and fast pointers meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }
        // If the loop ends, there is no cycle in the list
        return false;
    }
};
