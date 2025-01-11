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

#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(vector<int>& arr, int left, 
                     int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver code
int main()
{
    vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int n = arr.size();

    cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted vector is \n";
    printVector(arr);
    return 0;
}