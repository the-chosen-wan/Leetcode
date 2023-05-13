#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int l)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(l + 1, -inf));

    auto dfs = [&](int pos, int k, auto &&dfs) -> int
    {
        if (k == 0 && pos < n)
        {
            dp[pos][k] = 0;
            return 0;
        }
        if (pos >= n)
            return 0;
        if (dp[pos][k] != -inf)
            return dp[pos][k];

        int maxa = -inf;
        for (int i = pos + 1; i < n; i++)
            maxa = max(maxa, nums[i] - nums[pos] + dfs(i + 1, k - 1, dfs));
        maxa = max(maxa, dfs(pos + 1, k, dfs));
        dp[pos][k] = max(0, maxa);
        return dp[pos][k];
    };
    return dfs(0, l, dfs);
}

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        return ans(prices, k);
    }
};