#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define pb push_back
const int inf = (int)1e9;

int ans(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    if (n == 1)
        return dp[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++)
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);

    vector<int> dp1(n, 0);
    dp1[n - 1] = nums[n - 1];
    dp1[n - 2] = max(nums[n - 2], dp1[n - 1]);
    for (int i = n - 3; i >= 0; i--)
        dp1[i] = max(nums[i] + dp1[i + 2], dp1[i + 1]);
    return max(dp[n - 2], dp1[1]);
}

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        return ans(nums);
    }
};