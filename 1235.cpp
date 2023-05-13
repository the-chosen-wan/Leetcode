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

int ans(vector<int> &start, vector<int> &end, vector<int> &profit)
{
    vector<triple> nums;
    int n = start.size();

    for (int i = 0; i < n; i++)
        nums.pb(triple(start[i], end[i], profit[i]));

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

    return vals[0];
}

class Solution
{
public:
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        return ans(startTime, endTime, profit);
    }
};