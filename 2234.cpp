#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e6;
#define pb push_back
#define mp make_pair

bool check(vector<ll> &prefsum, vector<int> &nums, ll total, ll value, int pos)
{
    if (pos == 0)
        return false;
    int ind = upper_bound(nums.begin(), nums.begin() + pos, value) - nums.begin() - 1;
    if (ind < 0)
        return true;
    ll chq = (ind + 1) * value - prefsum[ind];
    return chq <= total;
}

ll maxa(vector<ll> &prefsum, vector<int> &nums, ll total, int pos, int target)
{
    int high = target - 1;
    int low = 0;

    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (mid == low)
        {
            if (check(prefsum, nums, total, high, pos))
                return high;
            return low;
        }
        if (check(prefsum, nums, total, mid, pos))
            low = mid;
        else
            high = mid - 1;
    }
    return -1;
}

ll ans(vector<int> &flowers, ll newflowers, ll target, ll full, ll partial)
{
    ll stat = 0;
    vector<int> valid;
    int n = flowers.size();

    for (int i = 0; i < n; i++)
    {
        if (flowers[i] >= target)
            stat += full;
        else
            valid.pb(flowers[i]);
    }
    if (valid.size() == 0)
        return stat;
    sort(valid.begin(), valid.end());
    n = valid.size();
    vector<ll> prefsum(n);
    prefsum[0] = valid[0];
    for (int i = 1; i < n; i++)
        prefsum[i] = prefsum[i - 1] + valid[i];

    ll ret = maxa(prefsum, valid, newflowers, n, target) * partial;

    for (int i = n - 1; i >= 0; i--)
    {
        ll temp = ret;
        if (newflowers + valid[i] < target)
            break;
        newflowers -= (target - valid[i]);
        ret = maxa(prefsum, valid, newflowers, i, target) * partial + (n - i) * full;
        ret = max<ll>(ret, temp);
    }
    return ret + stat;
}

class Solution
{
public:
    long long maximumBeauty(vector<int> &flowers, long long newFlowers, int target, int full, int partial)
    {
        return ans(flowers, newFlowers, target, full, partial);
    }
};