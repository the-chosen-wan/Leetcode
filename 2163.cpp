#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N (1e5)

ll mini(vector<int> &nums)
{
    priority_queue<int> pq;
    int n = nums.size() / 3;

    vector<ll> smallsum(3 * n, 0);
    smallsum[0] = nums[0];
    pq.push(nums[0]);

    for (int i = 1; i < n; i++)
    {
        smallsum[i] = smallsum[i - 1] + nums[i];
        pq.push(nums[i]);
    }

    for (int i = n; i < 2 * n; i++)
    {
        int top = pq.top();
        if (nums[i] < top)
        {
            pq.pop();
            pq.push(nums[i]);
            smallsum[i] = smallsum[i - 1] + nums[i] - top;
        }
        else
            smallsum[i] = smallsum[i - 1];
    }

    priority_queue<int, vector<int>, greater<int>> pq1;
    vector<ll> largesum(3 * n, 0);
    largesum[3 * n - 1] = nums[3 * n - 1];
    pq1.push(nums[3 * n - 1]);

    for (int i = 3 * n - 2; i >= 2 * n; i--)
    {
        largesum[i] = largesum[i + 1] + nums[i];
        pq1.push(nums[i]);
    }

    for (int i = 2 * n - 1; i >= n; i--)
    {
        int top = pq1.top();
        if (nums[i] > top)
        {
            pq1.pop();
            pq1.push(nums[i]);
            largesum[i] = largesum[i + 1] + nums[i] - top;
        }
        else
            largesum[i] = largesum[i + 1];
    }

    ll ans = 1e14;

    for (int i = n - 1; i < 2 * n; i++)
        ans = min<ll>(ans, smallsum[i] - largesum[i + 1]);
    return ans;
}

class Solution
{
public:
    long long minimumDifference(vector<int> &nums)
    {
        return mini(nums);
    }
};