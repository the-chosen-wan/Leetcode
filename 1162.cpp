#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> adj(n * m + 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val = i * m + j;
            int val1 = (i - 1) * m + j;
            int val2 = i * m + j - 1;
            int val3 = (i + 1) * m + j;
            int val4 = i * m + j + 1;
            if (i > 0)
                adj[val].pb(val1);
            if (i < n - 1)
                adj[val].pb(val3);
            if (j > 0)
                adj[val].pb(val2);
            if (j < m - 1)
                adj[val].pb(val4);
            if (grid[i][j] == 1)
                adj[n * m].pb(val);
        }
    }

    vector<int> dist(n * m + 1, 0);
    vector<bool> visited(n * m + 1, false);
    dist[n * m] = 0;
    visited[n * m] = true;
    queue<int> q;
    q.push(n * m);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int j : adj[front])
        {
            if (!visited[j])
            {
                visited[j] = true;
                dist[j] = dist[front] + 1;
                q.push(j);
            }
        }
    }

    int mini = -inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 0)
                mini = max(mini, dist[i * m + j]);
    if (mini == -inf)
        return -1;
    return --mini;
}

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        return ans(grid);
    }
};