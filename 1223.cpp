#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (int)((1e9) + 7)
#define N 6
#define pb push_back
#define mp make_pair

int nums(int n, vector<int> &roll)
{
    vector<vector<int>> dp(n + 1, vector<int>(N, 0));
    vector<vector<int>> pref(n + 1, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        dp[1][i] = 1;
        pref[1][i] = 5;
    }

    for (int i = 0; i < N; i++)
        pref[0][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            for (int k = 1; k <= roll[j]; k++)
            {
                if (i - k >= 0)
                    dp[i][j] = (dp[i][j] + pref[i - k][j]) % inf;
            }
            sum = (sum + dp[i][j]) % inf;
        }

        for (int j = 0; j < N; j++)
            pref[i][j] = (sum - dp[i][j]) % inf;
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = (ans + dp[n][i]) % inf;
    if (ans < 0)
        ans += inf;
    return ans;
}

class Solution
{
public:
    int dieSimulator(int n, vector<int> &rollMax)
    {
        return nums(n, rollMax);
    }
};