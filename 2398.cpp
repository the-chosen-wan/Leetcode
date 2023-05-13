#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int> &times, vector<int> &costs, ll budget)
{
    int n = times.size();
    vector<pii> nums;
    for (int i = 0; i < n; i++)
        nums.pb(mp(times[i], costs[i]));

    sort(nums.begin(), nums.end());
    auto check = [&](int k) -> bool
    {
        if (k == 0)
            return true;

        priority_queue<int> pq;
        ll sum = 0;
        bool ret = false;
        for (int i = 0; i < n; i++)
        {
            if (budget < nums[i].first)
                break;

            if (i <= k - 2)
            {
                sum += nums[i].second;
                pq.push(nums[i].second);
                continue;
            }
            ll temp = nums[i].first + (k * (sum + nums[i].second));
            if (temp <= budget)
            {
                ret = true;
                break;
            }
            if (k > 1)
            {
                int top = pq.top();
                if (nums[i].second < top)
                {
                    sum += nums[i].second;
                    sum -= top;
                    pq.pop();
                    pq.push(nums[i].second);
                }
            }
        }
        return ret;
    };
    int low = 0;
    int high = n;
    while (high >= low)
    {
        int mid = (high + low) / 2;

        if (mid == low)
        {
            if (check(mid))
                return mid;
            return low;
        }

        if (check(mid))
            low = mid;
        else
            high = mid - 1;
    }
    return -1;
}

class Solution
{
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        return ans(chargeTimes, runningCosts, budget);
    }
};

int main(){
    vector<int> times = { 11, 12, 74, 67, 37, 87, 42, 34, 18, 90, 36, 28, 34, 20 };
    vector<int> costs = {18, 98, 2, 84, 7, 57, 54, 65, 59, 91, 7, 23, 94, 20 };
    ll budget = 937;
    cout<<ans(times,costs,budget);
}