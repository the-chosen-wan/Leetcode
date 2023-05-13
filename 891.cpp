#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = ((1e9) + 7);
#define pb push_back
#define mp make_pair

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % inf;
        a = (a * a) % inf;
        b >>= 1;
    }
    return res;
}

int ans(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<ll> prefsum(n, 0);
    prefsum[0] = nums[0];
    ll ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans = (ans + (binpow(2, i) - 1) * nums[i] - prefsum[i - 1]) % inf;
        prefsum[i] = (2 * prefsum[i - 1] + nums[i]) % inf;
    }
    return ans;
}

class Solution
{
public:
    int sumSubseqWidths(vector<int> &nums)
    {
        return ans(nums);
    }
};