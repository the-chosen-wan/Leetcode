#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<int> dp(1 << n, -1);

    auto dfs = [&](int mask, auto &&dfs) -> int
    {
        if (mask == 0)
            return 0;
        int pos = __builtin_popcount(mask) - 1;
        if (dp[mask] != -1)
            return dp[mask];

        int ret = inf;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
                ret = min(ret, (nums1[i] ^ nums2[pos]) + dfs(mask ^ (1 << i), dfs));
        }
        dp[mask] = ret;
        return ret;
    };
    return dfs((1 << n) - 1, dfs);
}

class Solution
{
public:
    int minimumXORSum(vector<int> &nums1, vector<int> &nums2)
    {
        return ans(nums1, nums2);
    }
};