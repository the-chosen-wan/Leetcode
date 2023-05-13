#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9;
#define pb push_back
#define mp make_pair
#define N 31

int ans(vector<int> &nums)
{
    vector<int> dp(N, 0);
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < N; j++)
            if ((nums[i] & (1 << j)) != 0)
                dp[j]++;
    }

    int ans = 0;
    for (int j = 0; j < N; j++)
        if (dp[j] != 0)
            ans += (1 << j);
    return ans;
}

class Solution
{
public:
    int maximumXOR(vector<int> &nums)
    {
        return ans(nums);
    }
};