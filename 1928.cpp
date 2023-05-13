#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int time(int maxtime, vector<vector<int>> &edges, vector<int> &passing)
{
    int n = passing.size();
    int m = edges.size();

    vector<vector<pii>> inc(n);
    for (int i = 0; i < m; i++)
    {
        int from = edges[i][0];
        int to = edges[i][1];
        int w = edges[i][2];
        inc[to].pb(mp(w, from));
        inc[from].pb(mp(w,to));
    }

    vector<vector<int>> dp;
    dp.resize(n, vector<int>(maxtime + 1, inf));

    for (int i = 0; i <= maxtime; i++)
        dp[0][i] = passing[0];

    for (int i = 0; i <= maxtime; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int mini = inf;
            for (pii from : inc[j])
            {
                if (i - from.first >= 0)
                    mini = min(mini, dp[from.second][i - from.first] + passing[j]);
            }
            dp[j][i] = mini;
        }
    }
    if (dp[n - 1][maxtime] == inf)
        return -1;
    return dp[n - 1][maxtime];
}

class Solution
{
public:
    int minCost(int maxTime, vector<vector<int>> &edges, vector<int> &passingFees)
    {
        return time(maxTime, edges, passingFees);
    }
};