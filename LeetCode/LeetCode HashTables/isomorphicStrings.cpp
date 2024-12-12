/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.
*/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // If the length of the strings are not equal, then they can't be isomorphic
        if(s.length() != t.length()) return false;

        // Create a map to store the mapping of characters from s to t
        unordered_map<char, char> sToT;
        // Create a map to store the mapping of characters from t to s
        unordered_map<char, char> tToS;
        
        // Iterate through the strings
        for (int i = 0; i < s.length(); i++) {
            // Get the characters at the current index
            char sChar = s[i];
            char tChar = t[i];

            // Check if there is conflicting mapping from s and t
            if (sToT.count(sChar) && sToT[sChar] != tChar) {
                return false;
            }

            // Check if there is conflicting mapping from t and s
            if (tToS.count(tChar) && tToS[tChar] != sChar) {
                return false;
            }

            // Create the mapping
            sToT[sChar] = tChar;
            tToS[tChar] = sChar;
        }
        return true;
    }
};

/*
Time Complexity:
- O(n), where n is the length of the input strings `s` and `t`.
- We iterate over the strings once, and all map operations (insertions and lookups) are O(1) on average.

Space Complexity:
- O(1) in the sense that the map only stores mappings for the 256 possible ASCII characters, which is constant space.

Example Usage:
int main() {
    Solution solution;
    string s = "egg", t = "add";
    cout << (solution.isIsomorphic(s, t) ? "True" : "False") << endl;

    string s2 = "foo", t2 = "bar";
    cout << (solution.isIsomorphic(s2, t2) ? "True" : "False") << endl;

    return 0;
}

Expected Output:
True
False
*/