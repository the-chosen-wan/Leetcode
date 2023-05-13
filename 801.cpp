#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int minswap(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp;
    dp.resize(n, vector<int>(2, inf));

    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 1; i < n; i++)
    {
        int val11 = nums1[i - 1];
        int val12 = nums1[i];
        int val21 = nums2[i - 1];
        int val22 = nums2[i];

        if (val11 < val12 && val21 < val22)
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
        }

        if (val11 < val22 && val21 < val12)
        {
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
        }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}

class Solution
{
public:
    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        return minswap(nums1, nums2);
    }
};