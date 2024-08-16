#include <vector>
#include <unordered_set>

using namespace std;

// Function named 'findPairs' takes two vectors of integers, 'arr1' and 'arr2',
// and an integer 'target'. The function returns all pairs of integers where one
// integer is from 'arr1' and the other is from 'arr2', and their sum equals 'target'.
vector<vector<int>> findPairs(const vector<int>& arr1, const vector<int>& arr2, int target) {
  
  // Create an empty set named 'mySet' to store unique numbers from 'arr1'.
  unordered_set<int> mySet;
  
  // Create a 2D vector named 'pairs' to store the result pairs.
  vector<vector<int>> pairs;
  
  // Loop through each number 'num' in 'arr1'.
  for (int num : arr1) {
    
    // Add 'num' to 'mySet'.
    mySet.insert(num);
  }
  
  // Loop through each number 'num' in 'arr2'.
  for (int num : arr2) {
    
    // Calculate the 'complement' as 'target - num'.
    int complement = target - num;
    
    // Check if the 'complement' exists in 'mySet'.
    if (mySet.find(complement) != mySet.end()) {
      
      // If it exists, add the pair [complement, num] to 'pairs'.
      pairs.push_back({complement, num});
    }
  }
  
  // Return the 'pairs' vector as the result.
  return pairs;
}

