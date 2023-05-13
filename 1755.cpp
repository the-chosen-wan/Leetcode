#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int abs(int x)
{
    return x > 0 ? x : -x;
}

void remove(std::vector<int> &v)
{
    std::vector<int>::iterator itr = v.begin();
    std::unordered_set<int> s;

    for (auto curr = v.begin(); curr != v.end(); ++curr)
    {
        if (s.insert(*curr).second)
        {
            *itr++ = *curr;
        }
    }

    v.erase(itr, v.end());
}

int subset(vector<int> &nums, vector<int> &sums, int goal)
{
    int mini = inf;
    int n = nums.size();

    for (int i = 0; i < (1 << n); i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) != 0)
                s += nums[j];
        }
        mini = min(mini, abs(s - goal));
        sums.pb(s);
    }
    remove(sums);
    sort(sums.begin(), sums.end());
    return mini;
}

int ans(vector<int> &nums, int goal)
{
    int n = nums.size();
    int mini1, mini2;
    vector<int> sums1, sums2;
    vector<int> nums1, nums2;

    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
            nums1.pb(nums[i]);
        else
            nums2.pb(nums[i]);
    }

    mini1 = subset(nums1, sums1, goal);
    mini2 = subset(nums2, sums2, goal);

    int mini3 = inf;
    if (sums1.size() > sums2.size())
        swap(sums1, sums2);
    for (int k : sums1)
    {
        auto it = upper_bound(sums2.begin(), sums2.end(), goal - k);
        if (it != sums2.begin())
        {
            it--;
            mini3 = min(mini3, abs(k + *it - goal));
        }
        it = lower_bound(sums2.begin(), sums2.end(), goal - k);
        if (it != sums2.end())
            mini3 = min(mini3, abs(k + *it - goal));
    }
    // for(int k:sums2)
    //     cout<<k<<endl;
    // cout<<nums2.size();
    return min(min(mini1, mini2), mini3);
}

class Solution
{
public:
    int minAbsDifference(vector<int> &nums, int goal)
    {
        return ans(nums, goal);
    }
};
