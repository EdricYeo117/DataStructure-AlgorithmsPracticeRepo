#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the longest consecutive sequence in a vector 'nums'.
int longestConsecutiveSequence(const vector<int>& nums) {
 
  // Create a set 'numSet' to store unique numbers from 'nums'.
  unordered_set<int> numSet(nums.begin(), nums.end());
 
  // Initialize a variable 'longestStreak' to zero. It will store
  // the length of the longest consecutive sequence found.
  int longestStreak = 0;
 
  // Loop through each number 'num' in the set 'numSet'.
  for (int num : numSet) {
 
    // If 'num - 1' is not in 'numSet', then 'num' can be
    // the starting point of a new consecutive sequence.
    if (numSet.find(num - 1) == numSet.end()) {
 
      // Initialize 'currentNum' to 'num' and 'currentStreak' to 1.
      int currentNum = num;
      int currentStreak = 1;
 
      // While 'currentNum + 1' exists in 'numSet', keep extending
      // the streak by 1 and updating 'currentNum'.
      while (numSet.find(currentNum + 1) != numSet.end()) {
        currentNum++;
        currentStreak++;
      }
 
      // Update 'longestStreak' with the maximum between its current
      // value and 'currentStreak'.
      longestStreak = max(longestStreak, currentStreak);
    }
  }
 
  // Return the longest consecutive sequence length found.
  return longestStreak;
}
