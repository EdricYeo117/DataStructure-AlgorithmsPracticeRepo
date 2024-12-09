/*
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Time Complexity:
- O(n), where n is the number of elements in the array `nums`.
- Each element is added to the hash set once, and set operations (insert/find) are O(1) on average.

Space Complexity:
- O(n), where n is the number of unique elements in the array.
- In the worst case, all elements in `nums` are distinct, so the set will store all of them.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Create a set to store the unique elements in the array
        unordered_set <int> seen;

        // Iterate through the array
        for (int num : nums) {
            // If the element is already in the set, return true
            if (seen.find(num) != seen.end()) {
                return true;
            }
            // Otherwise, add the element to the set
            seen.insert(num);
        }
        return false;
    }
};