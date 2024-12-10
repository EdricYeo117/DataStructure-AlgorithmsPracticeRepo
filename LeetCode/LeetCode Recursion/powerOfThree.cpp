/*
Given an integer n, return true if it is a power of three. Otherwise, return false.

An integer n is a power of three, if there exists an integer x such that n == 3x.

Time Complexity:
- O(log₃ n), as the number is divided by 3 in each recursive call.

Space Complexity:
- O(log₃ n), due to the recursive call stack.
*/


class Solution {
public:
    bool isPowerOfThree(int n) {
        // Base case if n is less than or equal to 0
        if (n <= 0) return false;
        // Base case if n is 1
        if (n == 1) return true;
        // Check if n is divisible by 3 and is a power of 3
        return n % 3 == 0 && isPowerOfThree(n / 3);
    }
};


/*
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
};
*/