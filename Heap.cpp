#include <iostream>
#include <vector>

using namespace std;

//Heap is useful for priority queue
class Heap
{
private:
    vector<int> heap;

    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void printHeap()
    {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if (i < heap.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    const vector<int> &getHeap() const
    {
        return heap;
    }

public:
    void insert(int value)
    {
        // Add the new value at the end of the heap array.
        // This might temporarily break the heap's property.
        heap.push_back(value);
        // Set 'current' to the index of the newly added element.
        int current = heap.size() - 1;

        // Start a loop to restore the heap property. This loop
        // continues as long as 'current' isn't the root (index 0)
        // and the current element is larger than its parent. This
        // is essential for maintaining the max heap property.
        while (current > 0 && heap[current] > heap[parent(current)])
        {
            // Swap the current element with its parent if the
            // current element is larger. This is a step towards
            // restoring the max heap property by ensuring that a
            // parent node is always larger than its children.
            swap(current, parent(current));
            // Move up the tree by setting 'current' to the index
            // of the parent node. This step is crucial for the
            // iterative comparison of the newly inserted value
            // with its ancestors, ensuring the heap's integrity.
            current = parent(current);
        }
    }

    void sinkDown(int index)
    {
        // Initialize maxIndex with the current index. This variable
        // will be used to find the largest of the current node and
        // its children.
        int maxIndex = index;
        // Enter a loop that continues indefinitely until explicitly
        // broken out of. The purpose is to restore heap property.
        while (true)
        {
            // Calculate the indices of the left and right children
            // of the current node.
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);

            // If the left child exists and is greater than the
            // current node, update maxIndex to leftIndex. This
            // step identifies the larger of the two children.
            if (leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex])
            {
                maxIndex = leftIndex;
            }

            // Perform a similar check for the right child. If the
            // right child exists and is greater than the current
            // max (either the parent or left child), update maxIndex
            // to rightIndex. This ensures maxIndex points to the
            // largest of the parent and its two children.
            if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex])
            {
                maxIndex = rightIndex;
            }

            // If maxIndex has been updated, indicating that either
            // the left or right child is larger than the parent,
            // swap the parent with this larger child. This is a
            // key step in restoring the max heap property by
            // ensuring parents are larger than their children.
            if (maxIndex != index)
            {
                swap(index, maxIndex);
                // Update index to maxIndex for the next iteration.
                // This move down the tree, continuing to adjust
                // the heap as needed.
                index = maxIndex;
            }
            else
            {
                // If maxIndex has not changed, the heap property
                // has been restored for this subtree, and the loop
                // can be exited.
                return;
            }
        }
    }

    int remove()
    {
        // Check if the heap is empty. If it is,
        // return the minimum integer value as an
        // indication of an underflow condition.
        if (heap.empty())
        {
            return INT_MIN;
        }

        // Store the value at the root of the heap.
        // This is the maximum value in a max heap.
        int maxValue = heap.front();

        // If the heap only contains one element,
        // simply remove it and return its value.
        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            // Replace the root of the heap with the last element
            // in the heap. This action maintains the completeness
            // of the binary tree but may violate the heap property.
            heap[0] = heap.back();
            // Remove the last element as it's now moved to the root.
            heap.pop_back();
            // Call sinkDown to restore the max heap property starting
            // from the root. This method adjusts the position of the
            // new root by moving it down the tree until the heap property
            // is restored.
            sinkDown(0);
        }

        // Return the maximum value that was removed from the heap.
        return maxValue;
    }
};

int main()
{
    // Create an instance of the Heap class.
    Heap heap;

    // Insert values into the heap.
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);
    heap.insert(30);
    heap.insert(15);

    // Print the heap after inserts.
    cout << "Heap after inserts: ";
    heap.printHeap();

    // Remove the maximum element and print the heap.
    cout << "Removed element: " << heap.remove() << endl;
    cout << "Heap after removal: ";
    heap.printHeap();

    // Insert more values into the heap.
    heap.insert(50);
    heap.insert(40);

    // Print the heap after additional inserts.
    cout << "Heap after more inserts: ";
    heap.printHeap();

    // Remove the maximum element and print the heap.
    cout << "Removed element: " << heap.remove() << endl;
    cout << "Heap after removal: ";
    heap.printHeap();

    return 0;
}