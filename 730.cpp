#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(string s)
{
    int n = s.size();
    vector<vector<ll>> dp(n, vector<ll>(n, -1));
    vector<vector<int>> ispali(n, vector<int>(n, -1));

    auto check = [&](int i, int j, auto &&check) -> int
    {
        if (i >= j)
        {
            ispali[i][j] = 1;
            return 1;
        }
        if (ispali[i][j] != -1)
            return ispali[i][j];
        if (s[i] != s[j])
            ispali[i][j] = 0;
        else
            ispali[i][j] = check(i + 1, j - 1, check);
        return ispali[i][j];
    };

    check(0, n - 1, check);

    auto ret = [&](int i, int j, auto &&ret) -> ll
    {
        if (i == j)
        {
            dp[i][j] = 1;
            return 1;
        }
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        dp[i][j] = 0;
        if (s[i] == s[j])
            dp[i][j] = (2 * ret(i + 1, j - 1, ret) + ispali[i][j]) % inf;
        else
            dp[i][j] = (ret(i + 1, j, ret) + ret(i, j - 1, ret) - ret(i + 1, j - 1, ret)) % inf;
        return dp[i][j];
    };

    return (1 + ret(0, n - 1, ret)) % inf;
}

class Solution
{
public:
    int countPalindromicSubsequences(string s)
    {
        return ans(s);
    }
};