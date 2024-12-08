#include <iostream>
#include <vector>
using namespace std;
/*
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.


*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        // Step 1: Reverse the Linked List
        ListNode* reversedHead = reverseList(head);

        // Step 2: Traverse the reversed list and keep only valid nodes
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;
        ListNode* current = reversedHead;
        int maxSoFar = INT_MIN;

        while (current) {
            // If the current node is greater than max so far, update max so far
            if (current->val >= maxSoFar) {
                // Add the current node to the new list
                maxSoFar = current->val;
                // Add node to the new list
                if (!newHead) {
                    newHead = current;
                    tail = current;
                } else {
                    tail->next = current;
                    tail = current;
                }
            }
            // Move to the next node
            current = current->next;
        }
        // Add null to the end of the list
        if (tail) {
            tail->next = nullptr;
        }
        // Step 3: Reverse the new list
        return reverseList(newHead);
    }


private:
    // Helper function to reverse List
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        // Traverse the list
        while (current) {
            //Store the next node
            ListNode* nextNode = current->next;
            // Reverse the current node
            current->next = prev;
            // Move the pointers one position ahead
            prev = current;
            current = nextNode;
        }
        return prev;
    }
};