// Identical to Heap.cpp, except that index 0 is blank
#include <iostream>
#include <vector>

using namespace std;

// Heap is useful for priority queue
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

    void insert(int value)
    {
        // Append the new value to the end of the heap. This
        // ensures the tree remains complete, but may temporarily
        // violate the heap's ordering property.
        heap.push_back(value);
        // Set 'current' to the index of the newly added element.
        int current = heap.size() - 1;

        // Begin a loop to restore the heap property. The loop
        // conditions ensure that we're not at the root (since
        // the root has no parent to compare with) and that the
        // current node is less than its parent. This condition
        // is crucial for a min heap, where parents must be less
        // than their children.
        while (current > 0 && heap[current] < heap[parent(current)])
        {
            // Swap the current node with its parent. This step
            // moves the new element closer to the correct position
            // in the heap by ensuring the parent is always smaller.
            swap(current, parent(current));
            // Update 'current' to the index of the parent, moving
            // up the tree. This is essential for continuing the
            // comparison and swap process up the heap until the
            // newly inserted element is in the correct position.
            current = parent(current);
        }
    }

    void sinkDown(int index)
    {
        // Start with the assumption that the current node
        // (indexed by 'index') is the smallest in its subtree.
        int minIndex = index;
        // Continuously attempt to find a child node smaller
        // than the current node to maintain the min heap property.
        while (true)
        {
            // Calculate indices of left and right children.
            int leftIndex = leftChild(index);
            int rightIndex = rightChild(index);

            // Check if left child exists and is smaller than
            // the current smallest value. If so, update minIndex
            // to the index of this left child.
            if (leftIndex < heap.size() && heap[leftIndex] < heap[minIndex])
            {
                minIndex = leftIndex;
            }

            // Perform a similar check for the right child.
            // Update minIndex if the right child exists and is
            // smaller than the current smallest known value.
            if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex])
            {
                minIndex = rightIndex;
            }

            // If either child was smaller than the current node,
            // swap the current node with this smaller child. This
            // is essential for moving larger elements down the heap
            // to restore the min heap property.
            if (minIndex != index)
            {
                swap(index, minIndex);
                // Update 'index' to the position of the child to
                // continue sinking down the heap if necessary.
                index = minIndex;
            }
            else
            {
                // If no smaller child was found (meaning minIndex
                // didn't change), the current node is correctly
                // placed, and we can stop the process.
                return;
            }
        }
    }

    int remove()
    {
        // Check if the heap is empty. If true, return INT_MIN
        // to indicate that there's nothing to remove, which
        // also serves as an error code for underflow.
        if (heap.empty())
        {
            return INT_MIN;
        }

        // Store the value at the front of the heap. This is the
        // minimum value in a min heap and the one we'll be removing.
        int minValue = heap.front();

        // If the heap contains only one element, remove it
        // directly. This is a simple case where no further
        // adjustment is needed.
        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            // Replace the root of the heap (the min value) with the
            // last element in the heap. This action maintains the
            // completeness of the binary tree but might violate
            // the heap's ordering property.
            heap[0] = heap.back();
            // Remove the last element since it's now moved to the
            // root position.
            heap.pop_back();
            // Restore the heap's ordering property by calling
            // sinkDown starting from the root. This function
            // moves the new root down the heap until the min heap
            // property is restored.
            sinkDown(0);
        }

        // Return the minimum value that was removed.
        return minValue;
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

    // Remove the minimum element and print the heap.
    cout << "Removed element: " << heap.remove() << endl;
    cout << "Heap after removal: ";
    heap.printHeap();

    // Insert more values into the heap.
    heap.insert(50);
    heap.insert(40);

    // Print the heap after additional inserts.
    cout << "Heap after more inserts: ";
    heap.printHeap();

    // Remove the minimum element and print the heap.
    cout << "Removed element: " << heap.remove() << endl;
    cout << "Heap after removal: ";
    heap.printHeap();

    return 0;
}
