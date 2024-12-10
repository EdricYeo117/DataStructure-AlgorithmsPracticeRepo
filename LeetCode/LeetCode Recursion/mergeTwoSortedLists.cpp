/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Time Complexity:
- O(m + n), where m and n are the lengths of the two linked lists.
- We traverse each list exactly once to merge the nodes.

Space Complexity:
- O(1), as we do not use any extra space for data structures.
- The merged list is created by reusing the existing nodes of the input lists, so no additional space is allocated for new nodes.
*/

#include <iostream>
#include <vector>

using namespace std;
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
        // Create a dummy nose
        ListNode dummy;
        ListNode* current = &dummy;

        // While both list are not empty, compare current nodes of each list 
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }
            current = current->next;
        }

        if (list1 != nullptr) {
            current->next = list1;
        } else if (list2 != nullptr) {
            current->next = list2;
        }
        return dummy.next;
    }
};