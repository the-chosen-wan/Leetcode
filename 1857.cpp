#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair
#define N 26

int ans(string color, vector<vector<int>> &edges)
{
    int n = color.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
        adj[edges[i][0]].pb(edges[i][1]);

    int dp[N];
    memset(dp, 0, sizeof(dp));
    vector<pii> nodes(n);

    for (int i = 0; i < n; i++)
    {
        nodes[i] = mp(i, color[i] - 'a');
        dp[color[i] - 'a']++;
    }

    vector<int> mindist(n, 0);
    vector<int> visited(n, 0);
    bool cycle = false;
    int maxa = -inf;

    auto dfs = [&](int src, int col, auto &&dfs) -> int
    {
        if (cycle)
            return -1;

        if (visited[src] == 2)
            return mindist[src];
        visited[src] = 1;

        for (int v : adj[src])
        {
            if (visited[v] == 1)
                cycle = true;
            mindist[src] = max(mindist[src], dfs(v, col, dfs));
        }
        mindist[src] = mindist[src] + (nodes[src].second == col);
        visited[src] = 2;
        maxa = max(maxa, mindist[src]);
        return mindist[src];
    };

    for (int i = 0; i < N; i++)
    {
        if (dp[i] == 0)
            continue;
        mindist.assign(n, 0);
        visited.assign(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0)
                dfs(j, i, dfs);
            if (cycle)
                return -1;
        }
    }
    return maxa;
}

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        return ans(colors, edges);
    }
};