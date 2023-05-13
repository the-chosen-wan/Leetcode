#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define bit 31
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &cost)
{
    int s1 = cost.size();
    int s2 = cost[0].size();

    vector<vector<int>> dp(1 << s2, vector<int>(s1, -1));

    auto dfs = [&](int mask, int pos, auto &&dfs) -> int
    {
        if (mask == 0 && pos < 0)
            return 0;
        if (pos < 0)
            return inf;
        if (dp[mask][pos] != -1)
            return dp[mask][pos];

        int ret = inf;
        for (int i = 0; i < s2; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                ret = min(ret, cost[pos][i] + dfs(mask ^ (1 << i), pos, dfs));
                ret = min(ret, cost[pos][i] + dfs(mask ^ (1 << i), pos - 1, dfs));
            }
            else
            {
                ret = min(ret, cost[pos][i] + dfs(mask, pos - 1, dfs));
            }
        }

        dp[mask][pos] = ret;
        return ret;
    };
    return dfs((1 << s2) - 1, s1 - 1, dfs);
}

class Solution
{
public:
    int connectTwoGroups(vector<vector<int>> &cost)
    {
        return ans(cost);
    }
};