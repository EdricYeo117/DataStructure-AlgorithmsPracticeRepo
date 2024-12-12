/*
The Fibonacci numbers, commonly denoted F(n) form a sequence,
 called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

Time Complexity:
- O(2^n), due to the overlapping subproblems in the recursive calls.

Space Complexity:
- O(n), due to the recursion stack for \(n\) calls.
*/

class Solution {
public:
    int fib(int n) {
        // Base case if n is 0 or 1
        if (n <= 1) return n;
        // Recursive case
        return fib(n - 1) + fib(n - 2);
    }
};