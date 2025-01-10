/*
Given an array nums that represents a permutation of integers from 1 to n. 
We are going to construct a binary search tree (BST) 
by inserting the elements of nums in order into an initially empty BST.
 Find the number of different ways to reorder nums so that the constructed BST is 
 identical to that formed from the original array nums.

 Approach:
1) BST structure: 
- Defined by order of elements inserted. 
Left subtree contains elements smaller than the root, 
right subtree contains elements larger than the root

2) Divide and Conquer:
- Root of the BST, divide the remaining elements into the left and right subtrees
- Based on whether the element is smaller or larger than the root

3) Combinatorics:
- Number of ways to rearrange the elements of the left and right subtree in the same relative order
ways=    (  n - 1  ) 
         (left_size)

- n-1 is the total number of elements excluding the root, left_size is the number of elements in left subtree

4) Recursion:
- For each subtree, recursively calculate the number of ways to reorder its elements

5) Modulo:
- Return the number of ways modulo 10^9 + 7
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
/*
Given an array nums that represents a permutation of integers from 1 to n. 
We are going to construct a binary search tree (BST) 
by inserting the elements of nums in order into an initially empty BST.
 Find the number of different ways to reorder nums so that the constructed BST is 
 identical to that formed from the original array nums.

 Approach:
1) BST structure: 
- Defined by order of elements inserted. 
Left subtree contains elements smaller than the root, 
right subtree contains elements larger than the root

2) Divide and Conquer:
- Root of the BST, divide the remaining elements into the left and right subtrees
- Based on whether the element is smaller or larger than the root

3) Combinatorics:
- Number of ways to rearrange the elements of the left and right subtree in the same relative order
ways=    (  n - 1  ) 
         (left_size)

- n-1 is the total number of elements excluding the root, left_size is the number of elements in left subtree

4) Recursion:
- For each subtree, recursively calculate the number of ways to reorder its elements

5) Modulo:
- Return the number of ways modulo 10^9 + 7

Time Complexity : O(n^2)
Space Complexity : O(n^2)
*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    // Define the modulo value
    const int MOD = 1e9 + 7;
    // Calculate the number of ways to reorder the elements of the array
    vector<vector<long long>> comb;

    // Function to calculate binomial coefficients
    void calculateCombination(int n) {
        comb = vector<vector<long long>>(n, vector<long long>(n, 0));
        // For Loop 
        for (int i = 0; i < n; i++) {
            // Base Cases 
            comb[i][0] = comb[i][i] = 1;
            // For Loop
            for (int j = 1; j < i; j++) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }
    }

    // Recursive function to calculate the number of ways
    long long countWays(vector<int>& nums) {
        // Base case - Only one way for 0, 1, or 2 elements
        if (nums.size() <= 2) {
            return 1;
        }

        int root = nums[0];
        vector<int> left, right;

        // Divide elements into left and right subtrees
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root) {
                left.push_back(nums[i]);
            } else {
                right.push_back(nums[i]);
            }
        }

        // Calculate the number of ways for left and right subtrees
        long long leftWays = countWays(left);
        long long rightWays = countWays(right);

        // Combine the results using binomial coefficients
        int leftSize = left.size();
        int rightSize = right.size();

        return (comb[leftSize + rightSize][leftSize] * leftWays % MOD * rightWays % MOD) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        // Calculate binomial coefficients
        calculateCombination(n + 1);
        return (countWays(nums) - 1 + MOD) % MOD;
    }
};

/*
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        long long mod = 1e9 + 7;
		int n = nums.size();
        
		// Pascal triangle
        table.resize(n + 1);
        for(int i = 0; i < n + 1; ++i){
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % mod;
            }
        }
        
        long long ans = dfs(nums, mod);
        return ans % mod - 1;
    }
    
private:
    vector<vector<long long>> table;
    long long dfs(vector<int> &nums, long long mod){
        int n = nums.size();
        if(n <= 2) return 1;
        
		// find left sub-sequence elements and right sub-sequence elements
        vector<int> left, right;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
		
		// recursion with left subtree and right subtree
        long long left_res = dfs(left, mod) % mod;
        long long right_res = dfs(right, mod) % mod;
		
		// look up table and multiple them together
		int left_len = left.size(), right_len = right.size();
        return (((table[n - 1][left_len] * left_res) % mod) * right_res) % mod;
    }
};
*/