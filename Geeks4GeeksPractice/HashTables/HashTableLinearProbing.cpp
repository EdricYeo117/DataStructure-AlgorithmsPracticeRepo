// Hash Table Implementation in C++ using Linear Probing
#include <bits/stdc++.h>
using namespace std;

/*
    Structure: HashEntry
    Purpose: Represents a single key-value pair in the hash table along with its state.
    Features:
        - Stores integer keys and integer values.
        - Maintains a flag to indicate if the entry is active, deleted, or empty.
*/
struct HashEntry {
    int key;        // Key of the entry
    int value;      // Value associated with the key
    bool isActive;  // Status flag: true if active, false if deleted or never used

    /*
        Constructor: HashEntry
        Purpose: Initialize a hash entry with a given key and value.
        Parameters:
            - int key: The key for the hash entry.
            - int value: The value associated with the key.
        Pre: None.
        Post:
            - A HashEntry is created with 'key' and 'value' set to the provided parameters.
            - 'isActive' is set to true, indicating that the entry is active.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    HashEntry(int key, int value) : key(key), value(value), isActive(true) {}
};

/*
    Class: HashTable
    Purpose: Implements a hash table with linear probing for collision resolution.
    Features:
        - Insert: Add a key-value pair to the hash table.
        - Remove: Delete a key-value pair from the hash table using the key.
        - Search: Retrieve the value associated with a given key.
        - Display: Print the contents of the hash table.
        - isEmpty: Check if the hash table is empty.
        - getSize: Retrieve the current number of active key-value pairs in the hash table.
    - Includes constructor and destructor for proper resource management.
*/
class HashTable {
private:
    HashEntry** table;  // Array of pointers to HashEntry representing the buckets
    int numBuckets;     // Total number of buckets in the hash table
    int currentSize;    // Current number of active key-value pairs in the hash table
    const float loadFactorThreshold = 0.7;  // Threshold to trigger resizing

    /*
        Function: hashFunction
        Purpose: Compute the hash index for a given key.
        Parameters:
            - int key: The key to be hashed.
        Returns:
            - int: The index of the bucket where the key-value pair should be placed.
        Pre: None.
        Post: No changes to the hash table.
        Time Complexity: O(1) - Arithmetic operations are constant time.
        Space Complexity: O(1) - Uses a constant amount of extra space.
    */
    int hashFunction(int key) const {
        return key % numBuckets;  // Simple modulo-based hash function
    }

    /*
        Function: rehash
        Purpose: Resize the hash table when the load factor exceeds the threshold to maintain efficiency.
        Parameters: None.
        Returns: 
            - void
        Pre: 
            - The current load factor (currentSize / numBuckets) exceeds loadFactorThreshold.
        Post: 
            - The hash table size is doubled.
            - All existing active key-value pairs are re-inserted into the new table.
        Time Complexity: O(n), where n is the number of key-value pairs.
        Space Complexity: O(n) - Requires additional space for the new table.
    */
    void rehash() {
        int oldNumBuckets = numBuckets;
        numBuckets *= 2;  // Example: Double the number of buckets
        HashEntry** newTable = new HashEntry*[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            newTable[i] = nullptr;  // Initialize all new buckets as empty
        }

        // Re-insert all active key-value pairs into the new table
        for (int i = 0; i < oldNumBuckets; i++) {
            if (table[i] != nullptr && table[i]->isActive) {
                insert(table[i]->key, table[i]->value, newTable);
            }
        }

        // Deallocate the old table
        for (int i = 0; i < oldNumBuckets; i++) {
            delete table[i];
        }
        delete[] table;

        // Point to the new table
        table = newTable;
    }

    /*
        Function: insert
        Purpose: Helper function to insert a key-value pair into a specified table (used during rehashing).
        Parameters:
            - int key: The key to be inserted.
            - int value: The value associated with the key.
            - HashEntry** targetTable: The table where the key-value pair should be inserted.
        Returns: 
            - void
        Pre: 
            - 'targetTable' must be properly allocated with 'numBuckets' buckets.
        Post: 
            - The key-value pair is inserted into 'targetTable'.
        Time Complexity: O(1) on average
        Space Complexity: O(1)
    */
    void insert(int key, int value, HashEntry** targetTable) {
        int index = key % numBuckets;
        while (targetTable[index] != nullptr && targetTable[index]->isActive) {
            index = (index + 1) % numBuckets;  // Linear probing
        }
        targetTable[index] = new HashEntry(key, value);
    }

public:
    /*
        Constructor: HashTable
        Purpose: Initialize a hash table with a specified number of buckets.
        Parameters:
            - int numBuckets: The number of buckets to be used in the hash table.
        Pre: 
            - 'numBuckets' should be a positive integer.
        Post:
            - 'table' is initialized as an array of nullptrs with size 'numBuckets'.
            - 'currentSize' is set to 0.
        Time Complexity: O(n), where n is numBuckets (initialization of the array).
        Space Complexity: O(n), where n is numBuckets (storage for the bucket array).
    */
    HashTable(int numBuckets) {
        this->numBuckets = numBuckets;
        this->currentSize = 0;
        table = new HashEntry*[numBuckets];
        for (int i = 0; i < numBuckets; i++) {
            table[i] = nullptr;  // Initialize all buckets as empty
        }
    }

