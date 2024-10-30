#include <vector>
#include <unordered_map>

using namespace std;

// Define a function named "twoSum" that aims to find two 
// numbers in the 'nums' list which, when added together, 
// will equal the 'target' value.
vector<int> twoSum(const vector<int>& nums, int target) {
    
    // Create an "unordered_map" named "numMap". This will 
    // help us remember which numbers we've seen and their 
    // positions in the 'nums'.
    unordered_map<int, int> numMap;
 
    // Start a loop that will go through each number in the 
    // 'nums' list from the beginning to the end.
    for (int i = 0; i < nums.size(); i++) {
        
        // Store the current number from the list in the 
        // variable named 'num'.
        int num = nums[i];
        
        // Calculate what other number (named 'complement') 
        // we'd need to find in our list to pair with 'num' 
        // to reach our 'target'.
        int complement = target - num;
 
        // Now, we check if this 'complement' number has been 
        // seen before in our loop. If it's in 'numMap', 
        // then we've seen it!
        if (numMap.find(complement) != numMap.end()) {
            
            // If we found the complement, this means 'num' 
            // and 'complement' are the pair of numbers we 
            // are looking for. So, we'll return their 
            // positions from the list as our answer.
            return {numMap[complement], i};
        }
        
        // If we haven't found the pair, we save the current 
        // number 'num' and its position 'i' into 'numMap' 
        // for future checks. This means, "Hey map, remember 
        // that I've seen this number at this position!"
        numMap[num] = i;
    }
 
    // If we've gone through the entire list and didn't find 
    // any pair that adds up to the target, we return an empty 
    // list to signify "no solution was found".
    return {};
}
