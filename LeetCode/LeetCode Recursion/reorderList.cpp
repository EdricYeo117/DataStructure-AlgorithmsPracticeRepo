/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
*/
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void reorderList(ListNode* head) {
        // Set left to head and call recursive helper
        ListNode* left = head;
        reorder(head, left);
    }

private:
    bool reorder(ListNode* right, ListNode*& left) {
        // Base case: If we reach the end of the list, stop recursion
        if (!right) return false;

        // Recursive call to traverse to the end
        if (reorder(right->next, left)) return true;

        // Stop when left crosses or meets right
        if (left == right || left->next == right) {
            right->next = nullptr; // Mark the end of the list
            return true;
        }

        // Reorder: Connect left to right and move left forward
        ListNode* nextLeft = left->next;
        // Connect left to right
        left->next = right;
        // Connect right to next left
        right->next = nextLeft;
        // Move left forward
        left = nextLeft;

        return false;
    }
};