#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

ll range(vector<ll> &pref, int l, int r)
{
    if (l == 0)
        return pref[r] * (r + 1);
    return (pref[r] - pref[l - 1]) * (r - l + 1);
}

ll count(vector<int> &nums, ll k)
{
    int n = nums.size();
    vector<ll> pref(n, 0);

    pref[0] = nums[0];
    for (int i = 1; i < n; i++)
        pref[i] = nums[i] + pref[i - 1];

    int left = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (left <= i && range(pref, left, i) >= k)
            left++;
        if (left > i)
        {
            left = i;
            continue;
        }
        ans += (i - left + 1);
    }
    return ans;
}

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        return count(nums, k);
    }
};