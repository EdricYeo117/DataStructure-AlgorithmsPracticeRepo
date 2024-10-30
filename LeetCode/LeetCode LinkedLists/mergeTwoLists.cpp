/*You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.*/

struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the starting point of the merged list
        // This helps avoid edge cases with empty lists and simplifies the code
        ListNode dummy;
        ListNode* current = &dummy; // Pointer to build the new list starting at dummy

        // Traverse both lists until one of them becomes empty
        while (list1 != nullptr && list2 != nullptr) {
            // Compare the values of the current nodes of each list
            if (list1->val < list2->val) {
                // If list1's node is smaller, link it to the merged list
                current->next = list1;
                list1 = list1->next; // Move to the next node in list1
            } else {
                // If list2's node is smaller or equal, link it to the merged list
                current->next = list2;
                list2 = list2->next; // Move to the next node in list2
            }
            // Move the current pointer to the last node in the merged list
            current = current->next;
        }

        // At this point, at least one of the lists is empty
        // Attach the remaining non-empty list (if any) to the merged list
        current->next = (list1 != nullptr) ? list1 : list2;

        // The merged list starts at dummy.next (skipping the initial dummy node)
        return dummy.next;
    }
};
