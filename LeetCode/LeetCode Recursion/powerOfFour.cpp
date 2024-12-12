/*
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.

Time Complexity:
- O(log₃ n), as the number is divided by 4 in each recursive call.

Space Complexity:
- O(log₃ n), due to the recursive call stack.
*/

class Solution {
public:
    bool isPowerOfFour(int n) {
        // Base case if n is less than or equal to 0
        if (n <= 0) return false;
        // Base case if n is equal to 1
        if (n == 1) return true;

        // Return true if n is divisible by 4 and is a power of four
        return n % 4 == 0 && isPowerOfFour(n / 4);
    }
};

/*
class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;

        while (n % 4 == 0) {
            n /= 4;
        }

        return n == 1;
    }
};
*/