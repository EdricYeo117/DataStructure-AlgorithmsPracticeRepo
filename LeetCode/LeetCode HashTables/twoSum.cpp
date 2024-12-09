/*
Time Complexity:
- O(n), where n is the size of the input array 'nums'.
- Each element is processed exactly once in the loop, and lookup/insert operations in the unordered_map take O(1) on average.

Space Complexity:
- O(n), where n is the size of the input array 'nums'.
- In the worst case, the unordered_map will store all the elements in 'nums'.

*/
#include <vector>
#include <unordered_map>

using namespace std;

// Define a function to find two numbers in 'nums' that add up to 'target'
vector<int> twoSum(const vector<int>& nums, int target) {
    // Create an unordered map to store numbers and their indices
    unordered_map<int, int> numMap;
 
    // Iterate through the 'nums' array
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];  // Current number
        int complement = target - num;  // Number needed to make 'target'

        // Check if the complement exists in the map
        if (numMap.find(complement) != numMap.end()) {
            // Return indices of the two numbers
            return {numMap[complement], i};
        }
        
        // Store the current number and its index in the map
        numMap[num] = i;
    }
 
    // If no solution is found, return an empty vector
    return {};
}