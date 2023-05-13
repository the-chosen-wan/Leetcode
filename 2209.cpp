#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(string floor, int num, int len)
{
    int n = floor.size();
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
        nums[i] = floor[i] - '0';

    vector<int> suff(n, 0);
    suff[n - 1] = (nums[n - 1] == 1);
    for (int i = n - 2; i >= 0; i--)
        suff[i] = suff[i + 1] + (nums[i] == 1);
    int dp[n][num + 1];
    memset(dp, -1, sizeof(dp));

    auto dfs = [&](int pos, int j, auto &&dfs) -> int
    {
        if (pos >= n)
            return 0;
        if (j == 0)
        {
            dp[pos][j] = suff[pos];
            return dp[pos][j];
        }
        if (pos == n - 1)
            return 0;

        if (dp[pos][j] != -1)
            return dp[pos][j];
        int maxa = inf;
        maxa = min((nums[pos] == 1) + dfs(pos + 1, j, dfs), dfs(pos + len, j - 1, dfs));
        dp[pos][j] = maxa;
        return dp[pos][j];
    };
    return dfs(0, num, dfs);
}

class Solution
{
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen)
    {
        return ans(floor, numCarpets, carpetLen);
    }
};