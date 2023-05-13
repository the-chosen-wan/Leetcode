#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 2e9;
#define pb push_back
#define mp make_pair

bool check(vector<int> &nums, int val, int m)
{
    int c = 0;
    int sum = 0;
    int i = 0;
    int n = nums.size();
    while (i < n)
    {
        while (i < n && sum + nums[i] <= val)
        {
            sum += nums[i];
            i++;
        }
        if (i < n && nums[i] > val)
            return false;
        c++;
        sum = 0;
        if (c > m)
            return false;
    }
    return true;
}

int ans(vector<int> &nums, int m)
{
    int n = nums.size();
    int s = accumulate(nums.begin(), nums.end(), 0);

    int high = s;
    int low = 0;
    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (mid == low)
        {
            if (check(nums, mid, m))
                return mid;
            return high;
        }

        if (check(nums, mid, m))
            high = mid;
        else
            low = mid + 1;
    }
    return -1;
}

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        return ans(nums, m);
    }
};