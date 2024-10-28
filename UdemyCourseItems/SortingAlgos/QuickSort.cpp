#include <iostream>

using namespace std;

// Quick Sort
// Big O Notation: O(n log n) average case, O(n^2) worst case
void swap(int array[], int firstIndex, int secondIndex) {
    // Swap the elements at firstIndex and secondIndex
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex) {
    // The pivot element is initially at pivotIndex.
    // swapIndex is initialized to pivotIndex and will keep track of where the pivot should go.
    int swapIndex = pivotIndex;
 
    // Iterate through the array from the element after the pivotIndex to endIndex
    for (int i = pivotIndex + 1; i <= endIndex; i++) {
        // If the current element is less than the pivot element (which is at pivotIndex),
        // increment the swapIndex and swap the current element with the element at swapIndex.
        // This process moves elements smaller than the pivot to the left side of the array.
        if (array[i] < array[pivotIndex]) {
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    
    // After the loop, swap the pivot element with the element at swapIndex.
    // This places the pivot in its correct position within the array.
    swap(array, pivotIndex, swapIndex);
 
    // Return the final position of the pivot element.
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex) {
    // Base case: If the subarray has one or no elements, it is already sorted.
    // This condition also helps terminate the recursion.
    if (leftIndex >= rightIndex) return;

    // Recursive case:
    // Choose a pivot element and partition the array around it.
    // The pivot function returns the index where the pivot element is placed in its correct sorted position.
    int pivotIndex = pivot(array, leftIndex, rightIndex);

    // Recursively sort the subarray on the left of the pivot element.
    // This includes all elements that are less than the pivot.
    quickSort(array, leftIndex, pivotIndex - 1);

    // Recursively sort the subarray on the right of the pivot element.
    // This includes all elements that are greater than the pivot.
    quickSort(array, pivotIndex + 1, rightIndex);
}

int main() {
    int array[] = {29, 10, 14, 37, 14, 3, 12, 40};
    int size = sizeof(array) / sizeof(array[0]);

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    quickSort(array, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;

    /* -----------------------------------
    Expected Output:
    Original array: 29 10 14 37 14 3 12 40 
    Sorted array: 3 10 12 14 14 29 37 40 
    ------------------------------------- */
}