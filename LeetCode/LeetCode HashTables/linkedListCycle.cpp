/*
Time Complexity:
- O(n), where n is the number of nodes in the linked list.
- Each pointer travels at most n steps, as the fast pointer moves twice as fast as the slow pointer.

Space Complexity:
- O(1), as no additional data structures are used. Only two pointers, slow and fast, are maintained.
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
    bool hasCycle(ListNode *head) {
        // Initialize two pointers, slow and fast
        ListNode* slow = head;
        ListNode* fast = head;

        // Traverse the list with two pointers
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // Slow pointer moves one step
            fast = fast->next->next;  // Fast pointer moves two steps
            
            // If slow and fast meet, a cycle exists
            if (slow == fast) {
                return true;
            }
        }
        
        // If fast reaches the end, no cycle exists
        return false;
    }
};