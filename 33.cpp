#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (ll)((1e9) + 7)
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int target)
{
    int n = nums.size();
    if (n == 1)
    {
        if (nums[0] == target)
            return 0;
        return -1;
    }
    int start = 1;
    while (start < n && nums[start] > nums[start - 1])
        start++;

    auto it1 = lower_bound(nums.begin(), nums.begin() + start, target);
    if (start == n)
        start--;
    auto it2 = lower_bound(nums.begin() + start, nums.end(), target);

    if (it1 != nums.end() && *it1 == target)
        return it1 - nums.begin();
    if (it2 != nums.end() && *it2 == target)
        return it2 - nums.begin();
    return -1;
}

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return ans(nums, target);
    }
};