/*
Given an integer n, 
return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        // Create vector to store number of unique BSTs with i nodes
        vector<int> dp(n + 1, 0);
        // Base case - 0 nodes
        dp[0] = 1;
        // Base case - 1 node
        dp[1] = 1;

        // Nested for loop to iterate through all the nodes
        for (int i = 2; i<= n; ++i) {
            /// Nested for loop to iterate through all the nodes
            for (int j = 1; j<=i; ++j) {
                // Number of unique BSTs with i nodes = 
                // Number of unique BSTs with j-1 nodes * Number of unique BSTs with i-j nodes
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};