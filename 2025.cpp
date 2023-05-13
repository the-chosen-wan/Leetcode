#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int k)
{
    int n = nums.size();
    map<ll, int> suff;
    map<ll, int> pref;
    ll total = accumulate(nums.begin(), nums.end(), (ll)0);
    ll sum = 0;
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            if (pref.find((total - nums[i] + k) / 2) != pref.end() && (total - nums[i] + k) % 2 == 0)
                dp[i] += pref[(total - nums[i] + k) / 2];
        }
        sum += nums[i];
        pref[sum]++;
    }

    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (i != n - 1)
        {
            if (suff.find((total - nums[i] + k) / 2) != suff.end() && (total - nums[i] + k) % 2 == 0)
                dp[i] += suff[(total - nums[i] + k) / 2];
        }
        sum += nums[i];
        suff[sum]++;
    }
    pref[total]--;
    int val = *max_element(dp.begin(), dp.end());
    if (total % 2 == 0 && pref.find(total / 2) != pref.end())
    {
        return max(val, pref[total / 2]);
    }
    return val;
}

class Solution
{
public:
    int waysToPartition(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};