
/* Given the head of a linked list, return the list after sorting it in ascending order.*/

/*
Time Complexity:
o(nlogn) where n is the number of nodes in the linked list
- Each recusrive call, we split the list into two halves which takes o(n) time
- Merging the two sorted lists takes o(n) time
- The number of recursive calls is o(logn) since we are splitting the list into two halves each time
- Number of recursive levels in merge sort is proportional to height of recusion tree, which is O(logn), at each level, split and merge list

Space Complexity:
o(logn) where n is the number of nodes in the linked list
- The space complexity is o(logn) because the number of recursive calls is o(logn)
*/


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if the list has 0 or 1 node, it's already sorted
        if (!head || !head->next) {
            return head;
        }

        // Step 1: Split the list into two halves
        // Find the middle of the list
        ListNode* middle = findMiddle(head);
        // Split the list into two halves
        ListNode* left = head;
        ListNode* right = middle->next;
        // Break the link between the two halves
        middle->next = nullptr;

        // Step 2: Recursively sort the two halves
        // Sort the left half
        left = sortList(left);
        // Sort the right half
        right = sortList(right);

        // Step 3: Merge the two sorted lists
        return mergeTwoList(left, right);
    }

private:
    // Helper function to find the middle of the list
    ListNode* findMiddle(ListNode* head) {
        // Use the two-pointer technique to find the middle of the list
        // Slow pointer moves one step at a time, fast pointer moves two steps at a time
        ListNode* slow = head;
        ListNode* fast = head->next;
        // While the fast pointer is not null and the next node of the fast pointer is not null
        while (fast && fast->next) {
            // Move the slow pointer one step
            slow = slow->next;
            // Move the fast pointer two steps
            fast = fast->next->next;
        }
        return slow;
    }
    

    // Helper function to merge two sorted lists
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        // Create a dummy node to hold the merged list
        ListNode dummy(0);
        // Create a tail node to keep track of the last node in the merged list
        ListNode* tail = &dummy;

        // Merge the two lists until one of them is empty
        while (list1 && list2) {
            // Compare the values of the two lists and append the smaller one to the merged list
            if (list1-> val < list2->val) {
                // Append list1 to the merged list
                tail->next = list1;
                // Move list1 to the next node
                list1 = list1->next;
            } else {
                // Append list2 to the merged list
                tail->next = list2;
                // Move list2 to the next node
                list2 = list2->next;
            }
            // Move the tail to the last node in the merged list
            tail = tail->next;
        }
        // Append the remaining elements of list1 or list2
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};