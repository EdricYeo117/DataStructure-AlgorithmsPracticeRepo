#include <iostream>
#include <unordered_set>
 
using namespace std;
 
int main() {
    // Create a set
    unordered_set<int> mySet = {1, 2, 3, 4, 5};
 
    // Add elements to the set
    mySet.insert(6);
    mySet.insert(7);
 
    // Remove an element from the set
    mySet.erase(2);
 
    // Checking if an element is in a set
    if (mySet.find(10) != mySet.end()) {
        cout << "Found 10 in mySet" << endl;
    }
 
    // Check size of the set
    cout << "Size of mySet: " << mySet.size() << endl;
 
    // Check if a set is empty
    if (mySet.empty()) {
        cout << "Set is empty!" << endl;
    } else {
        cout << "Set is not empty!" << endl;
    }
 
    // Clearing all elements from a set
    mySet.clear();
    cout << "After clearing, size: " << mySet.size() << endl;
}