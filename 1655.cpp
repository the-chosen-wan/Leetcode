#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool ans(vector<int> &nums, vector<int> &quantity)
{
    int m = quantity.size();
    int n = nums.size();
    unordered_map<int, int> mappa;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (mappa.find(nums[i]) == mappa.end())
        {
            mappa[nums[i]] = c;
            c++;
        }
    }

    vector<int> unique(c, 0);
    for (int i = 0; i < n; i++)
        unique[mappa[nums[i]]]++;
    n = c;
    vector<vector<int>> dp(1 << m, vector<int>(n, -1));

    auto dfs = [&](int mask, int ind, auto &&dfs) -> int
    {
        if (mask == 0)
            return 1;
        if (ind < 0)
            return 0;
        if (dp[mask][ind] != -1)
            return dp[mask][ind];
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            if (((mask & (1 << i)) != 0) && (quantity[i] <= unique[ind]))
            {
                unique[ind] -= quantity[i];
                ret = ret | dfs(mask ^ (1 << i), ind, dfs);
                unique[ind] += quantity[i];
            }
        }
        ret = ret | dfs(mask, ind - 1, dfs);
        dp[mask][ind] = ret;
        return ret;
    };
    return dfs((1 << m) - 1, n - 1, dfs) == 1;
}

class Solution
{
public:
    bool canDistribute(vector<int> &nums, vector<int> &quantity)
    {
        return ans(nums, quantity);
    }
};