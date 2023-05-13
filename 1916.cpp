#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define MAX 100001

ll fact[MAX];
ll inv_fact[MAX];

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

void dfs(int par, int src, vector<vector<int>> &adj, vector<int> &sz, vector<int> &result)
{

    ll ans = 1;
    for (int v : adj[src])
    {
        if (v != par)
        {
            dfs(src, v, adj, sz, result);
            ans = (ans * result[v]) % inf;
            ans = (ans * inv_fact[sz[v]]) % inf;
            sz[src] += sz[v];
        }
    }
    ans = (ans * fact[sz[src]]) % inf;
    sz[src]++;
    result[src] = ans;
    return;
}

int ret(vector<int> &parent)
{
    int n = parent.size();
    vector<vector<int>> adj(n);

    fact[0] = 1;
    for (int i = 1; i < MAX; i++)
        fact[i] = (i * fact[i - 1]) % inf;

    inv_fact[MAX - 1] = inverse(fact[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--)
        inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % inf;

    for (int i = 1; i < n; i++)
    {
        adj[parent[i]].pb(i);
        adj[i].pb(parent[i]);
    }

    vector<int> result(n, 1);
    vector<int> sz(n, 0);
    dfs(0, 0, adj, sz, result);
    return result[0];
}

class Solution
{
public:
    int waysToBuildRooms(vector<int> &prevRoom)
    {
        return ret(prevRoom);
    }
};
