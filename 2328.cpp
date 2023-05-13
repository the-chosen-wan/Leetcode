#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

ll traverse(vector<vector<int>> &grid, vector<vector<ll>> &dp, vector<vector<bool>> &vis, int x, int y, int n, int m)
{
    if (dp[x][y] != -1)
        return dp[x][y];

    vis[x][y] = true;
    dp[x][y] = 0;

    if (x > 0 && grid[x - 1][y] > grid[x][y])
        dp[x][y] = (dp[x][y] + traverse(grid, dp, vis, x - 1, y, n, m)) % inf;
    if (x < n - 1 && grid[x + 1][y] > grid[x][y])
        dp[x][y] = (dp[x][y] + traverse(grid, dp, vis, x + 1, y, n, m)) % inf;
    if (y > 0 && grid[x][y - 1] > grid[x][y])
        dp[x][y] = (dp[x][y] + traverse(grid, dp, vis, x, y - 1, n, m)) % inf;
    if (y < m - 1 && grid[x][y + 1] > grid[x][y])
        dp[x][y] = (dp[x][y] + traverse(grid, dp, vis, x, y + 1, n, m)) % inf;

    dp[x][y] = (dp[x][y] + 1) % inf;
    return dp[x][y];
}

int ans(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<ll>> dp(n, vector<ll>(m, -1));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (!vis[i][j])
                traverse(grid, dp, vis, i, j, n, m);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = (ans + dp[i][j]) % inf;
    return ans;
}

class Solution
{
public:
    int countPaths(vector<vector<int>> &grid)
    {
        return ans(grid);
    }
};