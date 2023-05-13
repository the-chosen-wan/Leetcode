#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int maxa = -inf;
    int dp[n1][n2];
    memset(dp, -1, sizeof(dp));

    auto dfs = [&](int i, int j, auto &&dfs) -> int
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == 0)
            return dp[i][j] = nums1[0] == nums2[j];
        if (j == 0)
            return dp[i][j] = nums1[i] == nums2[0];

        dp[i][j] = 0;
        if (nums1[i] == nums2[j])
            dp[i][j] = 1 + dfs(i - 1, j - 1, dfs);
        maxa = max({dp[i][j], dfs(i - 1, j, dfs), dfs(i, j - 1, dfs), maxa});
        return dp[i][j];
    };
    dfs(n1 - 1, n2 - 1, dfs);
    return maxa;
}

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        return ans(nums1, nums2);
    }
};