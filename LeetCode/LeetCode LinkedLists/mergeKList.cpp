/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.*/

/*
Time Complexity:
- Heap Operations:
  Each of the k linked lists has n nodes on average.
  - The priority queue can contain at most k elements at a time.
  - Insertion and extraction from the heap take O(log k).
  - For kn nodes, the total cost of heap operations is:
    O(kn log k).
- Pointer Operations:
  Each node is processed exactly once, so the cost of pointer manipulations is:
    O(kn).
- Overall Time Complexity:
  O(kn log k).

Space Complexity:
- Priority Queue:
  At most k nodes are in the priority queue at any given time, requiring:
    O(k).
- Additional Memory:
  Only a dummy node and a few pointers are used, contributing O(1) additional space.
- Overall Space Complexity:
  O(k).
*/

#include <queue>
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Lambda to compare ListNode pointers for the priority queue
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        
        // Priority queue to keep track of the smallest node among the lists
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        
        // Initialize the priority queue with the head of each non-empty list
        for (auto list : lists) {
            if (list) {
                pq.push(list);
            }
        }
        
        // Dummy head to help build the result list
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        
        // Merge lists
        while (!pq.empty()) {
            // Get the node with the smallest value
            ListNode* smallest = pq.top();
            pq.pop();
            
            // Add it to the merged list
            current->next = smallest;
            current = current->next;
            
            // If there is a next node in the same list, add it to the heap
            if (smallest->next) {
                pq.push(smallest->next);
            }
        }
        
        // Result head is dummy->next
        return dummy->next;
    }
};