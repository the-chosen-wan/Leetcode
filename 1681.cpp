#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using namespace std;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int k)
{
    int n = nums.size();
    int bsize = n / k;
    int dp[(1 << n)][k][bsize + 1];
    memset(dp, -1, sizeof(dp));
    vector<set<int>> contains(k);
    bool check = false;

    auto dfs = [&](int mask, int box, int size, auto &&dfs) -> int
    {
        if (mask == 0)
        {
            check = true;
            return 0;
        }
        if (box > k - 1)
        {
            return inf;
        }
        if (dp[mask][box][size] != -1)
            return dp[mask][box][size];
        if (size == bsize)
        {
            int ret = inf;
            int small = *contains[box].begin();
            int large = *contains[box].rbegin();
            ret = large - small + dfs(mask, box + 1, 0, dfs);
            dp[mask][box][size] = ret;
            return ret;
        }

        int ret = inf;
        for (int i = 0; i < n; i++)
        {
            if (((mask & (1 << i)) != 0) && (contains[box].find(nums[i]) == contains[box].end()))
            {
                contains[box].insert(nums[i]);
                ret = min(ret, dfs(mask ^ (1 << i), box, size + 1, dfs));
                contains[box].erase(nums[i]);
            }
        }
        dp[mask][box][size] = ret;
        return ret;
    };
    int val = dfs((1 << n) - 1, 0, 0, dfs);
    if (!check)
        return -1;
    return val;
}

class Solution
{
public:
    int minimumIncompatibility(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};