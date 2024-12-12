/*
All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.

Time Complexity:
- Copying the value of the next node to the current node takes O(1) time.
-  Updating the next pointer of the current node takes O(1) time.
- Deleting the next node takes O(1) time.
- Overall Time Complexity: O(1)

Space Complexity:
- The algorithm uses only one pointer (temp) and no additional data structures.
- Overall Space Complexity: O(1)
*/
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Step 1: Copy the value of the next node to the current node
        node->val = node->next->val;

        // Step 2: Delete the next node
        ListNode* temp = node->next;
        node->next = node->next->next;

        // Step 3: Free the memory of the next node
        delete temp;
    }
};