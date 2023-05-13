#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &edges)
{
    int n = edges.size();
    int c = 0;
    vector<int> cycle(n, -1);
    vector<int> len(n, 0);
    vector<int> vis(n, 0);

    auto dfs = [&](int src, auto &&dfs) -> int
    {
        c++;
        len[src] = c;
        vis[src] = 1;
        int v = edges[src];
        if (v != -1)
        {
            if (vis[v] == 1)
                cycle[src] = len[src] - len[v] + 1;
            else if (vis[v] == 0)
                cycle[src] = dfs(v, dfs);
        }
        c--;
        vis[src] = 2;
        return cycle[src];
    };
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs(i, dfs);
    }
    return *max_element(cycle.begin(), cycle.end());
}

class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        return ans(edges);
    }
};