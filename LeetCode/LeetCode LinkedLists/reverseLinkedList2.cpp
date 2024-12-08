

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // Step 1 : Set up the dummy node
        ListNode dummy(0);
        // Set the next of the dummy node to the head
        dummy.next = head;
        // Set the prev node to the dummy node
        ListNode *prev = &dummy;

        // Step 2 : Traverse to the node right before 'left' position
        for (int i = 0; i < left - 1; i++)
        {
            prev = prev->next;
        }

        // Step 3 : Reverse the nodes from left to right
        ListNode *current = prev->next;
        ListNode *next = nullptr;
        ListNode *tail = current; // Tail of the reversed list

        // Reverse the nodes from left to right
        for (int i = 0; i < right - left + 1; i++)
        {
            // Set the next node
            next = current->next;
            // Set the next of the current node to the next of the prev node
            current->next = prev->next;
            // Set the next of the prev node to the current node
            prev->next = current;
            // Set the current node to the next node
            current = next;
        }

        // Step 4 : Connect the tail node to the next node
        tail->next = current;

        // Step 5 : Return the head node
        return dummy.next;
    }
};