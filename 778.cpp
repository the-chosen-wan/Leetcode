#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool check(int t, vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<pii>> adj(n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int val1 = i * m + j;
            int val2 = (i - 1) * m + j;
            int val3 = (i + 1) * m + j;
            int val4 = i * m + j - 1;
            int val5 = i * m + j + 1;
            if (i - 1 >= 0)
                if (max(grid[i - 1][j], grid[i][j]) <= t)
                    adj[val1].pb(mp(0, val2));
            if (j - 1 >= 0)
                if (max(grid[i][j - 1], grid[i][j]) <= t)
                    adj[val1].pb(mp(0, val4));
            if (i + 1 < n)
                if (max(grid[i + 1][j], grid[i][j]) <= t)
                    adj[val1].pb(mp(0, val3));
            if (j + 1 < m)
                if (max(grid[i][j + 1], grid[i][j]) <= t)
                    adj[val1].pb(mp(0, val5));
        }
    }

    vector<bool> visited(n * m, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (pii k : adj[front])
            if (!visited[k.second])
            {
                q.push(k.second);
                visited[k.second] = true;
            }
    }
    return visited[n * m - 1];
}

int count(vector<vector<int>> &grid)
{
    int high = 1e9;
    int low = 0;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (mid == low)
        {
            if (check(low, grid))
                return low;
            return high;
        }
        bool chk = check(mid, grid);
        if (chk)
            high = mid;
        else
            low = mid + 1;
    }
    return -1;
}

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        return count(grid);
    }
};