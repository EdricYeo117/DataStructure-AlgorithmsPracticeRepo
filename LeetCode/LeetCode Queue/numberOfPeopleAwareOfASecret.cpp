/*
On day 1, one person discovers a secret.

You are given an integer delay, which means that each person will share the secret with a new person every day,
    starting from delay days after discovering the secret. You are also given an integer forget,
    which means that each person will forget the secret forget days after discovering it.
A person cannot share the secret on the same day they forgot it, or on any day afterwards.

Given an integer n, return the number of people who know the secret at the end of day n.
Since the answer may be very large, return it modulo 109 + 7.
*/

#include <iostream>
#include <queue>
using namespace std;

int peopleAwareOfSecret(int n, int delay, int forget) {
    const int M = 1e9 + 7;
    int curr = 0;
    int ans = 1;
    queue<pair<int,int>> delayQ, forgetQ;
    delayQ.push({1,1});
    forgetQ.push({1,1});
    for (int i = 1; i <= n; i++) {
        if (!forgetQ.empty() && forgetQ.front().first + forget <= i) {
            auto front = forgetQ.front();
            forgetQ.pop();
            auto no = front.second;
            ans = (ans - no + M) % M;
            curr = (curr - no + M) % M;
        }
        if (!delayQ.empty() && delayQ.front().first + delay <= i) {
            auto front = delayQ.front();
            delayQ.pop();
            curr = (curr + front.second) % M;
        }
        if (curr > 0) {
            ans = (ans + curr) % M;
            delayQ.push({i, curr});
            forgetQ.push({i, curr});
        }
    }
    return ans;
};