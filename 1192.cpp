#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

void dfs(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &tin, vector<int> &low, vector<vector<int>> &s, int &timer, int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(adj, visited, tin, low, s, timer, to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                s.pb({to, v});
        }
    }
}

vector<vector<int>> ans(int N, vector<vector<int>> &edg)
{
    vector<vector<int>> adj(N);
    vector<pii> edges;
    for (int i = 0; i < edg.size(); i++)
    {
        adj[edg[i][0]].pb(edg[i][1]);
        adj[edg[i][1]].pb(edg[i][0]);
        edges.pb(mp(edg[i][0], edg[i][1]));
    }
    vector<bool> visited(N, false);
    vector<int> tin(N, -1);
    vector<int> low(N, -1);
    int timer = 0;
    vector<vector<int>> s;
    dfs(adj, visited, tin, low, s, timer, 0);
    return s;
}

class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        return ans(n, connections);
    }
};
