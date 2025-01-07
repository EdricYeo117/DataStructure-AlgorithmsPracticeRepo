/*
Given an array of n elements. 
The task is to check if it is an Inorder traversal of any Binary Search Tree or not.
*/


#include<bits/stdc++.h>
using namespace std;

// Function that returns true if array is Inorder
// traversal of any Binary Search Tree or not.
bool isInorder(vector<int> &arr) {
    int n = arr.size();
  
    // Array has one or no element
    if (n == 0 || n == 1)
        return true;

    for (int i = 1; i < n; i++)

        // Unsorted pair found
        if (arr[i-1] > arr[i])
            return false;

    // No unsorted pair found
    return true;
}

int main() {
    vector<int> arr = { 19, 23, 25, 30, 45 };
    
    if (isInorder(arr))
        cout << "true";
    else
        cout << "false";
        
  return 0;
}