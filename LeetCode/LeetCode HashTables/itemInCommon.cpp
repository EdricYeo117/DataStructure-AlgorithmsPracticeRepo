#include <vector>
#include <unordered_map>

using namespace std;

bool itemInCommon(vector<int> vect1, vector<int> vect2) {
    // Create an unordered_map to store elements of vect1
    unordered_map<int, bool> myMap;
    
    // Populate the map with elements from vect1
    for (int num : vect1) {
        myMap[num] = true;
    }
    
    // Check if any element from vect2 exists in the map
    for (int num : vect2) {
        if (myMap.find(num) != myMap.end()) {
            return true; // Found a common element
        }
    }
    
    // No common element found
    return false;
}
