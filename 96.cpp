#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll inf = 1e15;
#define pb push_back
#define mp make_pair

int ans(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            sum += (dp[j] * dp[i - 1 - j]);
        }
        dp[i] = sum;
    }
    return dp[n];
}

class Solution
{
public:
    int numTrees(int n)
    {
        return ans(n);
    }
};