/*
ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. 
You can assume that always the current list has at least k numbers.
*/

#include <queue>
using namespace std;

class ProductOfNumbers {
private:
    queue<int> q;           // Queue to store numbers
    int runningProduct;     // Running product of the queue elements

public:
    ProductOfNumbers() {
        // Initialize the running product to 1
        runningProduct = 1;
    }

    void add(int num) {
        if (num == 0) {
            // Reset the queue and product when 0 is encountered
            while (!q.empty()) {
                q.pop();
            }
            runningProduct = 1; // Reset product
        } else {
            // Add the number to the queue
            q.push(num);
            runningProduct *= num;
        }
    }

    int getProduct(int k) {
        // Handle case where k is greater than the queue size
        if (k > q.size()) {
            return 0; // Not enough numbers due to zero clearing the sequence
        }

        int tempProduct = runningProduct;
        queue<int> tempQueue = q; // Temporary queue for iteration

        // Remove the first (size - k) elements to calculate the product of the last k numbers
        for (int i = 0; i < q.size() - k; i++) {
            tempProduct /= tempQueue.front();
            tempQueue.pop();
        }

        return tempProduct;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */