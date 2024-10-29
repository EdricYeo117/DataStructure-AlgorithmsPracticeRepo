#include <cmath> // For log10 function

int count_digit(int num) {
    return (num == 0) ? 1 : (int)log10(num) + 1;
}

bool isPalindrome(int num) {
    int num_digits = count_digit(num);
    
    // Base case: A single-digit number is always a palindrome
    if (num_digits == 1) {
        return true;
    }

    // Calculate 10^(num_digits - 1) to get the left-most digit
    int power = 1;
    for (int i = 1; i < num_digits; i++) {
        power *= 10;
    }

    // Get the left-most and right-most digits
    int left_digit = num / power;
    int right_digit = num % 10;

    // If they don't match, it's not a palindrome
    if (left_digit != right_digit) {
        return false;
    }

    // Remove the left-most and right-most digits and call recursively
    num = (num % power) / 10; // Removing both digits

    // Recursive call
    return isPalindrome(num);
}

// Example usage
#include <iostream>
int main() {
    int num = 1221;
    if (isPalindrome(num)) {
        std::cout << num << " is a palindrome.\n";
    } else {
        std::cout << num << " is not a palindrome.\n";
    }
    return 0;
}
