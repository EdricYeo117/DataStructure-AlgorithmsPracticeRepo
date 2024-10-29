#include <iostream>
using namespace std;

class ArrayLinkedList {
private:
    int* arr;          // Array to hold elements
    int size;          // Current number of elements in the list
    int capacity;      // Maximum capacity of the list

public:
    // Constructor to initialize an empty array-based linked list with a given capacity
    ArrayLinkedList(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }

    // Destructor to release memory allocated for the array
    ~ArrayLinkedList() {
        delete[] arr;
    }

    // Function to display all elements in the array-based list
    void traverseList() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to add an element at the end of the list
    void insertAtEnd(int value) {
        if (size >= capacity) {
            cerr << "Error: List is full, cannot insert." << endl;
            return;
        }
        arr[size++] = value;
    }

    // Function to add an element at the beginning of the list
    void insertAtBeginning(int value) {
        if (size >= capacity) {
            cerr << "Error: List is full, cannot insert." << endl;
            return;
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    // Function to delete the first element from the list
    void deleteFromBeginning() {
        if (size == 0) {
            cerr << "Error: List is empty, cannot delete." << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }

    // Function to delete the last element from the list
    void deleteFromEnd() {
        if (size == 0) {
            cerr << "Error: List is empty, cannot delete." << endl;
            return;
        }
        size--;
    }

    // Function to search for an element in the list
    bool searchList(int value) const {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                return true;
            }
        }
        return false;
    }

    // Function to get the number of elements in the list
    int findLength() const {
        return size;
    }

    // Function to rotate the array-based list by moving the first 'k' elements to the end
    void rotateList(int k) {
        if (size == 0 || k <= 0) return;

        // Ensure that k is within the bounds of the list size
        k = k % size;
        if (k == 0) return;

        // Temporary array to store the rotated list
        int* temp = new int[size];

        // Copy the elements after the rotation point to the start of temp
        int index = 0;
        for (int i = k; i < size; i++) {
            temp[index++] = arr[i];
        }

        // Copy the first 'k' elements to the end of temp
        for (int i = 0; i < k; i++) {
            temp[index++] = arr[i];
        }

        // Copy the rotated array back to the original array
        for (int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }

        // Free the temporary array memory
        delete[] temp;
    }
};
