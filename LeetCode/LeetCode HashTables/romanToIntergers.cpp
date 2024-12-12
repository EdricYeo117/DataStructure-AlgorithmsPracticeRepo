/*
Time Complexity:
- O(n), where n is the length of the input string `s`.
- The algorithm processes each character of the string exactly once.

Space Complexity:
- O(1), as we use a constant-sized unordered map for the Roman numeral mappings.
- No additional data structures are used that grow with the input size.
*/
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        // Initialize the result variable to store the final
        // integer value of the Roman numeral.
        int result = 0;
        int n = s.size();

        // Start a loop that will go through each character
        for (int i = 0; i < n; i++) {
            // If current value is less than the next value, subtract it
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                result += romanMap[s[i]];
            }
        }

        return result;  // Return the final result
    }
};