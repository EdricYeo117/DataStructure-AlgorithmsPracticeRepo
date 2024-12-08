/*
Return the head of the linked list after swapping the values of the kth node from the beginning 
and the kth node from the end (the list is 1-indexed).

Time Complexity:
O(N) where N is the number of nodes in the linked list.
Due to traversing the linked list to find the length and the kth node from the beginning and the kth node from the end.

Space Complexity:
O(1) since we are using only a constant amount of space.
*/

#include <iostream>
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
    ListNode* swapNodes(ListNode* head, int k) {
        // Step 1 : Find the length of the linked list
        ListNode* current = head;
        int length = 0;
        // Traverse the linked list to find the length
        while(current != nullptr){
            length++;
            current = current->next;
        }

        // Step 2 : Find the kth node from the beginning
        ListNode* kthNodeFromBeginning = head;
        for(int i = 1; i < k; i++){
            kthNodeFromBeginning = kthNodeFromBeginning->next;
        }

        // Step 3 : Find the kth node from the end
        ListNode* kthNodeFromEnd = head;
        for(int i = 1; i <= length - k; i++){
            kthNodeFromEnd = kthNodeFromEnd->next;
        }

        // Step 4 : Swap the values of the kth node from the beginning and the kth node from the end
        swap(kthNodeFromBeginning->val, kthNodeFromEnd->val);

        // Return the head of the linked list
        return head;
    }
};