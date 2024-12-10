/*
Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

Time Complexity:
- O(log n), where n is the input number.
- Each recursive call divides `n` by 2, leading to a logarithmic number of calls.

Space Complexity:
- O(log n), due to the recursive call stack.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;

        return n % 2 == 0 && isPowerOfTwo(n / 2);
    }
};


/*
Iterative Solution:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;

        while (n % 2 == 0) {
            n /= 2;
        }

        return n == 1;
    }
};
*/