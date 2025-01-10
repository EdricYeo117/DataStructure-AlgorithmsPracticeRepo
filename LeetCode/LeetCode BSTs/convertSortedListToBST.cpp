/*
Given the head of a singly linked list where elements
are sorted in ascending order, convert it to a 
height-balanced binary search tree.

Approach:
1) Base Cases:
    - Linked list is empty, return null
    - Linked list has only one node, return a new node with the value of the head

2) Find the middle of the linked list
    - Use the slow and fast pointers to find the middle
    - Move the slow pointer one step and the fast pointer two steps
    - Use a prev pointer to disconnect the left half from the middle

3) Recursive Construction
    - Create a TreeNode with the value of the middle node
    - Recursively call the function on the left and right halves of the linked list

Time Complexity: O(nlogn) - For each recursive step, we traverse half the list to find the middle O(n)
    recursion depth is log n
Space Complexity: O(logn) - The recursion stack has a depth of log n
*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
private:
    ListNode* findMiddle(ListNode* head) {
        // Use the slow and fast pointers to find the middle 
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr; // To disconnect the left half from the middle 

        // Move the fast pointer twice as fast as the slow pointer
        while (fast != nullptr && fast->next != nullptr) {
            // Move the prev pointer to the slow pointer
            prev = slow;
            // Move the slow pointer one step
            slow = slow->next;
            // Move the fast pointer two steps
            fast = fast->next->next;
        }

        // If the prev pointer is not null, disconnect the left half from the middle
        if (prev != nullptr) {
            prev->next = nullptr;
        }

        // Return the middle node
        return slow; 
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        // Base case - if the head is null, return null
        if (head == nullptr) {
            return nullptr;
        }

        // Base case - if the head is the only node, return a new node with the head's value
        if (head->next == nullptr) {
            return new TreeNode(head->val);
        }

        // Find the middle of the linked list
        ListNode* mid = findMiddle(head);

        // Create a new node with the middle's value
        TreeNode* root = new TreeNode(mid->val);

        // Recursively call the function on the left and right halves of the linked list
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        // Return the root node
        return root;
    }
};