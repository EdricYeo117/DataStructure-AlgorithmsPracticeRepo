#include <iostream>

using namespace std;

// Merge Sort
// Merge two subarrays of array[]
// Big O Complexity: O(n log n)
void merge(int array[], int leftIndex, int midIndex, int rightIndex) {
        int leftArraySize = midIndex - leftIndex + 1;
        int rightArraySize = rightIndex - midIndex;
        // Create two temporary subarrays
        int leftArray[leftArraySize];
        int rightArray[rightArraySize];
    
        // Copy the elements of the original array into the two subarrays
        for (int i = 0; i < leftArraySize; i++)
            leftArray[i] = array[leftIndex + i];
        for (int j = 0; j < rightArraySize; j++)
            rightArray[j] = array[midIndex + 1 + j];
    
        // Merge the two subarrays back into the original array
        int index = leftIndex;
        int i = 0;
        int j = 0;
        
        while (i < leftArraySize && j < rightArraySize) {
            if (leftArray[i] <= rightArray[j]) {
                array[index] = leftArray[i];
                index++;
                i++;
            }
            else {
                array[index] = rightArray[j];
                index++;
                j++;
            }
        }
    
        // Copy the remaining elements of the left subarray into the original array
        while (i < leftArraySize) {
            array[index] = leftArray[i];
            index++;
            i++;
        }
    
        // Copy the remaining elements of the right subarray into the original array
        while (j < rightArraySize) {
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }

void mergeSort(int array[], int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return;
    // Find the middle index
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    
    // Recursively sort left and right halves of the array
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex+1, rightIndex);
    
    // Merge the two sorted halves of the array
    merge(array, leftIndex, midIndex, rightIndex);
}


int main() {
    
    int myArray[] = {3,1,4,2};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;


    mergeSort(myArray, leftIndex, rightIndex);


    for (auto value : myArray) {  
        cout << value << " ";
    }

    /*
        EXPECTED OUTPUT:
        ----------------
        1 2 3 4 
        
     */
    
}