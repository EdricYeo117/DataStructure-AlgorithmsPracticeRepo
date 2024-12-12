/* Given the head of a linked list, rotate the list to the right by k places.*/

/* 
Time Complexity: O(n)
Traverse the linked list to find the length of the list, then traverse again to find the new head.

Space Complexity: O(1)
Only a constant amount of space is used.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        // Step 1 : Find the length of the linked list
        int length = 1;
        ListNode *current = head;
        while (current->next)
        {
            current = current->next;
            length++;
        }

        // Step 2 : Make it circular linked list
        current->next = head;

        // Step 3 : Find the new head and new tail
        k = k % length;
        int newTailIndex = length - k;
        ListNode *newTail = current; // Start from tail

        while (newTailIndex--)
        {
            newTail = newTail->next;
        }

        // Step 4 : Break the circular linked list
        ListNode *newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};