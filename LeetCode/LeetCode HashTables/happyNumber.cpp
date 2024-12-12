/*
A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
*/

#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        // Create a set to store the numbers
        unordered_set<int> set;

        // Loop until the number is not 1
        while (n != 1) {
            int current = n;
            int sum = 0;

            // Calculate the sum of the squares of the digits
            while (current > 0) {
               int digit = current % 10;
                sum += digit * digit;
                current /= 10;
            }

            // If the number is already present in the set
            if (set.find(sum) != set.end()) {
                // Return false
                return false;
            }

            // Add the number to the set
            set.insert(sum);
            // Update the number
            n = sum;
        }
        return true;
    }
};

/*
 int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);

        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }
*/