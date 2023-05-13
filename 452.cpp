#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const ll inf = 1e15;
#define pb push_back
#define mp make_pair

int ans(vector<vector<int>> &nums)
{
    vector<pii> points;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        points.pb(mp(nums[i][0], nums[i][1]));

    sort(points.begin(), points.end());
    ll low = inf;
    ll high = -inf;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (points[i].first > high)
        {
            count++;
            low = points[i].first;
            high = points[i].second;
            continue;
        }

        low = max<ll>(low, points[i].first);
        high = min<ll>(high, points[i].second);
    }
    return count;
}

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        return ans(points);
    }
};