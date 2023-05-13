#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pref(n, 0);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + nums[i];

    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[n - 1][0] = 0;
    dp[n - 1][1] = 0;

    int val0 = pref[n - 1];
    int val1 = pref[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        dp[i][0] = val1;
        dp[i][1] = val0;

        val1 = max(val1, pref[i] - dp[i][1]);
        val0 = max(val0, pref[i] - dp[i][0]);
    }

    return dp[0][0];
}

class Solution
{
public:
    int stoneGameVIII(vector<int> &stones)
    {
        return ans(stones);
    }
};