#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(int m, int n, int moves, int x, int y)
{
    int dp[m][n][moves + 1];
    memset(dp, -1, sizeof(dp));

    auto dfs = [&](int i, int j, int k, auto &&dfs) -> int
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return 1;
        }
        if (k == 0)
        {
            dp[i][j][k] = 0;
            return 0;
        }
        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int ret = 0;
        ret = (ret + dfs(i - 1, j, k - 1, dfs)) % inf;
        ret = (ret + dfs(i, j - 1, k - 1, dfs)) % inf;
        ret = (ret + dfs(i + 1, j, k - 1, dfs)) % inf;
        ret = (ret + dfs(i, j + 1, k - 1, dfs)) % inf;

        dp[i][j][k] = ret;
        return ret;
    };
    return dfs(x, y, moves, dfs);
}

class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        return ans(m, n, maxMove, startRow, startColumn);
    }
};