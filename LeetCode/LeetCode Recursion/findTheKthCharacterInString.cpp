/*
You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet,
 and append it to the original word.
*/

class Solution {
public:
    char kthCharacter(int k) {
        return findKth(k, 1);
    }

private:
    char findKth(int k, int n) {
        // Base case: If n = 1, the string is "a"
        if (n == 1) {
            return 'a';
        }

        // Calculate the length of the string after n operations
        int length = (1 << n) - 1; // 2^n - 1

        // Determine if k is in the first half or second half
        int firstHalfLength = length / 2;

        if (k <= firstHalfLength) {
            // If k is in the first half, recursively find the result
            return findKth(k, n - 1);
        } else {
            // If k is in the second half, map k to the first half
            int mappedK = k - firstHalfLength;
            char result = findKth(mappedK, n - 1);

            // Apply the transformation (shift forward by 1 in the alphabet)
            return (result == 'z') ? 'a' : result + 1;
        }
    }
};