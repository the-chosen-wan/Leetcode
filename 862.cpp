#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int k)
{
    set<pii> s;
    int n = nums.size();
    vector<ll> pref(n);
    pref[0] = nums[0];
    s.insert(mp(nums[0], 0));
    s.insert(mp(0, -1));
    int ret = inf;
    if (n == 1)
    {
        if (nums[0] == k)
            return 1;
        return -1;
    }
    for (int i = 1; i < n; i++)
    {
        pref[i] = nums[i] + pref[i - 1];

        if (!s.empty())
        {
            pii val = mp(pref[i] - k, inf);
            auto it = (s.upper_bound(val));
            // cout<<it->first<<endl;
            if (it != s.begin())
            {
                it--;
                ret = min(ret, i - it->second);
            }
        }

        while (!s.empty() && (*s.rbegin()).first >= pref[i])
            s.erase(*s.rbegin());
        s.insert(mp(pref[i], i));
    }
    if (ret == inf)
        return -1;
    return ret;
}

class Solution
{
public:
    int shortestSubarray(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};