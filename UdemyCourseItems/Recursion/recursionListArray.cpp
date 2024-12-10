// Recursive function to add an item at a specific index in the list
/*
Time complexity: O(n) worst case, O(index) best case
Space complexity: O(n) worst case, O(index) best case
*/
bool List::addR(int index, ItemType item) {
    // Check if the index is within bounds
    if (index > size) {
        return false; // Index out of bounds
    }

    // Base case: If the index equals the size, add the item at the end
    if (index == size) {
        items[size] = item; // Add the new item
        size++;             // Increment the size
        return true;
    }

    // Recursive case: Shift items recursively to the right
    addR(index + 1, items[index]);
    items[index] = item; // Insert the new item at the correct position
    return true;
}

// Recursive function to remove an item at a specific index in the list
/*
Time complexity: O(n) worst case, O(index) best case
Space complexity: O(n) worst case, O(index) best case
*/
void List::removeR(int index) {
    // Ensure the index is within bounds
    if (index >= size) {
        return; // Index out of bounds, nothing to remove
    }

    // Base case: If this is the last element, simply reduce the size
    if (index == size - 1) {
        size--; // Decrement the size of the list
        return;
    }

    // Recursive case: Shift the current element to the left
    items[index] = items[index + 1];
    
    // Recur for the next index
    removeR(index + 1);
}

// Recursive function to count the number of occurrences of an item in the list
/*
Time complexity: O(n) worst case
Space complexity: O(n) worst case
*/
int List::count(ItemType item) {
    // Start the recursive count from index 0
    return countR(0, item);
}

int List::countR(int index, ItemType item) {
    // Base case: If the index is out of bounds, return 0
    if (index >= size) {
        return 0;
    }

    // Recursive case: Check if the current item matches the target
    return (items[index] == item ? 1 : 0) + countR(index + 1, item);
}

// Recursive function to display in reverse order
/*
Time complexity: O(n) due to the recursive calls
Space complexity: O(n) due to n frames in the call stack
*/
void List::displayReverseOrder(string array[], int n) {
    // Base case: If the array has only one element, print it
    if (n == 1) {
        cout << array[n - 1] << endl;
        return; // End the recursion
    }

    // Recursive case: Print the current element and recur for the rest
    cout << array[n - 1] << endl;
    displayReverseOrder(array, n - 1);
}

// Recursive function to calculate sum of elements in the array 
/*
Time complexity: O(n) due to the recursive calls
Space complexity: O(n) due to n frames in the call stack
*/
int findSum(int array[], int N) {
    // Base case: If there are no elements, the sum is 0
    if (N <= 0) {
        return 0;
    }

    // Recursive case: Add the last element to the sum of the remaining array
    return findSum(array, N - 1) + array[N - 1];
}


// Recursive function to calculate all the even numbers in the array
/*
Time complexity: O(n) due to the recursive calls
Space complexity: O(n) due to n frames in the call stack
*/
int List::addEven(int n) {
    // Base case: If we've reached the end of the list, stop recursion
    if (n >= size) {
        return 0;
    }

    // Recursive case: Add the current item if it's even, otherwise skip it
    if (items[n] % 2 == 0) {
        return items[n] + addEven(n + 1);
    } else {
        return addEven(n + 1);
    }
}

// Recursive function to find maximum item in the list
/*
Time complexity: O(n) due to the recursive calls
Space complexity: O(n) due to n frames in the call stack
*/
int findMax(int array[], int n) {
    // Base case: If the array has only one element, return it
    if (n == 1) {
        return array[0];
    }

    // Recursive case: Find the maximum in the rest of the array
    int maxInRest = findMax(array, n - 1);

    // Compare the current element with the maximum of the rest
    return (array[n - 1] > maxInRest) ? array[n - 1] : maxInRest;
}

// Recursive function to sort an array in ascending order
/*
Time complexity: O(n log n) due to the merge sort algorithm
Space complexity: O(n) due to the temporary arrays used in merge
*/
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of the left subarray
    int n2 = right - mid;     // Size of the right subarray

    // Create temporary subarrays
    int leftArray[n1], rightArray[n2];

    // Copy data to temporary subarrays
    for (int i = 0; i < n1; i++) {
        leftArray[i] = array[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArray[i] = array[mid + 1 + i];
    }

    // Merge the temporary subarrays back into the original array
    int i = 0;      // Initial index of left subarray
    int j = 0;      // Initial index of right subarray
    int k = left;   // Initial index of merged subarray

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of the left subarray
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy any remaining elements of the right subarray
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right) {
    // Base case: If the subarray has only one element, it's already sorted
    if (left >= right) {
        return;
    }

    // Find the middle point
    int mid = left + (right - left) / 2;

    // Recursively sort the left and right halves
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);

    // Merge the sorted halves
    merge(array, left, mid, right);
}

/*
int main() {
    int array[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(array) / sizeof(array[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    mergeSort(array, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}*/