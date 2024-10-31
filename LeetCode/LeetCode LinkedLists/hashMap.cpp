/*
Design a HashMap without using any built-in hash table libraries.

Implement the MyHashMap class:

MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 */
#include <vector>
#include <list>
using namespace std;

class MyHashMap {
private:
    static const int numBuckets = 1000;
    // Vector of lists to represent the hash table
    vector<list<pair<int, int>>> hashTable;

    // Hash function to determine the bucket index for a given key
    int hash(int key) {
        return key % numBuckets;
    }

public:
    MyHashMap() {
        // Initialize the hash table with numBuckets empty lists
        hashTable = vector<list<pair<int, int>>>(numBuckets);
    }
    
    void put(int key, int value) {
        // Calculate the bucket index for the key
        int bucket = hash(key);
        // Check if the key is already present in the bucket
        for (auto &p : hashTable[bucket]) {
            // If the key is found, update the value
            if (p.first == key) {
                p.second = value;
                return;
            } 
        }
        // Add the key-value pair to the bucket
        hashTable[bucket].push_back({key, value});
    }
    
    int get(int key) {
        // Calculate the bucket index for the key
        int bucket = hash(key);
        // Find the key in the bucket and return the value
        for (auto &p : hashTable[bucket]) {
            // If the key is found, return the value
            if (p.first == key) {
                return p.second;
            }
        }
        return -1;  // Key not found
    }
    
    void remove(int key) {
        // Calculate the bucket index for the key
        int bucket = hash(key);
        // Find the key in the bucket and remove it
        for (auto it = hashTable[bucket].begin(); it != hashTable[bucket].end(); ++it) {
            // If the key is found, erase the element
            if (it->first == key) {
                hashTable[bucket].erase(it);
                return;
            }
        }
    }
};