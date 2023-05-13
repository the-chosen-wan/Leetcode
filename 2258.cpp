#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool check(int src, int target, int time, vector<int> &vis, vector<int> &timer, vector<vector<int>> &adj)
{
    vis[src] = 0;
    queue<int> q;
    q.push(src);
    if (vis[src] + time >= timer[src])
        return false;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int v : adj[front])
        {
            if (vis[v] == inf && (vis[front] + 1 + time) < timer[v])
            {
                vis[v] = vis[front] + 1;
                q.push(v);
            }
            else if (v == target && vis[v] == inf && (vis[front] + 1 + time == timer[v]))
                return true;
        }
    }
    return vis[target] != inf;
}

int ans(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> adj(n * m + 1);
    vector<int> time(n * m + 1, inf + 50000);
    time[n * m] = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 2)
            {
                int val = i * m + j;
                if (grid[i][j] == 1)
                    adj[n * m].pb(val);
                int val2 = (i + 1) * m + j;
                int val3 = i * m + j + 1;
                if (i < n - 1 && grid[i + 1][j] < 2)
                {
                    adj[val].pb(val2);
                    adj[val2].pb(val);
                }
                if (j < m - 1 && grid[i][j + 1] < 2)
                {
                    adj[val].pb(val3);
                    adj[val3].pb(val);
                }
            }
        }
    }

    queue<int> q;
    q.push(n * m);
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int v : adj[front])
        {
            if (time[v] == inf + 50000)
            {
                time[v] = time[front] + 1;
                q.push(v);
            }
        }
    }

    int high = inf;
    int low = 0;
    vector<int> vis(n * m + 1, inf);
    while (high >= low)
    {
        vis.assign(n * m + 1, inf);
        int mid = (high + low) / 2;
        if (mid == low)
        {
            if (check(0, n * m - 1, high, vis, time, adj))
                return high;
            else if (check(0, n * m - 1, low, vis, time, adj))
                return low;
            break;
        }

        if (check(0, n * m - 1, mid, vis, time, adj))
            low = mid;
        else
            high = mid - 1;
    }
    vis.assign(n * m + 1, inf);
    if (check(0, n * m - 1, 0, vis, time, adj))
        return 0;
    return -1;
}

class Solution
{
public:
    int maximumMinutes(vector<vector<int>> &grid)
    {
        return ans(grid);
    }
};