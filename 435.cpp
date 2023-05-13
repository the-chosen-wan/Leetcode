#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define inf (int)((1e9) + 7)
#define N 6
#define pb push_back
#define mp make_pair

struct triple
{
    int first;
    int second;
    int third;

    triple(int first, int second, int third)
    {
        this->first = first;
        this->second = second;
        this->third = third;
    }

    bool operator<(const triple &t) const
    {
        if (first != t.first)
            return first < t.first;
        else if (second != t.second)
            return second < t.second;
        else
            return third < t.third;
    }
};

int ans(vector<vector<int>> &intervals)
{
    vector<triple> nums;
    int n = intervals.size();

    for (int i = 0; i < n; i++)
        nums.pb(triple(intervals[i][0], intervals[i][1], 1));

    sort(nums.begin(), nums.end());
    vector<int> vals(n, -inf);

    vals[n - 1] = nums[n - 1].third;

    for (int i = n - 2; i >= 0; i--)
    {
        int start = nums[i].first;
        int end = nums[i].second;
        int profit = nums[i].third;

        int it = lower_bound(nums.begin(), nums.end(), triple(end, -inf, -inf)) - nums.begin();
        if (it != n)
            vals[i] = max(vals[i], profit + vals[it]);
        else
            vals[i] = max(vals[i], profit);
        vals[i] = max(vals[i], vals[i + 1]);
    }

    return n - vals[0];
}

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        return ans(intervals);
    }
};