#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int abs(int a)
{
    return a >= 0 ? a : -a;
}
int count(vector<int> &loc, int start, int finish, int fuel)
{
    int n = loc.size();
    vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));
    for (int i = 0; i <= fuel; i++)
        dp[start][i] = 1;

    for (int i = 0; i <= fuel; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k != j)
                    dp[j][i] = (dp[j][i] + (i - abs(loc[j] - loc[k]) >= 0 ? dp[k][i - abs(loc[j] - loc[k])] : 0)) % inf;
            }
        }
    }
    return dp[finish][fuel];
}

class Solution
{
public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        return count(locations, start, finish, fuel);
    }
};