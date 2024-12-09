/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> countMap; // To store the frequency of each element
        int n = nums.size();

        // Traverse through the array and populate the frequency map
        for (int num : nums) {
            countMap[num]++;
            
            // Check if the current number is the majority element
            if (countMap[num] > n / 2) {
                return num;
            }
        }

        // This won't be reached because a majority element always exists
        return -1;
    }
};

/*
Time Complexity:
- O(n), where n is the size of the input array.
- We traverse the array once to populate the frequency map, which takes O(n).
- Checking or updating the map also takes O(1) for each element on average.

Space Complexity:
- O(n), where n is the number of unique elements in the input array.
- In the worst case (e.g., when all elements are unique), the unordered map will store n elements.

*/
