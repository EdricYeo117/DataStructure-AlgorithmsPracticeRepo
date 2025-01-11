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

// C++ program for implementation of Insertion Sort
#include <iostream>
using namespace std;

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        // Store the value of the current element in a temp variable
        int key = arr[i];
        // Initialize j to be one index behind i
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver method
int main()
{
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}

/* This code is contributed by Hritik Shah. */