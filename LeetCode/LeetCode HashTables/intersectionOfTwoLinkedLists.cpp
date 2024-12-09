/*
Time Complexity:
- O(m + n), where m and n are the lengths of the two linked lists.
- Each pointer traverses its own list and switches to the other, ensuring at most m + n steps.

Space Complexity:
- O(1), as no additional data structures are used, only two pointers are maintained.
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If either head is null, no intersection
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse both lists; when one pointer reaches the end,
        // redirect it to the start of the other list
        while (ptrA != ptrB) {
            ptrA = (ptrA != nullptr) ? ptrA->next : headB; 
            ptrB = (ptrB != nullptr) ? ptrB->next : headA;
        }
        
        // Return the intersection node or nullptr if no intersection
        return ptrA;
    }
};
