#include <bits/stdc++.h>
using namespace std;

/*
    Class: HashNode
    Purpose: Represents a single key-value pair in the hash table.
    Features:
        - Stores integer keys and integer values.
        - Points to the next HashNode in the chain (for handling collisions via separate chaining).
*/
class HashNode {
public:
    int key;            // Key of the node
    int value;          // Value associated with the key
    HashNode* next;     // Pointer to the next node in the chain

    /*
        Constructor: HashNode
        Purpose: Initialize a hash node with a given key and value.
        Parameters:
            - int key: The key for the hash node.
            - int value: The value associated with the key.
        Pre: None.
        Post:
            - A HashNode is created with 'key' and 'value' set to the provided parameters.
            - 'next' is initialized to nullptr.
        Time Complexity: O(1)
        Space Complexity: O(1)
    */
    HashNode(int key, int value) {
        this->key = key;          // Assign the provided key to the node
        this->value = value;      // Assign the provided value to the node
        this->next = nullptr;     // Initialize the next pointer to nullptr
    }
};

/*
    Class: HashTable
    Purpose: Implements a hash table with separate chaining for collision resolution.
    Features:
        - Insert: Add a key-value pair to the hash table.
        - Remove: Delete a key-value pair from the hash table using the key.
        - Search: Retrieve the value associated with a given key.
        - Display: Print the contents of the hash table.
        - isEmpty: Check if the hash table is empty.
    - Includes constructor and destructor for proper resource management.
*/
class HashTable {
private:
    // Array of pointers to HashNode representing the buckets
    HashNode** table; // This is a pointer to another pointer (double pointer), i.e pointer that holds the address of another pointer
    int numBuckets;  // Number of buckets in the hash table

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

public:
    /*
        Constructor: HashTable
        Purpose: Initialize a hash table with a specified number of buckets.
        Parameters:
            - int numBuckets: The number of buckets to be used in the hash table.
        Pre: numBuckets should be a positive integer.
        Post:
            - 'table' is initialized as an array of nullptrs with size 'numBuckets'.
            - 'numBuckets' is set to the provided parameter.
        Time Complexity: O(n), where n is numBuckets (initialization of the array).
        Space Complexity: O(n), where n is numBuckets (storage for the bucket array).
    */
    HashTable(int numBuckets) {
        this->numBuckets = numBuckets;
        table = new HashNode*[numBuckets];
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
            - All HashNodes in the hash table are deleted.
            - The bucket array is deallocated.
        Time Complexity: O(n), where n is the number of buckets (each bucket is traversed to delete nodes).
        Space Complexity: O(1)
    */
    ~HashTable() {
        for (int i = 0; i < numBuckets; i++) {
            HashNode* entry = table[i];
            while (entry != nullptr) {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;  // Delete each node in the chain
            }
            table[i] = nullptr;  // Optional: Set bucket to nullptr
        }
        delete[] table;  // Deallocate the bucket array
    }

    /*
        Function: isEmpty
        Purpose: Check if the hash table is empty (i.e., contains no key-value pairs).
        Parameters: None.
        Returns: 
            - bool: Returns true if the hash table is empty; otherwise, false.
        Pre: None.
        Post: No changes to the hash table.
        Time Complexity: O(n), where n is numBuckets (must check each bucket).
        Space Complexity: O(1) - Uses a constant amount of extra space.
    */
    bool isEmpty() const {
        for (int i = 0; i < numBuckets; i++) {
            if (table[i] != nullptr) {
                return false;  // Found at least one key-value pair
            }
        }
        return true;  // All buckets are empty
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
            - If the key does not exist, a new HashNode is created and added to the appropriate bucket.
            - If the key exists, its value is updated to the new value.
            - The size of the hash table increases by 1 if a new key is added.
        Time Complexity: O(1) on average - Constant time for insertion assuming a good hash function and low load factor.
        Space Complexity: O(1) - Allocates space for one new node regardless of hash table size.
    */
    void insert(int key, int value) {
        int bucketIndex = hashFunction(key);  // Determine the appropriate bucket

        // Check if the key already exists in the chain
        HashNode* entry = table[bucketIndex];
        while (entry != nullptr) {
            if (entry->key == key) {
                entry->value = value;  // Update existing key's value
                return;
            }
            entry = entry->next;
        }

        // If key does not exist, create a new node and add it to the front of the chain
        HashNode* newNode = new HashNode(key, value);
        newNode->next = table[bucketIndex];
        table[bucketIndex] = newNode;
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
            - If the key is found, the corresponding HashNode is removed from the chain.
            - The size of the hash table decreases by 1 if the key is removed.
        Time Complexity: O(1) on average - Constant time for removal assuming a good hash function and low load factor.
        Space Complexity: O(1) - Uses a constant amount of extra space for temporary pointers.
    */
    bool remove(int key) {
        int bucketIndex = hashFunction(key);  // Determine the appropriate bucket

        HashNode* entry = table[bucketIndex];
        HashNode* prev = nullptr;

        // Traverse the chain to find the key
        while (entry != nullptr && entry->key != key) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            return false;  // Key not found
        }

        if (prev == nullptr) {
            // The key is in the first node of the chain
            table[bucketIndex] = entry->next;
        } else {
            // The key is in a node beyond the first
            prev->next = entry->next;
        }

        delete entry;  // Deallocate memory of the removed node
        return true;   // Key successfully removed
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
        Space Complexity: O(1) - Uses a constant amount of extra space for temporary pointers.
    */
    int search(int key) const {
        int bucketIndex = hashFunction(key);  // Determine the appropriate bucket

        HashNode* entry = table[bucketIndex];
        while (entry != nullptr) {
            if (entry->key == key) {
                return entry->value;  // Key found, return its value
            }
            entry = entry->next;
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
        Time Complexity: O(n + m), where n is the number of buckets and m is the number of key-value pairs.
        Space Complexity: O(1) - Uses a constant amount of extra space for temporary pointers.
    */
    void display() const {
        for (int i = 0; i < numBuckets; i++) {
            HashNode* entry = table[i];
            cout << "Bucket " << i << ": ";
            while (entry != nullptr) {
                cout << "[" << entry->key << ": " << entry->value << "] -> ";
                entry = entry->next;
            }
            cout << "nullptr\n";
        }
    }
};