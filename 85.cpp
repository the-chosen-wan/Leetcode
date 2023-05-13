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
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < m; i++)
        if (grid[0][i] == 1)
            dp[0][i] = 1;

    for (int i = 1; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                dp[i][j] = dp[i - 1][j] + 1;

    int ans = -inf;
    for (int i = 0; i < n; i++)
    {
        stack<pii> s;
        vector<int> declen(m, 1);
        for (int j = 0; j < m; j++)
        {
            if (s.empty())
            {
                s.push(mp(dp[i][j], j));
            }
            else
            {
                pii top = s.top();
                if (top.first < dp[i][j])
                {
                    s.push(mp(dp[i][j], j));
                    continue;
                }

                while (top.first >= dp[i][j])
                {
                    s.pop();
                    if (s.empty())
                        break;
                    top = s.top();
                }

                if (s.empty())
                    declen[j] = j + 1;
                else
                    declen[j] = j - s.top().second;
                s.push(mp(dp[i][j], j));
            }
        }

        while (!s.empty())
            s.pop();
        vector<int> inclen(m, 1);
        for (int j = m - 1; j >= 0; j--)
        {
            if (s.empty())
            {
                s.push(mp(dp[i][j], j));
            }
            else
            {
                pii top = s.top();
                if (top.first < dp[i][j])
                {
                    s.push(mp(dp[i][j], j));
                    continue;
                }

                while (top.first >= dp[i][j])
                {
                    s.pop();
                    if (s.empty())
                        break;
                    top = s.top();
                }

                if (s.empty())
                    inclen[j] = m - j;
                else
                    inclen[j] = s.top().second - j;
                s.push(mp(dp[i][j], j));
            }
        }
        for (int j = 0; j < m; j++)
            ans = max(ans, (inclen[j] + declen[j] - 1) * dp[i][j]);
    }
    return ans;
}

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = matrix[i][j] - '0';
        return ans(grid);
    }
};