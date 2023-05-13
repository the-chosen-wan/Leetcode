#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &grid, int target)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
        dp[i][0] = grid[i][0] + dp[i - 1][0];
    for (int i = 1; i < m; i++)
        dp[0][i] = grid[0][i] + dp[0][i - 1];

    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] = grid[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];

    auto sum = [&](int p, int q, int r, int s) -> int
    {
        int s1 = 0;
        int s2 = 0;
        if (p != 0)
            s1 += dp[p - 1][s];
        if (q != 0)
            s1 += dp[r][q - 1];
        if (p != 0 && q != 0)
            s2 += dp[p - 1][q - 1];
        return dp[r][s] - s1 + s2;
    };
    unordered_map<int, int> mappa;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            mappa.clear();
            for (int k = 0; k < m; k++)
            {
                int val = sum(i, 0, j, k);
                if (mappa.find(val - target) != mappa.end())
                    ans += mappa[val - target];
                if (val == target)
                    ans++;
                mappa[val]++;
            }
        }
    }
    return ans;
}

class Solution
{
public:
    int numSubmatrixSumTarget(vector<vector<int>> &matrix, int target)
    {
        return ans(matrix, target);
    }
};