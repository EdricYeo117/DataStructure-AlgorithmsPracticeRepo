/*Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // If the list is empty or has only one node, there are no duplicates to remove
        if (!head || !head->next) {
            return head;
        } 
        
        // Start with the head node
        ListNode* current = head;

        // Traverse the list
        while (current && current->next) {
            // Check if the current node and the next node have the same value
            if (current->val == current->next->val) {
                // Duplicate found, so skip the next node
                ListNode* temp = current->next;     // Temporary pointer to the duplicate node
                current->next = current->next->next; // Bypass the duplicate node
                delete temp;                         // Free memory of the duplicate node
            } else {
                // No duplicate, move to the next node
                current = current->next;
            }
        }
        
        // Return the head of the modified list
        return head;
    }
};
