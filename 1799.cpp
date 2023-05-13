#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    int n = nums.size();
    int iter = (n / 2) + 1;
    vector<vector<int>> dp((1 << n), vector<int>(iter, -1));

    auto dfs = [&](int mask, int it, auto &&dfs) -> int
    {
        if (mask == 0)
            return 0;

        if (dp[mask][it] != -1)
            return dp[mask][it];

        int ret = -inf;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int val1 = mask & (1 << i);
                int val2 = mask & (1 << j);
                if ((val1 != 0) && (val2 != 0))
                    ret = max(ret, it * __gcd(nums[i], nums[j]) + dfs(mask - (1 << i) - (1 << j), it + 1, dfs));
            }
        }
        dp[mask][it] = ret;
        return ret;
    };

    return dfs((1 << n) - 1, 1, dfs);
}

class Solution
{
public:
    int maxScore(vector<int> &nums)
    {
        return ans(nums);
    }
};