    /*
        Destructor: ~HashTable
        Purpose: Clean up all dynamically allocated memory to prevent memory leaks when a HashTable object is destroyed.
        Parameters: None.
        Pre: None.
        Post:
            - All HashEntry objects in the hash table are deleted.
            - The bucket array is deallocated.
        Time Complexity: O(n), where n is the number of buckets (each bucket is checked).
        Space Complexity: O(1)
    */
    ~HashTable() {
        for (int i = 0; i < numBuckets; i++) {
            if (table[i] != nullptr) {
                delete table[i];
                table[i] = nullptr;
            }
        }
        delete[] table;  // Deallocate the bucket array
    }

    /*
        Function: isEmpty
        Purpose: Check if the hash table is empty (i.e., contains no active key-value pairs).
        Parameters: None.
        Returns: 
            - bool: Returns true if the hash table is empty; otherwise, false.
        Pre: None.
        Post: No changes to the hash table.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    bool isEmpty() const {
        return currentSize == 0;
    }

    /*
        Function: getSize
        Purpose: Retrieve the current number of active key-value pairs in the hash table.
        Parameters: None.
        Returns: 
            - int: The number of active key-value pairs in the hash table.
        Pre: None.
        Post: No changes to the hash table.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    int getSize() const {
        return currentSize;
    }

    /*
        Function: insert
        Purpose: Add a key-value pair to the hash table.
        Parameters:
            - int key: The key for the key-value pair.
            - int value: The value associated with the key.
        Returns: 
            - void
        Pre: 
            - None. If the key already exists, its value will be updated.
        Post: 
            - If the key does not exist, a new HashEntry is created and placed in the appropriate bucket.
            - If the key exists, its value is updated to the new value.
            - The size of the hash table increases by 1 if a new key is added.
            - If the load factor exceeds the threshold, the hash table is resized (rehashing occurs).
        Time Complexity: O(1) on average - Constant time for insertion assuming a good hash function and low load factor.
        Space Complexity: O(1) - Allocates space for one new node regardless of hash table size.
    */
    void insert(int key, int value) {
        if ((float)(currentSize + 1) / numBuckets > loadFactorThreshold) {
            rehash();  // Resize the table if load factor exceeds the threshold
        }

        int index = hashFunction(key);
        int startIndex = index;  // To detect if we've looped around the table

        while (table[index] != nullptr && table[index]->isActive) {
            if (table[index]->key == key) {
                table[index]->value = value;  // Update existing key's value
                return;
            }
            index = (index + 1) % numBuckets;  // Linear probing
            if (index == startIndex) {
                // Table is full, which should not happen due to rehashing
                throw overflow_error("Hash Table is full");
            }
        }

        // Insert new key-value pair
        table[index] = new HashEntry(key, value);
        currentSize++;
    }

    /*
        Function: remove
        Purpose: Remove a key-value pair from the hash table using the key.
        Parameters:
            - int key: The key of the key-value pair to be removed.
        Returns: 
            - bool: Returns true if the key was found and removed; otherwise, false.
        Pre: 
            - The key should exist in the hash table for successful removal.
        Post: 
            - If the key is found, the corresponding HashEntry is marked as inactive (deleted).
            - The size of the hash table decreases by 1 if the key is removed.
        Time Complexity: O(1) on average - Constant time for removal assuming a good hash function and low load factor.
        Space Complexity: O(1) - Uses a constant amount of extra space.
    */
    bool remove(int key) {
        int index = hashFunction(key);
        int startIndex = index;  // To detect if we've looped around the table

        while (table[index] != nullptr) {
            if (table[index]->isActive && table[index]->key == key) {
                table[index]->isActive = false;  // Mark the entry as inactive (deleted)
                currentSize--;
                return true;  // Key successfully removed
            }
            index = (index + 1) % numBuckets;  // Linear probing
            if (index == startIndex) {
                break;  // Searched all buckets
            }
        }

        return false;  // Key not found
    }

    /*
        Function: search
        Purpose: Retrieve the value associated with a given key.
        Parameters:
            - int key: The key to search for in the hash table.
        Returns: 
            - int: The value associated with the key. Returns INT_MIN if the key is not found.
        Pre: 
            - None. If the key does not exist, INT_MIN is returned.
        Post: 
            - No changes to the hash table.
        Time Complexity: O(1) on average - Constant time for search assuming a good hash function and low load factor.
        Space Complexity: O(1) - Uses a constant amount of extra space.
    */
    int search(int key) const {
        int index = hashFunction(key);
        int startIndex = index;  // To detect if we've looped around the table

        while (table[index] != nullptr) {
            if (table[index]->isActive && table[index]->key == key) {
                return table[index]->value;  // Key found, return its value
            }
            index = (index + 1) % numBuckets;  // Linear probing
            if (index == startIndex) {
                break;  // Searched all buckets
            }
        }

        return INT_MIN;  // Key not found
    }

    /*
        Function: display
        Purpose: Print the contents of the hash table.
        Parameters: None.
        Returns: 
            - void
        Pre: 
            - None.
        Post: 
            - The key-value pairs in each bucket are printed to the console.
        Time Complexity: O(n), where n is numBuckets (each bucket is checked).
        Space Complexity: O(1) - Uses a constant amount of extra space.
    */
    void display() const {
        for (int i = 0; i < numBuckets; i++) {
            if (table[i] != nullptr && table[i]->isActive) {
                cout << "Bucket " << i << ": [" << table[i]->key << " : " << table[i]->value << "]\n";
            } else {
                cout << "Bucket " << i << ": [Empty]\n";
            }
        }
    }
};