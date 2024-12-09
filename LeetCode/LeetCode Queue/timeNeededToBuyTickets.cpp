/*
You are given a 0-indexed integer array tickets of length n where the number of tickets 
that the ith person would like to buy is tickets[i].

Each person takes exactly 1 second to buy a ticket.
 A person can only buy 1 ticket at a time and has to go back to the end of the line (which happens instantaneously) 
 in order to buy more tickets. If a person does not have any tickets left to buy, the person will leave the line.

 Return the time taken for the person initially at position k (0-indexed) to finish buying tickets.
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Create a queue to store the tickets
        queue<pair<int, int>> queue;

        // Push all the tickets into the queue
        // Step 1 : Intialise the queue 
        for (int i = 0; i < tickets.size(); i++) {
            // Push the tickets into the queue
            queue.push({tickets[i], i});
        }

        // Time taken to buy the tickets
        int time = 0;

        // Step 2 : Loop through the queue
        while (!queue.empty()) {
            // Get the front element of the queue
            pair<int, int> person = queue.front();
            // Remove the front element from the queue
            queue.pop();
            // Increase the time
            time++;
            // Decrease the number of tickets
           person.first--;

            // If the number of tickets is greater than 0
            if (person.first > 0) {
                // If still require more tickets, add back to queue
                queue.push(person);

            } else if (person.second == k) {
                // If the person is at position k
                // Break the loop
                break;
            }
        }
        // Return the time taken
        return time;
    }
};