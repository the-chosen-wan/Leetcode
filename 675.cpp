#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int mindist(int src, int target, vector<int> &dist, vector<vector<int>> &adj)
{
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int v : adj[f])
        {
            if (dist[v] == inf)
            {
                dist[v] = dist[f] + 1;
                q.push(v);
            }
            if (v == target)
                return dist[v];
        }
    }
    return inf;
}

int ans(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> adj(n * m);
    vector<pii> pos;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val1 = i * m + j;
            int val2 = (i + 1) * m + j;
            int val3 = i * m + j + 1;
            if (grid[i][j] != 0)
            {
                if (grid[i][j] > 1)
                    pos.pb(mp(grid[i][j], val1));
                if (i < n - 1 && grid[i + 1][j] > 0)
                {
                    adj[val1].pb(val2);
                    adj[val2].pb(val1);
                }
                if (j < m - 1 && grid[i][j + 1] > 0)
                {
                    adj[val1].pb(val3);
                    adj[val3].pb(val1);
                }
            }
        }
    }
    vector<int> dist(n * m, inf);
    sort(pos.begin(), pos.end());
    int sum = mindist(0, pos[0].second, dist, adj);
    if (sum == inf)
        return -1;
    int s = pos.size();
    for (int i = 1; i < s; i++)
    {
        dist.assign(n * m, inf);
        sum += mindist(pos[i - 1].second, pos[i].second, dist, adj);
        if (sum >= inf)
            return -1;
    }
    return sum;
}

class Solution
{
public:
    int cutOffTree(vector<vector<int>> &forest)
    {
        return ans(forest);
    }
};
