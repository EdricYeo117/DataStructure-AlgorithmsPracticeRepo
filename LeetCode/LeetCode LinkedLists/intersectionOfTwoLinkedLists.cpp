/*Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. 
If the two linked lists have no intersection at all, return null.*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // If either list is empty, there can be no intersection
        if (headA == nullptr || headB == nullptr) return nullptr;

        // Initialize two pointers, each starting at the head of one list
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        // Traverse both lists. When either pointer reaches the end of its list, 
        // it switches to the head of the other list. 
        while (ptrA != ptrB) {
            // Move ptrA to the next node, or to headB if it reaches the end of list A
            ptrA = (ptrA != nullptr) ? ptrA->next : headB;
            // Move ptrB to the next node, or to headA if it reaches the end of list B
            ptrB = (ptrB != nullptr) ? ptrB->next : headA;
        }

        // When ptrA and ptrB meet, they are either at the intersection node
        // or both null (indicating no intersection).
        return ptrA;
    }
};
