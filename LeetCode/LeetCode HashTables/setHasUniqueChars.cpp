#include <string>
#include <unordered_set>

using namespace std;

// Function called 'hasUniqueChars' that takes in a string 'str'
// and returns true if all characters in the string are unique,
// otherwise returns false.
bool hasUniqueChars(const string& str) {
  
  // Create an empty set called 'charSet' to hold characters.
  // Sets only store unique items.
  unordered_set<char> charSet;
  
  // Loop through each character 'ch' in the string 'str'.
  for (char ch : str) {
    
    // Check if 'ch' is already in 'charSet'.
    if (charSet.find(ch) != charSet.end()) {
      
      // If 'ch' is found, it's a duplicate. Return false.
      return false;
    }
    
    // If 'ch' not found, add it to 'charSet'.
    charSet.insert(ch);
  }
  
  // If we make it through the loop without returning false,
  // that means all characters are unique. Return true.
  return true;
}

