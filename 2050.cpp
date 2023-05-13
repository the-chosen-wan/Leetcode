#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int dfs(int src, vector<vector<int>> &adj, vector<int> &complete, vector<int> &time)
{
    if (complete[src] != -1)
        return complete[src];

    complete[src] = time[src - 1];
    int temp = 0;

    for (int k : adj[src])
        temp = max(temp, dfs(k, adj, complete, time));
    complete[src] += temp;
    return complete[src];
}

int minnum(int n, vector<vector<int>> &edges, vector<int> &time)
{
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < edges.size(); i++)
        adj[edges[i][1]].pb(edges[i][0]);

    vector<int> complete(n + 1, -1);

    int ans = -inf;
    for (int i = 1; i <= n; i++)
    {
        if (complete[i] == -1)
            dfs(i, adj, complete, time);
        ans = max(ans, complete[i]);
    }
    return ans;
}

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        return minnum(n, relations, time);
    }
};