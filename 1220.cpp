#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(int n)
{
    vector<vector<int>> adj(5);
    adj[0].pb(1);
    adj[1].pb(0);
    adj[1].pb(2);
    adj[2] = {0, 1, 3, 4};
    adj[3] = {2, 4};
    adj[4] = {0};

    ll total = 0;
    ll dp[n][5];

    auto dfs = [&](int pos, int ind, auto &&dfs) -> ll
    {
        if (pos == 0)
        {
            dp[pos][ind] = 1;
            return 1;
        }

        if (dp[pos][ind] != -1)
            return dp[pos][ind];

        ll ret = 0;
        for (int v : adj[ind])
        {
            ret = (ret + dfs(pos - 1, v, dfs)) % inf;
        }
        dp[pos][ind] = ret;
        return ret;
    };
    for (int i = 0; i < 5; i++)
    {
        memset(dp, -1, sizeof(dp));
        dfs(n - 1, i, dfs);
        total = (total + dp[n - 1][i]) % inf;
    }
    return (int)total;
}

class Solution
{
public:
    int countVowelPermutation(int n)
    {
        return ans(n);
    }
};