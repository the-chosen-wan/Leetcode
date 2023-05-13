#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N 41

int ans(vector<vector<int>> &hats)
{
    int n = hats.size();
    vector<unordered_set<int>> s(n);
    for (int i = 0; i < n; i++)
    {
        int m = hats[i].size();
        for (int j = 0; j < m; j++)
            s[i].insert(hats[i][j]);
    }

    vector<vector<ll>> dp(1 << n, vector<ll>(N, -1));

    auto dfs = [&](int mask, int ind, auto &&dfs) -> ll
    {
        if (dp[mask][ind] != -1)
            return dp[mask][ind];
        if (mask == 0)
        {
            dp[mask][ind] = 1;
            return 1;
        }
        if (ind < 1)
            return 0;
        ll ret = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0 && s[i].find(ind) != s[i].end())
                ret = (ret + dfs(mask ^ (1 << i), ind - 1, dfs)) % inf;
        }
        ret = (ret + dfs(mask, ind - 1, dfs)) % inf;
        dp[mask][ind] = ret;
        return ret;
    };
    return dfs((1 << n) - 1, N - 1, dfs);
}

class Solution
{
public:
    int numberWays(vector<vector<int>> &hats)
    {
        return ans(hats);
    }
};