#include <iostream>
#include <vector>
static int counter = 0;

//Dynamic programming implementation------------------------------------------
std::vector<int> memo(100, -1); // Initialize memoization table with -1

int fibonacci(int n) {
    counter++;
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 1) {
        return n;
    } 
    memo[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return memo[n];
}

int main() {
    int n = 10;
    std::cout << "Fibonacci number at position " << n << ": " << fibonacci(n) << std::endl;
    std::cout << "Number of function calls: " << counter << std::endl;
    return 0;
}