#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define mp make_pair
#define N 32

int ans(vector<int> &nums)
{
    int n = nums.size();
    vector<int> pos(N, -1);

    int maxa = 1;
    int dp = 1;
    for (int i = 0; i < N; i++)
    {
        if ((nums[0] & (1 << i)) != 0)
            pos[i] = 0;
    }

    for (int i = 1; i < n; i++)
    {
        int localdp = inf;
        for (int j = 0; j < N; j++)
        {
            if ((nums[i] & (1 << j)) != 0)
            {
                localdp = min(localdp, i - pos[j]);
                pos[j] = i;
            }
        }
        dp = min(localdp, dp + 1);
        maxa = max(dp, maxa);
    }

    return maxa;
}

class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        return ans(nums);
    }
};