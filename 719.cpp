#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ret(vector<int> &nums, int k)
{
    int n = nums.size();
    int ret = 0;
    int low = 0;
    for (int i = 0; i < n; i++)
    {
        while (nums[i] - nums[low] > k)
            low++;
        ret += (i - low);
    }
    return ret;
}

int ans(vector<int> &nums, int k)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int high = inf;
    int low = 0;

    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (mid == low)
        {
            if (ret(nums, mid) == k)
                return mid;
            return high;
        }

        int val = ret(nums, mid);
        if (val > k)
            high = mid - 1;
        else
            low = mid;
        // cout<<high<<" ";
    }
    return -1;
}

class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};