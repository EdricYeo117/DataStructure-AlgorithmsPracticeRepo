/* You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself. */

 struct ListNode {
    int val;
    ListNode *next;
    // Default constructor initializes value to 0 and next pointer to nullptr
    ListNode() : val(0), next(nullptr) {}
    // Constructor initializes node with a specific value and next pointer to nullptr
    ListNode(int x) : val(x), next(nullptr) {}
    // Constructor initializes node with a specific value and a given next node pointer
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy head node to simplify result list construction
        ListNode* dummyHead = new ListNode(0);
        // Tail pointer to track the end of the result list
        ListNode* tail = dummyHead;
        // Variable to store carry-over value for each addition
        int carry = 0;

        // Loop continues while there are nodes in either list or carry is non-zero
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the value of the current node from l1, or 0 if l1 is null
            int digit1 = (l1 != nullptr) ? l1->val : 0;
            // Get the value of the current node from l2, or 0 if l2 is null
            int digit2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum of the two digits and the carry
            int sum = digit1 + digit2 + carry;
            // The new digit is the remainder of sum divided by 10
            int digit = sum % 10;
            // Update carry to be the result of sum divided by 10
            carry = sum / 10;

            // Create a new node for the current digit
            ListNode* newNode = new ListNode(digit);
            // Link the new node to the current tail
            tail->next = newNode;
            // Move the tail pointer to the new node
            tail = tail->next;

            // Move to the next node in l1, if available
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            // Move to the next node in l2, if available
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }

        // The result list starts after the dummy head
        ListNode* result = dummyHead->next;
        // Free the dummy head node to avoid memory leaks
        delete dummyHead;
        return result;
    }
};
