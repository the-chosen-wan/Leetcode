#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define bit 31
#define pb push_back
#define mp make_pair

int powtwo;
int n;
int timer;
vector<int> in;
vector<int> out;

int gcd(int x, int y)
{
    if(x<y)
        swap(x,y);
    if (y == 0)
        return x;
    return gcd(y, x % y);
}


void dfs(int source, int parent, vector<vector<int>> &adj, vector<bool> &b, vector<vector<int>> &lca, vector<int>& nums)
{
    in[source] = ++timer;
    b[source] = true;
    lca[source][0] = gcd(nums[parent],nums[source]);
    for (int i = 1; i <= powtwo; i++)
        lca[source][i] = gcd(lca[source][i-1],lca[lca[source][i - 1]][i - 1]);
    for (int i : adj[source])
    {
        if (!b[i])
            dfs(i, source, adj, b, lca,nums);
    }
    out[source] = ++timer;
}

int first_gcd(int u,vector<vector<int>> &lca)
{
    for (int i = powtwo; i >= 0; i--)
    {
        if (lca[u][i]==1)
            u = lca[u][i];
    }
    return lca[u][0];
}