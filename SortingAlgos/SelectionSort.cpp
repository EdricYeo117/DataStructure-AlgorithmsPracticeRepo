#include <iostream>

using namespace std;

// Sorts an array of integers in ascending order using selection sort.
// Input: an array of integers 'array', and its size 'size'.
void selectionSort(int array[], int size) {
    // Iterate through the array from left to right.
    for (int i = 0; i < size; i++) {
        // Find the minimum value in the unsorted part of the array.
        int minIndex = i;
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the minimum value with the first element in the unsorted part of the array.
        if (i != minIndex) {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}


int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    selectionSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}
