/*Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.*/

// Find the Middle of the List: Use the slow and fast pointer technique to locate the middle of the list.
// Reverse the Second Half of the List: Reverse the second half of the linked list.
// Compare the Two Halves: Compare the first half and the reversed second half node by node. If all values match, the list is a palindrome.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            // A single node or an empty list is always a palindrome
            return true;
        }
        
        // Step 1: Find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;            // Moves one step
            fast = fast->next->next;      // Moves two steps
        }
        
        // Step 2: Reverse the second half of the list starting from 'slow'
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;

        // Step 3: Compare the first and second halves
        ListNode* temp = secondHalf; // Used to restore the list later
        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) {
                // Mismatch found, not a palindrome
                reverseList(temp); // Restore the list to its original order
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        
        // Optional Step 4: Restore the list to its original order
        reverseList(temp);

        return true; // All nodes matched, it's a palindrome
    }
    
private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while (current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};
