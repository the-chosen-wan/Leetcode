#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums, int k)
{
    int n = nums.size();
    int ret = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n - k + 1; i++)
    {
        while (!pq.empty() && pq.top() <= i - k)
            pq.pop();

        int s = pq.size();
        if ((s & 1) && (nums[i] == 1))
        {
            pq.push(i);
            ret++;
        }
        else if (((s & 1) == 0) && (nums[i] == 0))
        {
            pq.push(i);
            ret++;
        }
    }

    for (int i = n - k + 1; i < n; i++)
    {
        while (!pq.empty() && pq.top() <= i - k)
            pq.pop();

        int s = pq.size();
        if ((s & 1) && (nums[i] == 1))
            return -1;
        if (((s & 1) == 0) && (nums[i] == 0))
            return -1;
    }

    return ret;
}

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        return ans(nums, k);
    }
};