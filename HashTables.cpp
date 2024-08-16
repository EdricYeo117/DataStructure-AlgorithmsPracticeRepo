#include <iostream>
#include <vector> // Add this line to include the vector header

using namespace std;

class Node
{
public:
    string key;
    int value;
    Node *next;

    Node(string key, int value)
    {
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            dataMap[i] = nullptr;
        }
    }
    ~HashTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            Node *head = dataMap[i];
            Node *temp = head;
            while (head)
            {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    }

    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ":" << endl;
            if (dataMap[i])
            {
                Node *temp = dataMap[i];
                while (temp)
                {
                    cout << "   {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }

    // Hash Function
    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < key.length(); i++)
        {
            int asciiValue = int(key[i]);
            // Hashing to be more random, use prime numbers
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }

    // Insert a key-value pair into the hash table
    void set(string key, int value)
    {
        // Calculate the hash index for the key
        int index = hash(key);

        // Create a new node with the key-value pair
        Node *newNode = new Node(key, value);

        // If the head of the linked list in the bucket is null, set it to the new node
        if (dataMap[index] == nullptr)
        {
            dataMap[index] = newNode;
        }
        else
        { // Otherwise, traverse the linked list until the end and add the new node
            // Create a temporary node pointer and set it to the
            // head of the linked list in the bucket
            Node *temp = dataMap[index];

            // Traverse the linked list until the end
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            // Add the new node to the end of the linked list
            temp->next = newNode;
        }
    }

    // Retrieve the value associated with the specified key from the hash table
    int get(string key)
    {
        // Calculate the hash index for the key
        int index = hash(key);

        // Set a temporary node pointer to the head of the linked list in the bucket
        Node *temp = dataMap[index];

        // Traverse the linked list until the end or until the key is found
        while (temp != nullptr)
        {
            // If the current node's key is equal to the specified key, return its value
            if (temp->key == key)
                return temp->value;

            // Move to the next node in the linked list
            temp = temp->next;
        }

        // If the key is not found in the linked list, return 0
        return 0;
    }

    // Retrieve all keys from the hash table as a vector of strings
    vector<string> keys()
    {
        // Create an empty vector to store the keys
        vector<string> allKeys;

        // Iterate through each bucket in the hash table
        for (int i = 0; i < SIZE; i++)
        {
            // Set a temporary node pointer to the head of the linked list in the bucket
            Node *temp = dataMap[i];

            // Traverse the linked list until the end, adding each key to the vector
            while (temp != nullptr)
            {
                allKeys.push_back(temp->key);
                temp = temp->next;
            }
        }

        // Return the vector containing all the keys in the hash table
        return allKeys;
    }
};

int main()
{
    HashTable *myHashTable = new HashTable();

    // Test the 'set' function by inserting key-value pairs
    myHashTable->set("paint", 20);
    myHashTable->set("bolts", 40);
    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    // Test the 'get' function by retrieving values based on keys
    cout << "Value for 'paint': " << myHashTable->get("paint") << endl; // Expected: 20
    cout << "Value for 'bolts': " << myHashTable->get("bolts") << endl; // Expected: 40
    cout << "Value for 'nails': " << myHashTable->get("nails") << endl; // Expected: 100
    cout << "Value for 'tile': " << myHashTable->get("tile") << endl;   // Expected: 50
    cout << "Value for 'lumber': " << myHashTable->get("lumber") << endl; // Expected: 80

    // Test the 'keys' function by retrieving all keys in the hash table
    vector<string> myKeys = myHashTable->keys();

    cout << "\nAll keys in the hash table:" << endl;
    for (auto key : myKeys)
    {
        cout << key << " "; // Expected: paint bolts nails tile lumber (order may vary based on hash function)
    }
    cout << endl;

    // Test the 'printTable' function by printing the entire hash table
    cout << "\nHash table contents:" << endl;
    myHashTable->printTable();

    // Test the 'get' function with a key that does not exist
    cout << "\nValue for non-existing key 'glue': " << myHashTable->get("glue") << endl; // Expected: 0

    // Clean up
    delete myHashTable;

    /*
        EXPECTED OUTPUT:
        ----------------
        Value for 'paint': 20
        Value for 'bolts': 40
        Value for 'nails': 100
        Value for 'tile': 50
        Value for 'lumber': 80

        All keys in the hash table:
        paint bolts nails tile lumber 

        Hash table contents:
        0:
        1:
        2:    {tile, 50}
        3:
        4:    {lumber, 80}
        5:    {bolts, 40}    {nails, 100}
        6:    {paint, 20}

        Value for non-existing key 'glue': 0
    */
}

