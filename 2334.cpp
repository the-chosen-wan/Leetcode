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
    vector<int> prev(n, 0);
    vector<int> next(n, n - 1);

    stack<pii> sp;
    for (int i = 0; i < n; i++)
    {
        if (sp.empty())
        {
            sp.push(mp(nums[i], i));
        }
        else
        {
            pii top = sp.top();
            if (top.first < nums[i])
            {
                prev[i] = ++top.second;
                sp.push(mp(nums[i], i));
                continue;
            }

            while (top.first >= nums[i])
            {
                sp.pop();
                if (sp.empty())
                    break;
                top = sp.top();
            }

            if (!sp.empty())
                prev[i] = sp.top().second + 1;
            else
                prev[i] = 0;
            sp.push(mp(nums[i], i));
        }
    }
    while (!sp.empty())
        sp.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        if (sp.empty())
        {
            sp.push(mp(nums[i], i));
        }
        else
        {
            pii top = sp.top();
            if (top.first < nums[i])
            {
                next[i] = --top.second;
                sp.push(mp(nums[i], i));
                continue;
            }

            while (top.first >= nums[i])
            {
                sp.pop();
                if (sp.empty())
                    break;
                top = sp.top();
            }

            if (!sp.empty())
                next[i] = --sp.top().second;
            else
                next[i] = n - 1;
            sp.push(mp(nums[i], i));
        }
    }

    for (int i = 0; i < n; i++)
    {
        int len = (k / nums[i]) + 1;
        int x = prev[i];
        int y = next[i];
        if (y - x + 1 >= len)
            return (y - x + 1);
    }
    return -1;
}

class Solution
{
public:
    int validSubarraySize(vector<int> &nums, int threshold)
    {
        return ans(nums, threshold);
    }
};