#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

bool ans(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int dp[n][m][n + m + 1];
    memset(dp, -1, sizeof(dp));

    auto dfs = [&](int i, int j, int k, auto &&dfs) -> int
    {
        if (k < 0 || i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        if (i == 0 && j == 0)
        {
            if (grid[0][0] == '(' && k == 1)
            {
                dp[0][0][k] = 1;
                return 1;
            }
            dp[0][0][k] = 0;
            return 0;
        }

        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        if (grid[i][j] == '(')
        {
            dp[i][j][k] = (dfs(i - 1, j, k - 1, dfs) | dfs(i, j - 1, k - 1, dfs));
        }
        else
        {
            dp[i][j][k] = (dfs(i - 1, j, k + 1, dfs) | dfs(i, j - 1, k + 1, dfs));
        }
        return dp[i][j][k];
    };
    dfs(n - 1, m - 1, 0, dfs);
    if (dp[n - 1][m - 1][0] == 1)
        return true;
    return false;
}

class Solution
{
public:
    bool hasValidPath(vector<vector<char>> &grid)
    {
        return ans(grid);
    }
};