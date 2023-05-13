#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    int n = nums.size();
    nums.pb(1);
    nums.insert(nums.begin(), 1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = 1; i <= n; i++)
        dp[i][0] = nums[i - 1] * nums[i] * nums[i + 1];

    for (int l = 1; l < n; l++)
    {
        for (int i = 1; i <= n - l; i++)
        {
            int maxa = -inf;
            for (int k = i + 1; k < i + l; k++)
                maxa = max(maxa, nums[i - 1] * nums[k] * nums[i + l + 1] + dp[i][k - 1 - i] + dp[k + 1][i + l - k - 1]);
            maxa = max(maxa, nums[i - 1] * nums[i] * nums[i + l + 1] + dp[i + 1][l - 1]);
            maxa = max(maxa, nums[i - 1] * nums[i + l] * nums[i + l + 1] + dp[i][l - 1]);
            dp[i][l] = maxa;
        }
    }

    return dp[1][n - 1];
}

class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        return ans(nums);
    }
};