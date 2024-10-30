/*Given the head of a linked list and an integer val, 
remove all the nodes of the linked list that has Node.val == val, and return the new head.*/
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    // Default constructor initializes a node with value 0 and next pointer as nullptr
    ListNode() : val(0), next(nullptr) {}

    // Constructor initializes a node with a given value and next pointer as nullptr
    ListNode(int x) : val(x), next(nullptr) {}

    // Constructor initializes a node with a given value and a specified next pointer
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node that points to the head of the list
        // The dummy node helps handle cases where the head itself needs to be removed
        ListNode* dummy = new ListNode(0, head);

        // Start with the dummy node as the current node
        ListNode* current = dummy;

        // Traverse the list until the end is reached
        while (current->next != nullptr) {
            // If the next node's value is the one to remove
            if (current->next->val == val) {
                // Temporarily store the node to be deleted
                ListNode* temp = current->next;
                
                // Bypass the node by pointing current's next to the node after temp
                current->next = current->next->next;
                
                // Delete the temporary node to free memory
                delete temp;
            } else {
                // Move to the next node if no deletion was performed
                current = current->next;
            }
        }

        // Store the new head of the list (next node of dummy)
        ListNode* newHead = dummy->next;

        // Delete the dummy node to free memory
        delete dummy;

        // Return the new head of the modified list
        return newHead;
    }
};
