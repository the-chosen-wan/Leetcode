#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

int ans(vector<vector<int>> &grid, int k)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(m, vector<ll>(k, -1)));

    auto dfs = [&](int i, int j, int r, auto &&dfs) -> ll
    {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j][r] != -1)
            return dp[i][j][r];

        if (i == 0 && j == 0)
        {
            if (r == (grid[0][0] % k))
                return dp[i][j][r] = 1;
            return dp[i][j][r] = 0;
        }

        ll ret = 0;

        ret = (ret + dfs(i - 1, j, ((r - grid[i][j]) % k + k) % k, dfs)) % inf;
        ret = (ret + dfs(i, j - 1, ((r - grid[i][j]) % k + k) % k, dfs)) % inf;
        dp[i][j][r] = ret;
        return ret;
    };

    return dfs(n - 1, m - 1, 0, dfs);
}

class Solution
{
public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        return ans(grid, k);
    }
};