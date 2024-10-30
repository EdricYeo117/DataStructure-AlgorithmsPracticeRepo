#include <vector>
#include <unordered_map>

using namespace std;

// Function to find a continuous subarray which adds up to target
vector<int> subarraySum(const vector<int>& nums, int target) {
    // Initialize an unordered map to store sum of elements up to an index
    unordered_map<int, int> sumIndex;
 
    // Initialize 0 sum at index -1
    sumIndex[0] = -1;
 
    // Initialize currentSum to 0
    int currentSum = 0;
 
    // Iterate through nums array
    for (int i = 0; i < nums.size(); i++) {
        // Accumulate sum
        currentSum += nums[i];
 
        // 'find' function is used to search 'currentSum - target' in the map
        // 'end' function gives an iterator pointing to past-the-end element
        // If 'currentSum - target' is not found in map, 'find' returns 'end'
        // So, if 'find' does not return 'end', it means 'currentSum - target'
        // exists in the map, which implies a subarray with sum equals to
        // 'target' has been found
        if (sumIndex.find(currentSum - target) != sumIndex.end()) {
            // Return the indices of subarray which adds up to target
            return {sumIndex[currentSum - target] + 1, i};
        }
 
        // Record the current sum and its index in the map
        sumIndex[currentSum] = i;
    }
 
    // If no such subarray is found, return an empty vector
    return {};
}
