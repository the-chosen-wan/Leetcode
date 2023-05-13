#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
const int p = 31;
#define pb push_back
#define mp make_pair

bool ans(vector<int> &nums)
{
    int n = nums.size();
    int s = 0;
    for (int i = 0; i < n; i++)
        s += nums[i];

    bool dp[n][n + 1][s + 1];
    memset(dp, false, sizeof(dp));

    for (int i = 0; i < n; i++)
        dp[i][0][0] = true;

    dp[0][1][nums[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= s; k++)
            {
                // if(k>(s*j)/n)
                //     break;
                if (nums[i] > k)
                    dp[i][j][k] = dp[i - 1][j][k];
                else
                    dp[i][j][k] = dp[i - 1][j][k] | dp[i - 1][j - 1][k - nums[i]];
            }
        }
    }
    bool ans = false;
    for (int i = 1; i < n; i++)
        if ((s * i) % n == 0)
            ans |= dp[n - 1][i][(s * i) / n];
    return ans;
}
class Solution
{
public:
    bool splitArraySameAverage(vector<int> &nums)
    {
        return ans(nums);
    }
};