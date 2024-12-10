/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
*/

class Solution {
public:
    double myPow(double x, int n) {
        // Convert n to long long to handle INT_MIN safely
        long long exp = n;

        // Handle negative exponent
        if (exp < 0) {
            x = 1 / x;
            exp = -exp; // Safely negate using long long
        }

        return power(x, exp);
    }

private:
    double power(double x, long long n) {
        // Base case : x^0 = 1
        if (n == 0) {
            return 1.0;
        }

        // Recursive case
        double half = power(x, n / 2);

        // If n is even
        if (n % 2 == 0) {
            return half * half;
        } else {
            // If n is odd
            return half * half * x;
        }
    }
};