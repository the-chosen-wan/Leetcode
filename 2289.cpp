#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int steps(vector<int> &nums)
{
    int n = nums.size();
    stack<pii> s;
    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (s.empty())
        {
            s.push(mp(nums[i], i));
            dp[i] = 0;
        }
        else
        {
            pii top = s.top();
            if (nums[i] < top.first)
            {
                s.push(mp(nums[i], i));
                dp[i] = 1;
                continue;
            }
            int maxa = -inf;
            while (top.first <= nums[i])
            {
                maxa = max(maxa, dp[top.second]);
                s.pop();
                if (s.empty())
                    break;
                pii top = s.top();
            }
            if (s.empty())
                dp[i] = 0;
            else
                dp[i] = maxa + 1;
            s.push(mp(nums[i], i));
        }
    }

    int ans = -inf;
    for (int k : dp)
        ans = max(ans, k);
    return ans;
}

class Solution
{
public:
    int totalSteps(vector<int> &nums)
    {
        return steps(nums);
    }
};