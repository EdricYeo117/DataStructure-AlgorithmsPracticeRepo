#include <iostream>
#include <vector>

static int counter = 0;

// Bottom-up approach
int fibonacci(int n) {
    std::vector<int> fibList(n + 1);
    fibList[0] = 0;
    fibList[1] = 1;
    for (int index = 2; index <= n; index++) {
        fibList[index] = (fibList[index - 1] + fibList[index - 2]);
        counter++; // Increment counter each time a Fibonacci number is computed
    }
    return fibList[n];
}

int main() {
    int n = 41;
    std::cout << "Fibonacci number at position " << n << ": " << fibonacci(n) << std::endl;
    std::cout << "\nCounter: " << counter << std::endl;
}
