#include <iostream>

using namespace std;

// Function to perform Bubble Sort on an integer array
void insertionSort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        // Store the value of the current element in a temp variable
        int temp = array[i];
        // Initialize j to be one index behind i
        int j = i - 1;
        // Shift elements to the right until the correct position for temp is found
        while (j > -1 && temp < array[j]) {
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}


int main() {
    
    int myArray[] = {6,4,2,5,1,3};

    int size = sizeof(myArray) / sizeof(myArray[0]);


    insertionSort(myArray, size);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 5 6 
        
     */
    
}
