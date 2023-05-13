#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

bool comp(const pii &a, const pii &b)
{
    double a1 = (double)a.first / (double)a.second;
    double b1 = (double)b.first / (double)b.second;
    return a1 <= b1;
}

double ans(vector<int> &quality, vector<int> &wage, int k)
{
    vector<pii> nums;
    int n = quality.size();
    for (int i = 0; i < n; i++)
        nums.pb(mp(wage[i], quality[i]));
    sort(nums.begin(), nums.end(), comp);
    double ans = inf;
    priority_queue<int> pq;
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (pq.size() < k - 1)
        {
            pq.push(nums[i].second);
            sum += nums[i].second;
            continue;
        }

        if (pq.size() == k - 1)
        {
            sum += nums[i].second;
            pq.push(nums[i].second);
            ans = min<double>(ans, sum * ((double)nums[i].first / (double)nums[i].second));
            continue;
        }

        int top = pq.top();
        ans = min<double>(ans, (sum - top + nums[i].second) * ((double)nums[i].first / (double)nums[i].second));

        if (nums[i].second < top)
        {
            pq.pop();
            pq.push(nums[i].second);
            sum += (nums[i].second - top);
        }
    }
    return ans;
}

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        return ans(quality, wage, k);
    }
};