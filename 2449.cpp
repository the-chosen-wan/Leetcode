#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

ll ans(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    vector<int> odd1;
    vector<int> odd2;

    for (int i = 0; i < n; i++)
    {
        if (nums1[i] & 1)
            odd1.pb(nums1[i]);
        if (nums2[i] & 1)
            odd2.pb(nums2[i]);
    }

    sort(odd1.begin(), odd1.end());
    sort(odd2.begin(), odd2.end());

    ll ans = 0;
    int nd = odd1.size();

    for (int i = 0; i < nd; i++)
    {
        if (odd2[i] >= odd1[i])
            ans += (odd2[i] - odd1[i]);
    }

    odd1.clear();
    odd2.clear();

    for (int i = 0; i < n; i++)
    {
        if ((nums1[i] & 1) == 0)
            odd1.pb(nums1[i]);
        if ((nums2[i] & 1) == 0)
            odd2.pb(nums2[i]);
    }

    sort(odd1.begin(), odd1.end());
    sort(odd2.begin(), odd2.end());

    nd = odd1.size();

    for (int i = 0; i < nd; i++)
    {
        if (odd2[i] >= odd1[i])
            ans += (odd2[i] - odd1[i]);
    }

    return ans / 2;
}

class Solution
{
public:
    long long makeSimilar(vector<int> &nums, vector<int> &target)
    {
        return ans(nums, target);
    }
};