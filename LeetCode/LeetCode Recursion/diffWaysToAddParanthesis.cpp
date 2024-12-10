/*
Given a string expression of numbers and operators, 
return all possible results from computing all the different possible ways to group numbers and operators. 
You may return the answer in any order.

Time Complexity:
- At each operator, the expression is split into left and right subparts, resulting in two recursive calls.
- For an expression with `n` characters (including operators and numbers), the number of splits grows exponentially.
- The total number of recursive calls is approximately O(2^n), where `n` is the number of operators.
- Additionally, combining results at each level can take O(2^n) time due to all combinations being computed.
- Total time complexity: O(4^n)

Space Complexity:
- The recursion stack depth is proportional to the number of operators, which is O(n).
- At each recursive level, intermediate results from left and right subproblems are stored, which can grow to O(2^n).
- Total space complexity: O(2^n)

*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // Base case: If the expression is a single number, return it as the only result
        if (isNumber(expression)) {
            // Convert string to integer
            return {stoi(expression)};
        }

        // Vector to store the result
        vector<int> result;

        // Iterate through the expression
        for (int i = 0; i < expression.size(); i++) {
            char c = expression [i];

            // If the character is an operator, split the expression into two parts
            if (c == '+' || c == '-' || c == '*') {
                // Split the expression into two parts
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results of the two parts
                for (int a : left) {
                    for (int b : right) {
                        result.push_back(calculate(a, b, c));
                    }
                }
            }
        }
        return result;
    }

private:
    // Helper function to check if string is number
    bool isNumber(const string& s) {
        return s.find_first_not_of("0123456789") == string::npos;
    }

    // Helper function to compute the result of a single operation
    int calculate(int a, int b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            default:
                return 0;
        }
    }
};