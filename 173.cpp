#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define pb push_back
const int inf = (int)1e9;

bool check(int n, vector<vector<int>> &dungeon)
{
    int len = dungeon.size();
    int len1 = dungeon[0].size();
    vector<vector<int>> dp(len, vector<int>(len, 0));

    dp[0][0] = max(n + dungeon[0][0], 0);

    for (int i = 1; i < len; i++)
        dp[i][0] = dp[i - 1][0] == 0 ? 0: max(dp[i - 1][0] + dungeon[i][0], 0);
    
    for(int i=1;i<len1;i++)
        dp[0][i] = dp[0][i - 1] == 0 ? 0 : max(dp[0][i - 1] + dungeon[0][i], 0);

    for (int i = 1; i < len; i++)
    {
        for (int j = 1; j < len1; j++)
        {
            int maxa = max(dp[i - 1][j], dp[i][j - 1]);
            dp[i][j] = maxa == 0 ? 0 : max(maxa + dungeon[i][j], 0);
        }
    }
    return dp[len - 1][len1 - 1] != 0;
}

int minimum(vector<vector<int>> &dungeon)
{
    int high = inf;
    int low = 1;

    while (high >= low)
    {
        int mid = low + (high - low) / 2;
        if (mid == low)
        {
            if (check(low, dungeon))
                return low;
            return high;
        }
        bool chk = check(mid, dungeon);
        if (chk)
            high = mid;
        else
            low = mid + 1;
    }
    return -1;
}

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        return minimum(dungeon);
    }
};