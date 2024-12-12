/*
RecentCounter() Initializes the counter with zero recent requests.

int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, 
and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). 
Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
*/

#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
private:
    // Queue to store the recent requests
    queue<int> queue;

public:
    RecentCounter() {
        // Constructor : Initializes the counter with zero recent requests
    }
    
    int ping(int t) {
        // Add a new request at time t
        queue.push(t);

        // Remove timestamps that are not within the range [t - 3000, t]
        while (!queue.empty() && queue.front() < t - 3000) {
            // Remove the front element from the queue
            queue.pop();
        }
        // Return the number of requests that have happened in the past 3000 milliseconds
        return queue.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */