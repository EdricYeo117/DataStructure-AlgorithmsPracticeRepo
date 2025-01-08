#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap
    int k; // Store k

public:
    // Constructor to initialize k and the initial set of scores
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop(); // Remove the smallest element if heap exceeds k
            }
        }
    }

    // Add a new score and return the k-th largest score
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > k) {
            minHeap.pop(); // Ensure heap size remains k
        }
        return minHeap.top(); // Return the k-th largest element (top of Min-Heap)
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Using BST
/*
class KthLargest {
private:
    TreeNode* root;
    int k;

    // Insert a value into the BST and update node counts
    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);

        node->count++; // Increment count of current node

        if (val <= node->val) {
            node->left = insert(node->left, val); // Go left if smaller
        } else {
            node->right = insert(node->right, val); // Go right if larger
        }

        return node;
    }

    // Find the k-th largest element
    int findKthLargest(TreeNode* node, int k) {
        int rightCount = (node->right) ? node->right->count : 0;

        if (rightCount + 1 == k) {
            return node->val; // Current node is the k-th largest
        } else if (rightCount >= k) {
            return findKthLargest(node->right, k); // Search right subtree
        } else {
            return findKthLargest(node->left, k - rightCount - 1); // Adjust k and search left
        }
    }

public:
    KthLargest(int k, vector<int>& nums) : root(nullptr), k(k) {
        for (int num : nums) {
            root = insert(root, num);
        }
    }

    int add(int val) {
        root = insert(root, val); // Add the new value to BST
        return findKthLargest(root, k); // Return k-th largest
    }
};

*/