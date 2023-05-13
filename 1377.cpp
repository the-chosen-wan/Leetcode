#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using pii = pair<int, int>;
#define inf (ll)((1e9) + 7)
#define pb push_back
#define mp make_pair

double ans(int n, vector<vector<int>> &edges, int t, int target)
{
    target--;
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    vector<bool> isleaf(n, true);
    for (int i = 0; i < edges.size(); i++)
    {
        edges[i][0]--;
        edges[i][1]--;
        adj[edges[i][0]].pb(edges[i][1]);
        adj[edges[i][1]].pb(edges[i][0]);
        deg[edges[i][0]]++;
        deg[edges[i][1]]++;
    }

    for (int i = 1; i < n; i++)
        deg[i]--;

    vector<pair<int, double>> nodes(n);

    auto dfs = [&](int parent, int src, int height, double prob, auto &&dfs) -> void
    {
        nodes[src].first = height;
        nodes[src].second = prob;

        for (int v : adj[src])
        {
            if (v != parent)
            {
                isleaf[src] = false;
                dfs(src, v, height + 1, prob / deg[src], dfs);
            }
        }
        return;
    };

    dfs(0, 0, 0, 1, dfs);
    if ((nodes[target].first == t && !isleaf[target]) || (nodes[target].first <= t && isleaf[target]))
        return nodes[target].second;
    return 0;
}

class Solution
{
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        return ans(n, edges, t, target);
    }
};