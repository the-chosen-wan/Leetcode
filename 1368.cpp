#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (ll)((1e9) + 7)
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<pii>> adj(n * m);

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
                adj[val].pb(mp(val1, grid[i][j] != 4));
            if (i < n - 1)
                adj[val].pb(mp(val3, grid[i][j] != 3));
            if (j > 0)
                adj[val].pb(mp(val2, grid[i][j] != 2));
            if (j < m - 1)
                adj[val].pb(mp(val4, grid[i][j] != 1));
        }
    }
    deque<int> dq;
    vector<int> mindist(n * m, inf);
    mindist[0] = 0;
    dq.pb(0);
    while (!dq.empty())
    {
        int front = dq.front();
        dq.pop_front();
        for (pii v : adj[front])
        {
            if (mindist[v.first] > mindist[front] + v.second)
            {
                mindist[v.first] = mindist[front] + v.second;
                if (v.second == 0)
                    dq.push_front(v.first);
                else
                    dq.pb(v.first);
            }
        }
    }
    return mindist[n * m - 1];
}

class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        return ans(grid);
    }
};