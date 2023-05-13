#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(string &s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, inf));

    for (int i = 0; i < n; i++)
        dp[i][0] = 0;

    for (int l = 1; l < n; l++)
    {
        for (int i = 0; i < n - l; i++)
        {
            if (s[i] != s[i + l])
                dp[i][l] = 1 + min(dp[i][l - 1], dp[i + 1][l - 1]);
            else
            {
                if (l == 1)
                    dp[i][l] = 0;
                else
                    dp[i][l] = dp[i + 1][l - 2];
            }
        }
    }
    return dp[0][n - 1];
    ;
}

class Solution
{
public:
    int minInsertions(string s)
    {
        return ans(s);
    }
};