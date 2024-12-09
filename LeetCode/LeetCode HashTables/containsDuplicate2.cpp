/*
Given an integer array nums and an integer k, 
return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 Time Complexity:
- O(n), where n is the size of the array.
- Each element is processed once, and map operations (insert/find) are O(1) on average.

Space Complexity:
- O(n), where n is the number of unique elements in the array.
- In the worst case, all elements are unique, so the map stores all of them.
*/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Map to store the element and its index
        unordered_map <int, int> numMap;

        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Check if the elements exists in the map
            if (numMap.find(nums[i]) != numMap.end()) {
                // If the difference between the indices is less than or equal to k, return true
                if (i - numMap[nums[i]] <= k) {
                    return true;
                }
            }
            // Update the index of the element
            numMap[nums[i]] = i;
        }
        return false;
    }
};