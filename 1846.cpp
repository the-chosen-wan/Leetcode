#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    nums[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        else
            nums[i] = nums[i - 1] + 1;
    }
    return nums[n - 1];
}

class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        return ans(arr);
    }
};