#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(const vector<string>& strings) {
    // Map to store anagram groups with canonical forms as keys
    unordered_map<string, vector<string>> anagramGroups;
 
    for (const string& str : strings) {
        // Create the canonical form by sorting the string
        string canonical = str;
        sort(canonical.begin(), canonical.end());
 
        // Add the string to its anagram group
        anagramGroups[canonical].push_back(str);
    }
 
    // Vector to store the final result
    vector<vector<string>> result;
 
    // Iterate through anagram groups
    for (const auto& group : anagramGroups) {
        // Add the anagram group to the result
        result.push_back(group.second);
    }
 
    // Return the grouped anagrams
    return result;
}
