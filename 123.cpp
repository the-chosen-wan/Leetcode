#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prefix(n);
    prefix[0] = 0;
    int mini = nums[0];

    for (int i = 1; i < n; i++)
    {
        mini = min(mini, nums[i]);
        prefix[i] = max(prefix[i - 1], nums[i] - mini);
    }

    vector<int> suffix(n);
    suffix[n - 1] = 0;
    int maxi = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        maxi = max(maxi, nums[i]);
        suffix[i] = max(suffix[i + 1], maxi - nums[i]);
    }

    int ans = -inf;
    for (int i = 0; i < n - 1; i++)
    {
        ans = max(ans, prefix[i] + suffix[i + 1]);
    }

    ans = max(ans, suffix[0]);

    return ans;
}

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return ans(prices);
    }
};
