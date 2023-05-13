#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool traverse(int mask, int sum, int &maxsum, int &maxbit, vector<int> &dp)
{
    if(sum>=maxsum)
        return false;

    if (dp[mask] != -1)
        return dp[mask];

    bool ret = true;
    for (int i = 0; i < maxbit; i++)
    {
        if (!(mask & (1 << i)))
            ret = ret & traverse(mask | (1 << i), sum + i + 1, maxsum, maxbit, dp);
    }
    ret = !ret;
    dp[mask] = (int)ret;
    return ret;
}

bool ans(int choosable, int maxreq)
{
    int N = 1 << choosable;
    vector<int> dp(N, -1);
    return traverse(0, 0, maxreq, choosable, dp);
}

class Solution
{
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        return ans(maxChoosableInteger, desiredTotal);
    }
};