#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(int n, int k)
{
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= min(i, k); j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + (i - 1) * dp[i - 1][j]) % inf;
        }
    }
    return dp[n][k];
}

class Solution
{
public:
    int rearrangeSticks(int n, int k)
    {
        return ans(n, k);
    }
};