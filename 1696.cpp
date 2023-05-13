#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[n - 1] = nums[n - 1];
    deque<pii> dq;
    dq.pb(mp(n - 1, nums[n - 1]));

    for (int i = n - 2; i >= 0; i--)
    {
        if (dq.front().first == i + k + 1)
            dq.pop_front();
        dp[i] = nums[i] + dq.front().second;
        while (!dq.empty() && dq.back().second <= dp[i])
            dq.pop_back();
        dq.push_back(mp(i, dp[i]));
    }
    return dp[0];
}

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};