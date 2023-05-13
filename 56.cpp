#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

vector<vector<int>> ans(vector<vector<int>> &intervals)
{
    vector<pii> nums;
    int n = intervals.size();
    for (int i = 0; i < n; i++)
        nums.pb(mp(intervals[i][0], intervals[i][1]));
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;
    int low = nums[0].first;
    int high = nums[0].second;

    for (int i = 1; i < n; i++)
    {
        if (nums[i].first <= high)
        {
            high = max(nums[i].second, high);
        }
        else
        {
            ans.pb({low, high});
            low = nums[i].first;
            high = nums[i].second;
        }
    }
    ans.pb({low, high});
    return ans;
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        return ans(intervals);
    }
};