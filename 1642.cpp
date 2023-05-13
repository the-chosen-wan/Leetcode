#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int brick, int ladder)
{
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    int ret = 0;
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] >= nums[i + 1])
        {
            ret = i + 1;
            continue;
        }
        else
        {
            if (count < ladder)
            {
                ret = i + 1;
                pq.push(nums[i + 1] - nums[i]);
                count++;
                continue;
            }
            else
            {
                int h = nums[i + 1] - nums[i];
                int top;
                if (pq.empty())
                    top = -inf;
                else
                    top = pq.top();
                if (h > top && !pq.empty())
                {
                    pq.pop();
                    pq.push(h);
                    h = top;
                }

                if (brick < h)
                    return ret;
                brick -= h;
                ret = i + 1;
            }
        }
    }
    return ret;
}

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        return ans(heights, bricks, ladders);
    }
};