/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

Time Complexity:
- Each node in both linked lists is processed exactly once.
- Let `m` be the number of nodes in l1 and `n` be the number of nodes in l2.
- The recursion will run for max(m, n) steps (including the carry node if necessary).
- Thus, the time complexity is:
  O(max(m, n))

Space Complexity:
- The recursion stack will have depth proportional to the number of nodes in the longer list.
- Additionally, each recursive call creates a new node for the resulting linked list.
- Thus, the space complexity is:
  O(max(m, n)) (due to recursion stack and the output list).
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return add(l1, l2, 0);
    }

private:
    ListNode *add(ListNode *l1, ListNode *l2, int carry)
    {
        // Base Case: If both lists are empty and there is no carry, return nullptr
        if (!l1 && !l2 && carry == 0)
        {
            return nullptr;
        }

        // Calculate the sum of the current digits
        int sum = carry;
        // If l1 is not empty, add the value of l1 to sum
        if (l1)
        {
            sum += l1->val;
        }
        // If l2 is not empty, add the value of l2 to sum
        if (l2)
        {
            sum += l2->val;
        }

        // Determine the current digit and the new carry
        int currentDigit = sum % 10;
        int newCarry = sum / 10;

        // Create the new node for the current digit
        ListNode *newNode = new ListNode(currentDigit);

        // Recursively process the next nodes
        // If l1 is not empty, move to the next node in l1
        newNode->next = add(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr, newCarry);
        return newNode;
    }
};