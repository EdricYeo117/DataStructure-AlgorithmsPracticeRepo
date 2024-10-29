int count_digit(int number) {
    if (number < 10) // base case
        return 1;

    number = number / 10;
    return 1 + count_digit(number); // recursive step
}