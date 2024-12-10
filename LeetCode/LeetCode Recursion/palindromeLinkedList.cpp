/*
Given the head of a singly linked list, return true if it is a 
palindrome
 or false otherwise.

Time Complexity:
- O(n), where n is the number of nodes in the linked list.
  - Finding the middle of the list takes O(n/2).
  - Reversing the second half takes O(n/2).
  - Comparing the two halves takes O(n/2).
  - Total: O(n).

Space Complexity:
- O(1), as no extra space is used apart from a few pointers for traversal and list reversal.
  - The list is modified in place and restored to its original state.
*/

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
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
        // If the list is empty or has only one node, it's a palindrome
        if (!head || !head->next) {
            return true;
        }

        // Step 1: Use two pointers (slow and fast) to find the middle of the list
        ListNode* slow = head;
        ListNode* fast = head;

        // Find the middle of the list
        while (fast && fast->next) {
            // Move slow one step and fast two steps
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half of the list
        ListNode* secondHalf = reverseList(slow);
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf; // Store the reversed second half to restore later

        // Step 3: Compare the first half with the reversed second half
        while (secondHalf) {
            // If the values are different, it's not a palindrome
            if (firstHalf->val != secondHalf->val) {
                reverseList(temp); // Restore the original list
                return false;
            }
            // Move to the next nodes
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: Restore the original list before returning
        reverseList(temp);
        return true;
    }

private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        // Initialize three pointers to reverse the list
        ListNode* previous = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        // Reverse the list
        while (current) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }
        return previous;
    }
};