/*
The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:

If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Create a queue to store the students
        queue<int> queue;
        // Push all the students into the queue
        for (int student : students) {
            queue.push(student);
        }

        // Index to keep track of the sandwiches
        int index = 0;
        // Index to keep track of rotations
        int rotations = 0;

        // Loop through the queue
        while (!queue.empty()) {
            // If the student is at front of the queue prefers the sandwich on the top of the stack
            if (queue.front() == sandwiches[index]) {
                // Student will take it and leave the queue
                queue.pop();
                // Increase the index
                index++;
                // Reset the rotations
                rotations = 0;
            } else {
                // Move the student to the end of the queue
                queue.push(queue.front());
                // Remove the student from the front of the queue
                queue.pop();
                // Increase the rotations
                rotations++;
            }

            // If the rotations are equal to the size of the queue
            if (rotations == queue.size()) {
                // Break the loop
                break;
            }
        }
        // Return the size of the queue
        return queue.size();
    }
};