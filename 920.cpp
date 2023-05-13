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

ll inverse(ll a)
{
    return binpow(a, inf - 2);
}

ll nck(int n, int k, vector<ll> &fact, vector<ll> &inv_fact)
{
    if (n == 0 && k == 0)
        return 0;
    if (k > n)
        return 0;
    return (fact[n] * (inv_fact[k] * inv_fact[n - k]) % inf) % inf;
}

ll ans(int n, int goal, int k)
{
    vector<vector<ll>> dp(goal + 1, vector<ll>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= goal; ++i)
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] += dp[i - 1][j - 1] * (n - j + 1);
            dp[i][j] += dp[i - 1][j] * max(j - k, 0);
            dp[i][j] %= inf;
        }

    return (int)dp[goal][n];
}

class Solution
{
public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        return ans(n, goal, k);
    }
};