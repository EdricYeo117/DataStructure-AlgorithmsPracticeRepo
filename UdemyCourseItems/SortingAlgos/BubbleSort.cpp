#include <iostream>

using namespace std;

// Function to perform Bubble Sort on an integer array
void bubbleSort(int array[], int size) {
    // Outer loop to control the number of passes through the array
    for (int i = size - 1; i > 0; i--) {
        // Inner loop to iterate through the unsorted part of the array
        for (int j = 0; j < i; j++) {
            // Compare adjacent elements and swap if they are in the wrong order
            if (array[j] > array[j+1]) {
                // Swap array[j] and array[j+1] using a temporary variable
                // Store array[j] value in a temporary variable
                int temp = array[j];      
                // Assign array[j+1] value to array[j]
                array[j] = array[j+1];   
                // Assign temporary variable value to array[j+1] 
                array[j+1] = temp;        
            }
        }
    }
}

int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    bubbleSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}