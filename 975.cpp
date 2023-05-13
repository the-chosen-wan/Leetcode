#include <iostream>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair

int ans(vector<int> &nums)
{
    int n = nums.size();
    vector<int> odd(n, -1);
    vector<int> even(n, -1);
    set<pii> s;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.empty())
        {
            s.insert(mp(nums[i], i));
        }
        else
        {
            pii temp = mp(nums[i], -inf);
            auto it = s.lower_bound(temp);
            if (it != s.end())
                odd[i] = it->second;

            it = s.upper_bound(mp(nums[i], inf));
            if (it != s.begin())
            {
                int val = (--it)->first;
                it = s.lower_bound(mp(val, -inf));
                even[i] = it->second;
            }
            s.insert(mp(nums[i], i));
        }
    }

    vector<vector<bool>> dp(n, vector<bool>(2, false));
    dp[n - 1][0] = true;
    dp[n - 1][1] = true;

    for (int i = n - 2; i >= 0; i--)
    {
        if (odd[i] != -1)
            dp[i][1] = dp[odd[i]][0];
        if (even[i] != -1)
            dp[i][0] = dp[even[i]][1];
    }

    int c = 0;
    for (int i = 0; i < n; i++)
        if (dp[i][1])
            c++;
    return c;
}

class Solution
{
public:
    int oddEvenJumps(vector<int> &arr)
    {
        return ans(arr);
    }
};