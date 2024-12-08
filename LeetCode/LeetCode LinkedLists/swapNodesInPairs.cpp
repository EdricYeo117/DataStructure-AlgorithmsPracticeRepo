/* Given a linked list, swap every two adjacent nodes and return its head.*/

/*
Iterative Approach
Use a dummy node to simplify edge cases (e.g., when the list has fewer than two nodes).
Use a pointer prev that always points to the node before the current pair.
Swap the nodes in pairs while updating pointers appropriately.
Continue until all pairs are swapped.*/

/*
Recursive Approach
If the list has fewer than two nodes, return the head as is.
Swap the first two nodes, and recursively call the function on the rest of the list.
Connect the swapped pair with the result of the recursive call.*/


/*

Time Complexity: O(n)
For a list with n nodes, loop runs approximately n/2 times
Number of iterations proportional to number of n nodes, each iteration is O(1), so total time complexity is O(n)

Space Complexity: O(1)
Only a constant amount of extra space is used, so space complexity is O(1)

However in the recursive approach, the space complexity is O(n) due to the recursive calls.

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
    ListNode *swapPairs(ListNode *head)
    {
        // Base case: if the list has fewer than two nodes
        if (!head || !head->next)
        {
            return head;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *prev = &dummy;

        // Swap the nodes in pairs
        while (prev->next && prev->next->next)
        {
            ListNode *first = prev->next;
            ListNode *second = prev->next->next;

            // Swapping
            prev->next = second;
            first->next = second->next;
            second->next = first;

            // Move to the next pair
            prev = first;
        }
        return dummy.next;
    }

    ListNode *swapPairsRecursive(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *first = head;
        ListNode *second = head->next;

        // Swap recursively
        first->next = swapPairsRecursive(second->next);
        second->next = first;

        return second;
    }
};