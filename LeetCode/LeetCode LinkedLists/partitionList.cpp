

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
    ListNode *partition(ListNode *head, int x)
    {
        // Create two dummy nodes for less and greater lists
        ListNode lessDummy(0), greaterDummy(0);
        ListNode *less = &lessDummy;
        ListNode *greater = &greaterDummy;

        /* Step 1: Traverse the original list
              and append nodes with lesser value to lesser list
                and nodes with greater value to greater list
        */
        // While loop to traverse the original list
        while (head)
        {
            if (head->val < x)
            {
                less->next = head; // Append to the less list
                less = less->next;
            }
            else
            {
                greater->next = head; // Append to the greater list
                greater = greater->next;
            }
            head = head->next; // Move to the next node
        }

        // Terminate the greater list
        greater->next = nullptr;

        // Step 2: Append the greater list to the end of the less list
        less->next = greaterDummy.next;

        // Return the head of the less list
        return lessDummy.next;
    }
};