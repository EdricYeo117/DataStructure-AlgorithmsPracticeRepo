/*
Use a queue to store the characters along with their indices as they appear in the string.

Use a frequency array to keep track of the frequency of each character.

Iterate through the string and:
    Add the character to the queue if it's the first time it is encountered.
    Update the frequency of the character.
    Remove characters from the front of the queue if their frequency is greater than 1.

After processing the string, the character at the front of the queue is the first unique character. If the queue is empty, return -1.
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        // Create a queue to store the characters along with their indices
        vector<int> freq(26, 0);
        // Queue to store character and its index
        queue<pair<char, int>> queue; 

        // Step 1 : Process string 
        for (int i = 0; i < s.size(); i++) {
            // Add the character to the queue if it's the first time it is encountered
            char c = s[i];
            // Update the frequency of the character
            freq[c - 'a']++;
            // Add characters and index to the queue
            queue.push({c, i});
        }

        // Step 2 : Find the first unique character
        // While loop to remove characters from the front of the queue if their frequency is greater than 1
        while (!queue.empty()) {
            // Remove characters from the front of the queue
            char c = queue.front().first;
            // Get the index of the character
            int index = queue.front().second;
            // If statement to check if the frequency of the character is 1
            if (freq[c - 'a'] == 1) {
                // Return the index of the first unique character
                return index; 
            }
            // Pop the front element from the queue
            queue.pop();
        }
        return -1;
    }
};