#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

long long binpow(long long a, long long b)
{
    long long res = 1;
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

int ans(int n, int m, int k)
{
    ll dp[n + 1][m + 1][k + 1];
    memset(dp, -1, sizeof(dp));

    auto dfs = [&](int p, int q, int r, auto &&dfs) -> ll
    {
        if (p == 0 || q == 0 || r == 0)
            return 0;
        if (dp[p][q][r] != -1)
            return dp[p][q][r];
        if (r == 1 && p == 1)
        {
            dp[p][q][r] = q;
            return q;
        }
        if (r == 1)
        {
            ll ret = dfs(p, q - 1, r, dfs);
            ret = (ret + dfs(p - 1, q, r, dfs)) % inf;
            dp[p][q][r] = ret;
            return ret;
        }

        ll ret = dfs(p, q - 1, r, dfs);
        for (int ind = 1; ind <= p; ind++)
        {
            ret = (ret + (dfs(ind - 1, q - 1, r - 1, dfs) * binpow(q, p - ind)) % inf) % inf;
        }
        dp[p][q][r] = ret;
        return ret;
    };
    return dfs(n, m, k, dfs);
}

class Solution
{
public:
    int numOfArrays(int n, int m, int k)
    {
        return ans(n, m, k);
    }
};