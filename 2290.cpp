#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int count(vector<vector<int>> &grid)
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
                adj[val1].pb(mp(grid[i - 1][j], val2));
            if (j - 1 >= 0)
                adj[val1].pb(mp(grid[i][j - 1], val4));
            if (i + 1 < n)
                adj[val1].pb(mp(grid[i + 1][j], val3));
            if (j + 1 < m)
                adj[val1].pb(mp(grid[i][j + 1], val5));
        }
    }

    vector<int> d(n * m, inf);
    d[0] = 0;
    deque<int> q;
    q.push_front(0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (pii edge : adj[v])
        {
            int to = edge.second;
            int w = edge.first;
            if (d[to] > d[v] + w)
            {
                d[to] = d[v] + w;
                if (w == 1)
                    q.push_back(to);
                else
                    q.push_front(to);
            }
        }
    }
    return d[n * m - 1];
}

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        return count(grid);
    }
};