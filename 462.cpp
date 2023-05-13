#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int abs(int x)
{
    return x > 0 ? x : -x;
}

int ans(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();

    int val = nums[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(nums[i] - val);
    return ans;
}

class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        return ans(nums);
    }
};