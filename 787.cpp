#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(int n, vector<vector<int>> &flights, int src, int dest, int k)
{
    k++;
    int f = flights.size();
    vector<vector<pii>> adj(n);

    for (vector<int> &e : flights)
    {
        adj[e[0]].pb(mp(e[1], e[2]));
    }

    vector<vector<int>> dp(n, vector<int>(k + 1, inf));
    for (int i = 0; i <= k; i++)
        dp[src][i] = 0;

    for (int j = 0; j <= k - 1; j++)
    {
        for (int i = 0; i < n; i++)
        {
            for (pii &e : adj[i])
                dp[e.first][j + 1] = min(dp[e.first][j + 1], dp[i][j] + e.second);
        }
    }
    if (dp[dest][k] >= inf)
        return -1;
    return dp[dest][k];
}

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        return ans(n, flights, src, dst, k);
    }
};