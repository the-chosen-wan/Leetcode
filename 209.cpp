#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define mp make_pair
#define pb push_back
const int inf = (int)1e9;

int ans(vector<int> &nums, int target)
{
    int n = nums.size();
    int ret = inf;
    int low = 0;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        while (low < i && sum - nums[low] >= target)
        {
            sum -= nums[low];
            low++;
        }

        if (sum >= target)
            ret = min(ret, i - low + 1);
    }

    if (ret == inf)
        return 0;
    return ret;
}

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        return ans(nums, target);
    }
};