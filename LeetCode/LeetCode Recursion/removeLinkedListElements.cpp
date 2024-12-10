/*
Given the head of a linked list and an integer val,
 remove all the nodes of the linked list that has Node.val == val, and return the new head.

Time Complexity:
- O(n), where n is the number of nodes in the linked list.
- We traverse the entire list once, checking and removing nodes as needed.

Space Complexity:
- O(1), as no additional space is used apart from a few pointers.
- The algorithm modifies the list in place and does not use extra data structures.
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *current = dummy;

        while (current->next != nullptr)
        {
            if (current->next->val == val)
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }
        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};