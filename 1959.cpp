#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair
#define M 25

int ans(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> prefsum(n, 0);
    prefsum[0] = nums[0];
    for (int i = 1; i < n; i++)
        prefsum[i] = prefsum[i - 1] + nums[i];

    vector<vector<int>> dp(n, vector<int>(M));

    for (int i = 0; i < n; i++)
        dp[i][0] = nums[i];

    for (int j = 1; j < M; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
            dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
    }

    int lg[n + 1];
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;

    auto query_max = [&](int l, int r) -> int
    {
        int len = lg[r - l + 1];
        return max(dp[l][len], dp[r - (1 << len) + 1][len]);
    };

    auto query_sum = [&](int l, int r) -> int
    {
        if (l > r)
            return 0;
        if (l == 0)
            return prefsum[r];
        return prefsum[r] - prefsum[l - 1];
    };

    vector<vector<int>> ans(n, vector<int>(k + 1, -1));
    // memset(ans, -1, sizeof(ans));

    auto dfs = [&](int i, int j, auto &&dfs) -> int
    {
        if (i < 0)
            return inf;
        if (j == 0)
        {
            ans[i][j] = (i + 1) * query_max(0, i) - query_sum(0, i);
            return ans[i][j];
        }
        if (i == 0)
        {
            ans[i][j] = 0;
            return 0;
        }
        if (ans[i][j] != -1)
            return ans[i][j];

        int ret = inf;
        for (int ind = 0; ind <= i; ind++)
        {
            ret = min(ret, dfs(ind - 1, j - 1, dfs) + ((i - ind + 1) * query_max(ind, i) - query_sum(ind, i)));
        }
        ret = min(ret, dfs(i, j - 1, dfs));
        ans[i][j] = ret;
        return ret;
    };
    return dfs(n - 1, k, dfs);
}

// int main(){
//     vector<int> v = {2, 48, 18, 16, 15, 9, 48, 7, 44, 48};
//     int k  =1;
//     cout<<ans(v,k)<<endl;
//     return 0;
// }

class Solution
{
public:
    int minSpaceWastedKResizing(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};