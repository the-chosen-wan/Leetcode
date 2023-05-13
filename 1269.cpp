#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(int steps, int len)
{
    vector<vector<int>> dp(steps + 1, vector<int>(steps + 1, 0));
    dp[0][0] = 1;

    for (int i = 1; i <= steps; i++)
    {
        for (int j = 0; j <= steps; j++)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % inf;
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % inf;
            if (j < len - 1 && j < steps)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % inf;
        }
    }
    return dp[steps][0];
}

class Solution
{
public:
    int numWays(int steps, int arrLen)
    {
        return ans(steps, arrLen);
    }
};