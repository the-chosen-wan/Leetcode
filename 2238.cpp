#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return res;
}

ll inv(ll a)
{
    return binpow(a, inf - 2);
}

int recurse(int pos, int path, vector<vector<int>> &dp, vector<vector<int>> &adj)
{
    if (dp[pos][path] != -1)
        return dp[pos][path];
    if (path == 1)
    {
        dp[pos][path] = 1;
        return dp[pos][path];
    }

    int ret = 0;
    for (int v : adj[pos])
        ret += recurse(v, path - 1, dp, adj);
    dp[pos][path] = ret;
    return ret;
}

ll val(int n, int k, vector<ll> &fact)
{
    if (k <= 0)
        return 0;
    if (k > n)
        return 0;

    ll ans = (((fact[n - 1] * inv(fact[k - 1])) % inf) * inv(fact[n - k])) % inf;
    return ans;
}

ll ans(int n, int maxa)
{
    vector<vector<int>> adj(maxa + 1);

    for (int i = 1; i <= maxa; i++)
    {
        for (int j = 2 * i; j <= maxa; j += i)
            adj[i].pb(j);
    }

    vector<vector<int>> numpath(maxa + 1, vector<int>(15, -1));
    for (int i = 1; i <= maxa; i++)
        for (int j = 1; j < 15; j++)
            recurse(i, j, numpath, adj);

    vector<ll> fact(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++)
        fact[i] = (fact[i - 1] * i) % inf;

    ll ans = 0;
    for (int i = 1; i <= maxa; i++)
        for (int j = 1; j < 15; j++)
            ans = (ans + numpath[i][j] * val(n, j, fact)) % inf;
    return ans;
}

class Solution
{
public:
    int idealArrays(int n, int maxValue)
    {
        return ans(n, maxValue);
    }
};