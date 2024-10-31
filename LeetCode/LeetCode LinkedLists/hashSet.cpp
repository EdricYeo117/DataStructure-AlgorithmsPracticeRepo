/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.*/
#include <vector>
#include <list>

using namespace std;

class MyHashSet {
private:
    // Number of buckets for the hash table
    static const int numBuckets = 1000;
    // Vector of lists to represent the hash table
    vector<list<int>> hashTable;
    
    // Hash function to determine the bucket index for a given key
    int hash(int key) {
        return key % numBuckets;
    }
public:
    MyHashSet() : hashTable(numBuckets) {}
    
    void add(int key) {
        // Calculate the bucket index for the key
        int bucket = hash(key);
        // Check if key is already present in the bucket
        for (int k : hashTable[bucket]) {
            if (k == key) {
                return;
            }
            // Add the key to the bucket
        }
        hashTable[bucket].push_back(key);
    }
    
    void remove(int key) {
        // Calculate the bucket index for the key
        int bucket = hash(key);
        // Find the key in the bucket and remove it
        hashTable[bucket].remove(key);
    }
    
    bool contains(int key) {
        // Calculate the bucket index for the key
        int bucket = hash(key);
        // Check if the key is present in the bucket
        for (int k : hashTable[bucket]) {
            if (k == key) {
                return true;
            }
        }
        return false;
    }
};