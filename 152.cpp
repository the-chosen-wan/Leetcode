#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    int n = nums.size();
    int ans = nums[0];
    int pos = nums[0] > 0 ? nums[0] : 1;
    int neg = nums[0] <= 0 ? nums[0] : 1;

    for (int i = 1; i < n; i++)
    {
        if (nums[i] > 0)
        {
            neg = neg * nums[i];
            pos = max(pos * nums[i], nums[i]);
        }
        else
        {
            int temp = neg * nums[i];
            neg = min(pos * nums[i], nums[i]);
            pos = temp;
        }
        ans = max({ans, pos});
    }
    return ans;
}

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        return ans(nums);
    }
};