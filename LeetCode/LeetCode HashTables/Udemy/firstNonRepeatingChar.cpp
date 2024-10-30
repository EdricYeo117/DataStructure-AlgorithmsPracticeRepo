
#include <string>
#include <unordered_map>

using namespace std;

char firstNonRepeatingChar(const string& input_string) {
    // Create an unordered_map to store the count of each character
    unordered_map<char, int> charCounts;
    
    // Count occurrences of each character in the input string
    for (char ch : input_string) {
        charCounts[ch]++;
    }
    
    // Find the first character with a count of 1
    for (char ch : input_string) {
        if (charCounts[ch] == 1) {
            return ch;
        }
    }
    
    // Return '\0' if no non-repeating character is found
    return '\0';
}