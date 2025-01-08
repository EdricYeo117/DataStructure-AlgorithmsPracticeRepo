/*
Given two arrays that represent a sequence of keys. 
Imagine we make a Binary Search Tree (BST) from each array. The task is to find whether 
two BSTs will be identical or not without actually constructing the tree.
*/

/*
Follow the steps below to solve the problem:

In both arrays by comparing values within a range defined by min and max constraints.
This starts from the root node.
For both arrays, find the next element that satisfies the current range of values (greater than min and less than max) to identify valid children.
If no valid children are found in both arrays, return true as both subtrees are leaves.
If one array has a valid child and the other does not, or if the children found are not equal, return false.
Move to the next valid child and recursively check both left and right subtrees by updating min and max values based on the current child.
Combine the results of the recursive calls for both left and right subtrees, returning true only if both match at every step.

Time Complexity: O(n^2), each node in one array might compare to all nodes in the other array (worst case)
Space Complexity: O(log N), due to recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if two arrays construct the same BST
// Recursive comparison 
bool isSameBSTUtil(vector<int>& arr1, vector<int>& arr2,  
                 int n, int l, int r, int low, int high) {
    int leftIdx, rightIdx;

    // Search for a valid element in arr1 and arr2
    // that satisfies the constraints `low` and `high`
    for (leftIdx = l; leftIdx < n; leftIdx++) {
        if (arr1[leftIdx] > low && arr1[leftIdx] < high) {
            break;
        }
    }
    for (rightIdx = r; rightIdx < n; rightIdx++) {
        if (arr2[rightIdx] > low && arr2[rightIdx] < high) {
            break;
        }
    }

    // If both arrays have no valid elements, return true
    // Base case, both arrays have no valid elements
    if (leftIdx == n && rightIdx == n) {
        return true;
    }

    // If one array has a valid element but the other doesn't,
    // or if the elements are different, return false
    // Base case: Only one array has valid node/nodes mismatch
    if (((leftIdx == n) ^ (rightIdx == n)) 
                     || arr1[leftIdx] != arr2[rightIdx]) {
      
        return false;
    }

    // Recursively check for the right and left subtrees
    return isSameBSTUtil(arr1, arr2, n, leftIdx + 1, rightIdx + 1, 
                         arr1[leftIdx], high) &&  
           isSameBSTUtil(arr1, arr2, n, leftIdx + 1, rightIdx + 1, 
                         low, arr1[leftIdx]);     
}

// This is a wrapper function
// Passes the arrays, size and intial constraints to the utility function
bool isSameBST(vector<int>& arr1, vector<int>& arr2,
                                               int n) {
    return isSameBSTUtil(arr1, arr2, n, 0, 0, 
                                INT_MIN, INT_MAX);
}

int main() {
  
    // Hardcoded inputs for both the arrays
    vector<int> arr1 = {8, 3, 6, 1, 4, 7, 10, 14, 13};
    vector<int> arr2 = {8, 10, 14, 3, 6, 4, 1, 7, 13};
    int n = arr1.size();

    if (isSameBST(arr1, arr2, n)) {
        cout << "True";
    } 
    else {
        cout << "False";
    }

    return 0;
}