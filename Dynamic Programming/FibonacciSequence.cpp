#include <iostream>
#include <vector>
static int counter = 0;
//Normal recursive implementation
int fibonacci(int n) {
    counter++;
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n = 10;
    std::cout << "Fibonacci number at position " << n << ": " << fibonacci(n) << std::endl;
    std::cout << "Number of function calls: " << counter << std::endl;
    return 0;
}
