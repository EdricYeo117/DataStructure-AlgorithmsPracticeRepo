/*
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day, 
    starting from delay days after discovering the secret. You are also given an integer forget, 
    which means that each person will forget the secret forget days after discovering it. 
A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n. 
Since the answer may be very large, return it modulo 109 + 7.
*/

#include <queue>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;

        // Queue to track sharers (startDay, sharers)
        queue<pair<int, int>> q;
        int totalSharers = 0;    // Total number of people actively sharing the secret
        int totalAware = 0;      // Total number of people aware of the secret

        // Day 1: One person knows the secret and starts sharing
        q.push({1, 1});
        totalSharers = 1;

        // Simulate each day
        for (int day = 1; day <= n; day++) {
            // Remove people who forget the secret today
            while (!q.empty() && q.front().first + forget == day) {
                totalSharers = (totalSharers - q.front().second + mod) % mod;
                q.pop();
            }

            // Add people who start sharing today
            if (!q.empty() && q.front().first + delay == day) {
                q.push({day, totalSharers});
            }

            // Update the total number of people aware of the secret
            totalAware = (totalSharers + totalAware) % mod;
        }

        // Final count: Sum all people in the queue who haven't forgotten the secret
        totalAware = 0;
        while (!q.empty()) {
            totalAware = (totalAware + q.front().second) % mod;
            q.pop();
        }

        return totalAware;
    }
};