#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return res;
}

ll inverse(ll a)
{
    return binpow(a, inf - 2);
}

int ans(int n, int mini, vector<int> &group, vector<int> &profit)
{
    int m = group.size();
    vector<pii> nums;
    for (int i = 0; i < m; i++)
        nums.pb(mp(group[i], profit[i]));

    ll dp[m][n + 1][mini + 1];

    int g = nums[0].first;
    int p = nums[0].second;

    for (int j = 0; j <= n; j++)
    {
        for (int k = 0; k <= mini; k++)
        {
            if (k == 0)
            {
                if (j >= g)
                    dp[0][j][k] = 2;
                else
                    dp[0][j][k] = 1;
            }
            else
            {
                if (j >= g)
                {
                    if (k <= p)
                        dp[0][j][k] = 1;
                    else
                        dp[0][j][k] = 0;
                }
                else
                    dp[0][j][k] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        int gval = nums[i].first;
        int pval = nums[i].second;
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= mini; k++)
            {
                if (j >= gval)
                    dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - gval][max(0, k - pval)]) % inf;
                else
                    dp[i][j][k] = dp[i - 1][j][k];
            }
        }
    }
    return dp[m - 1][n][mini];
}

class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        return ans(n, minProfit, group, profit);
    }
};