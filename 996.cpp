#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 2e9;
#define pb push_back
#define mp make_pair
#pragma GCC optimize("Ofast")

int ans(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<ll> s;
    ll c = 0;
    while (c * c <= inf)
    {
        s.insert(c * c);
        c++;
    }

    vector<int> fact(13, 0);
    fact[0] = 1;
    for (int i = 1; i <= 12; i++)
        fact[i] = fact[i - 1] * i;

    unordered_map<int, int> mappa;
    for (int i = 0; i < n; i++)
        mappa[nums[i]]++;

    vector<vector<int>> dp((1 << n), vector<int>(n + 1, -1));

    auto dfs = [&](int mask, int ind, auto &&dfs) -> int
    {
        if (mask == 0)
        {
            dp[mask][ind] = 1;
            return 1;
        }

        if (dp[mask][ind] != -1)
            return dp[mask][ind];

        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            if (ind == n)
            {
                if ((mask & (1 << i)) != 0)
                    ret = ret + dfs(mask ^ (1 << i), i, dfs);
            }
            else
            {
                if (((mask & (1 << i)) != 0) && (s.find(nums[i] + nums[ind]) != s.end()))
                    ret = ret + dfs(mask ^ (1 << i), i, dfs);
            }
        }
        dp[mask][ind] = ret;
        return ret;
    };
    int ans = dfs((1 << n) - 1, n, dfs);
    for (pii e : mappa)
        ans /= fact[e.second];
    return ans;
}

class Solution
{
public:
    int numSquarefulPerms(vector<int> &nums)
    {
        return ans(nums);
    }
};