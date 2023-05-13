#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

ll ans(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<ll> dp(n);
    dp[n - 1] = nums[n - 1][0];

    for (int i = n - 2; i >= 0; i--)
    {
        if (i + nums[i][1] + 1 < n)
            dp[i] = max(nums[i][0] + dp[i + nums[i][1] + 1], dp[i + 1]);
        else
            dp[i] = max((ll)nums[i][0], dp[i + 1]);
    }
    return dp[0];
}

class Solution
{
public:
    long long mostPoints(vector<vector<int>> &questions)
    {
        return ans(questions);
    }
};