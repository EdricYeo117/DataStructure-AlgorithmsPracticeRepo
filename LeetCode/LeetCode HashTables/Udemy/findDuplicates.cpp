#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findDuplicates(const vector<int>& nums) {
    // Map to store number counts
    unordered_map<int, int> numCounts;
 
    // Iterate through the nums vector and count each number
    for (int num : nums) {
        numCounts[num]++;
    }
 
    // Vector to store the duplicate numbers
    vector<int> duplicates;
 
    // Iterate through the number counts
    for (const auto& entry : numCounts) {
        // Check if the count is greater than 1 (duplicate)
        if (entry.second > 1) {
            // Add the duplicate number to the duplicates vector
            duplicates.push_back(entry.first);
        }
    }
 
    // Return the duplicates vector
    return duplicates;
}