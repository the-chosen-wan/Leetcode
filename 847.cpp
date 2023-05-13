#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, inf));

    for (int i = 0; i < n; i++)
    {
        queue<int> q;
        dist[i][i] = 0;
        q.push(i);
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (int v : graph[front])
            {
                if (dist[i][v] == inf)
                {
                    q.push(v);
                    dist[i][v] = dist[i][front] + 1;
                }
            }
        }
    }

    int dp[1 << n][n];
    memset(dp, -1, sizeof(dp));

    auto dfs = [&](int mask, int src, auto &&dfs) -> int
    {
        if (mask == 0)
            return 0;
        if (dp[mask][src] != -1)
            return dp[mask][src];

        int ret = inf;
        for (int i = 0; i < n; i++)
        {
            if ((i != src) && ((mask & (1 << i)) != 0))
                ret = min(ret, dist[src][i] + dfs(mask ^ (1 << i), i, dfs));
        }
        dp[mask][src] = ret;
        return ret;
    };

    int maxa = inf;
    for (int i = 0; i < n; i++)
    {
        maxa = min(maxa, dfs((1 << n) - 1 - (1 << i), i, dfs));
        memset(dp, -1, sizeof(dp));
    }
    return maxa;
}

class Solution
{
public:
    int shortestPathLength(vector<vector<int>> &graph)
    {
        return ans(graph);
    }
};